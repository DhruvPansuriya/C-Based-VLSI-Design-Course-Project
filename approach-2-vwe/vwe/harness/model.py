"""Durable job specifications; a generated harness is not proof evidence."""
from __future__ import annotations
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class HarnessBundle:
    kind: str
    folder: Path
    files: tuple[Path,...]
    entry_point: str
    unwind: int
    watch: tuple[str,...]
    property_labels: tuple[str,...]
    prerequisites: tuple[str,...]
    profile_sha256: str
    reference_guard: str|None=None
    e1_decisive: bool=False
    program_symbols: tuple[tuple[str,...],tuple[str,...]]=((),())
    witness_names: tuple[tuple[str,str],...]=()

    @property
    def ready_for_decision(self) -> bool:
        # T05/T07 consume the prerequisites and attach actual certificates.
        # Emission itself never silently turns them into proofs.
        return not self.prerequisites
