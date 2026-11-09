"""Validated immutable configuration, including a Python 3.10 TOML fallback."""
from __future__ import annotations

from dataclasses import dataclass, field, fields
from pathlib import Path
from types import MappingProxyType
from typing import Any, Mapping
import sysconfig

try:
    import tomllib
except ModuleNotFoundError:  # Python 3.10
    import tomli as tomllib


class ConfigError(ValueError):
    """A configuration cannot be used without guessing its meaning."""


@dataclass(frozen=True)
class Bounds:
    K: int = 4
    max_unwind: int = 9


@dataclass(frozen=True)
class Timeouts:
    cbmc_s: int = 600
    esbmc_s: int = 600
    equiv_pair_s: int = 120


@dataclass(frozen=True)
class Backends:
    primary: tuple[str, ...] = ("sat", "z3")
    confirm: str = "esbmc"


@dataclass(frozen=True)
class Native:
    cc: str = "gcc"
    sanitize: str = "address,undefined"


@dataclass(frozen=True)
class Config:
    bounds: Bounds = field(default_factory=Bounds)
    timeouts: Timeouts = field(default_factory=Timeouts)
    backends: Backends = field(default_factory=Backends)
    native: Native = field(default_factory=Native)
    llm: Mapping[str, Any] = field(default_factory=lambda: MappingProxyType({}))


def data_path(relative: str) -> Path:
    """Resolve source-tree data first, then wheel-installed shared data."""
    source = Path(__file__).resolve().parent.parent / relative
    if source.is_file() or source.is_dir():
        return source
    return Path(sysconfig.get_path("data")) / "share" / "vwe" / relative


def _freeze(value: Any) -> Any:
    if isinstance(value, dict):
        return MappingProxyType({k: _freeze(v) for k, v in value.items()})
    if isinstance(value, list):
        return tuple(_freeze(v) for v in value)
    return value


def _record(cls: type, value: Any, section: str) -> Any:
    if not isinstance(value, dict):
        raise ConfigError(f"{section} must be a TOML table")
    extra = value.keys() - {f.name for f in fields(cls)}
    if extra:
        raise ConfigError(f"Unknown {section} keys: {sorted(extra)}")
    return cls(**value)


def load_config(path: str | Path | None = None) -> Config:
    """Load defaults or an explicit TOML file; missing sections use defaults."""
    chosen = Path(path) if path is not None else data_path("config/default.toml")
    try:
        with chosen.open("rb") as stream:
            raw = tomllib.load(stream)
    except (OSError, tomllib.TOMLDecodeError) as exc:
        raise ConfigError(f"Cannot load config {chosen}: {exc}") from exc
    extra = raw.keys() - {f.name for f in fields(Config)}
    if extra:
        raise ConfigError(f"Unknown config sections: {sorted(extra)}")
    bounds = _record(Bounds, raw.get("bounds", {}), "bounds")
    timeouts = _record(Timeouts, raw.get("timeouts", {}), "timeouts")
    for section, record in (("bounds", bounds), ("timeouts", timeouts)):
        for f in fields(record):
            value = getattr(record, f.name)
            if type(value) is not int or value <= 0:
                raise ConfigError(f"{section}.{f.name} must be a positive integer")
    if bounds.max_unwind <= bounds.K:
        raise ConfigError("bounds.max_unwind must exceed K")
    backend_raw = raw.get("backends", {})
    backends = _record(Backends, backend_raw, "backends")
    primary = backends.primary
    if not isinstance(primary, (list, tuple)) or not primary:
        raise ConfigError("backends.primary must be a nonempty list")
    if any(type(b) is not str or b not in {"sat", "z3"} for b in primary):
        raise ConfigError("Only qualified primary choices sat and z3 are configurable")
    if len(set(primary)) != len(primary) or backends.confirm != "esbmc":
        raise ConfigError("Duplicate primary backend or unsupported confirmation backend")
    native = _record(Native, raw.get("native", {}), "native")
    if not isinstance(native.cc, str) or not native.cc.strip():
        raise ConfigError("native.cc must name an executable")
    if native.sanitize != "address,undefined":
        raise ConfigError("The supported native profile requires address,undefined")
    llm = raw.get("llm", {})
    if not isinstance(llm, dict):
        raise ConfigError("llm must be a TOML table")
    return Config(bounds, timeouts, Backends(tuple(primary), backends.confirm), native, _freeze(llm))
