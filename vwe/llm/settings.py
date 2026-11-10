"""Load config/llm.toml: client policy and per-family provider settings."""
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from types import MappingProxyType
from typing import Mapping

from ..config import ConfigError, data_path, tomllib
from .client import LLMClient
from .providers import make_provider


@dataclass(frozen=True)
class FamilySettings:
    name: str
    adapter: str
    model_id: str
    api_key_env: str = ""


@dataclass(frozen=True)
class LLMSettings:
    cache_dir: str
    max_retries: int
    temperature: float
    timeout_s: int
    families: Mapping[str, FamilySettings]


def load_llm_settings(path: str | Path | None = None) -> LLMSettings:
    chosen = Path(path) if path else data_path("config/llm.toml")
    try:
        with chosen.open("rb") as stream:
            raw = tomllib.load(stream)
    except (OSError, tomllib.TOMLDecodeError) as exc:
        raise ConfigError(f"Cannot load LLM config {chosen}: {exc}") from exc
    if raw.keys() - {"client", "families"}:
        raise ConfigError(f"Unknown llm config sections: {sorted(raw.keys() - {'client', 'families'})}")
    client = raw.get("client", {})
    extra = client.keys() - {"cache_dir", "max_retries", "temperature", "timeout_s"}
    if extra:
        raise ConfigError(f"Unknown llm client keys: {sorted(extra)}")
    retries, timeout = client.get("max_retries", 2), client.get("timeout_s", 120)
    temperature = client.get("temperature", 0.0)
    if type(retries) is not int or not 0 <= retries <= 2:
        raise ConfigError("client.max_retries must be 0..2")
    if type(timeout) is not int or timeout <= 0:
        raise ConfigError("client.timeout_s must be a positive integer")
    if isinstance(temperature, bool) or not isinstance(temperature, (int, float)) or not 0 <= temperature <= 2:
        raise ConfigError("client.temperature must be in 0..2")
    families: dict[str, FamilySettings] = {}
    for name, table in raw.get("families", {}).items():
        if not isinstance(table, dict) or table.keys() - {"adapter", "model_id", "api_key_env"}:
            raise ConfigError(f"families.{name} has unknown keys")
        if table.get("adapter") not in {"mock", "anthropic", "openai"}:
            raise ConfigError(f"families.{name}.adapter must be mock, anthropic or openai")
        families[name] = FamilySettings(name, table["adapter"], str(table.get("model_id", "")),
                                        str(table.get("api_key_env", "")))
    return LLMSettings(str(client.get("cache_dir", "~/.cache/vwe/llm")), retries,
                       float(temperature), timeout, MappingProxyType(families))


def build_client(settings: LLMSettings, family: str, *, offline: bool = False,
                 seed: int | None = None, cache_dir: Path | None = None,
                 log_path: Path | None = None, fixture_dir: Path | None = None) -> LLMClient:
    """Create a client for a configured family; unavailable families fail at call time."""
    if family not in settings.families:
        raise ConfigError(f"Unknown LLM family {family!r}")
    fam = settings.families[family]
    provider = make_provider(fam.adapter, fam.name, fam.model_id, fam.api_key_env,
                             timeout_s=settings.timeout_s, fixture_dir=fixture_dir)
    return LLMClient(provider, fam.model_id, cache_dir=cache_dir or Path(settings.cache_dir),
                     offline=offline, max_retries=settings.max_retries,
                     temperature=settings.temperature, seed=seed, log_path=log_path)
