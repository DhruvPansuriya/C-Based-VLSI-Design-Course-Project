#!/usr/bin/env bash
# Pinned Linux/amd64 tools; Python packages are installed into the caller's venv.
set -euo pipefail
if [[ "$(uname -s)" != Linux || "$(uname -m)" != x86_64 ]]; then
  echo 'This installer targets Linux x86_64 (Ubuntu 24.04). On macOS, use a qualified native CBMC build.' >&2
  exit 2
fi
PREFIX="${PREFIX:-/opt}"
VWE_DOWNLOAD_CACHE="${VWE_DOWNLOAD_CACHE:-${XDG_CACHE_HOME:-$HOME/.cache}/vwe/downloads}"
CBMC_VER=6.11.0
ESBMC_VER=8.7
CBMC_SHA256=b3721aa541038384d7801ea3aeabbcddc3e8845ac8f1cbff637cf8dec7481ac8
ESBMC_SHA256=deb5230f10755722eac78938c167cfa5631d81c7ef10e23f3350fced7c0ee6da
mkdir -p "$PREFIX/cbmc" "$PREFIX/esbmc" "$VWE_DOWNLOAD_CACHE"
fetch() {
  local url="$1" file="$2" digest="$3"
  if [[ ! -f "$file" ]]; then
    curl --fail --location --retry 3 "$url" --output "$file.part"
    mv "$file.part" "$file"
  fi
  printf '%s  %s\n' "$digest" "$file" | sha256sum --check --status
}
fetch "https://github.com/diffblue/cbmc/releases/download/cbmc-${CBMC_VER}/ubuntu-24.04-cbmc-${CBMC_VER}-Linux.deb" \
  "$VWE_DOWNLOAD_CACHE/cbmc-${CBMC_VER}.deb" "$CBMC_SHA256"
fetch "https://github.com/esbmc/esbmc/releases/download/v${ESBMC_VER}/esbmc-linux.zip" \
  "$VWE_DOWNLOAD_CACHE/esbmc-${ESBMC_VER}.zip" "$ESBMC_SHA256"
dpkg -x "$VWE_DOWNLOAD_CACHE/cbmc-${CBMC_VER}.deb" "$PREFIX/cbmc"
unzip -q -o "$VWE_DOWNLOAD_CACHE/esbmc-${ESBMC_VER}.zip" -d "$PREFIX/esbmc"
chmod +x "$PREFIX/esbmc/release/bin/esbmc"
if [[ "${VWE_SKIP_PYTHON_INSTALL:-0}" != 1 ]]; then
  python3 -m pip install -r "$(dirname "$0")/../requirements.txt"
  z3 --version
fi
"$PREFIX/cbmc/usr/bin/cbmc" --version
"$PREFIX/esbmc/release/bin/esbmc" --version
printf 'Add to PATH: %s/cbmc/usr/bin:%s/esbmc/release/bin\n' "$PREFIX" "$PREFIX"
