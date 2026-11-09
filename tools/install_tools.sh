#!/usr/bin/env bash
# Installs the pinned verification tools on Ubuntu 24.04 (x86_64) without Docker.
# Versions verified on 22 Nov 2026: CBMC 6.11.0, ESBMC 8.7.0, Z3 5.4.1 (PyPI).
set -euo pipefail
PREFIX="${PREFIX:-/opt}"
CBMC_VER=6.11.0
ESBMC_VER=8.7

tmp=$(mktemp -d)
curl -fsSL -o "$tmp/cbmc.deb" "https://github.com/diffblue/cbmc/releases/download/cbmc-${CBMC_VER}/ubuntu-24.04-cbmc-${CBMC_VER}-Linux.deb"
# The .deb declares a dependency on bash-completion only beyond libc/libstdc++/gcc; extracting avoids apt.
mkdir -p "$PREFIX/cbmc" && dpkg -x "$tmp/cbmc.deb" "$PREFIX/cbmc"

curl -fsSL -o "$tmp/esbmc.zip" "https://github.com/esbmc/esbmc/releases/download/v${ESBMC_VER}/esbmc-linux.zip"
mkdir -p "$PREFIX/esbmc" && unzip -q -o "$tmp/esbmc.zip" -d "$PREFIX/esbmc"
chmod +x "$PREFIX/esbmc/release/bin/esbmc"

python3 -m pip install -r "$(dirname "$0")/../requirements.txt"

echo "Add to PATH: export PATH=$PREFIX/cbmc/usr/bin:$PREFIX/esbmc/release/bin:\$PATH"
"$PREFIX/cbmc/usr/bin/cbmc" --version
"$PREFIX/esbmc/release/bin/esbmc" --version | head -1
z3 --version
