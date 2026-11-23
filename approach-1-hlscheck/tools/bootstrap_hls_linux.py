"""Prepare the pinned HLS binaries in the Linux home directory, without FUSE."""
import argparse
import hashlib
from pathlib import Path
import shutil
import subprocess
import tarfile
import urllib.request

ROOT=Path(__file__).resolve().parents[1]
RESOURCES=[
    ('bambu-2026.11.AppImage','https://release.bambuhls.eu/bambu-2026.11.AppImage',533607616,'6e8cd7049c09ef48ec7ea2ece88e91f2c70bf67547c77a71b6ff44c4e008fa06'),
    ('openroad-yosys-opt.tar','https://release.bambuhls.eu/openroad-yosys-opt.tar',77746307,'fb49a19ea1c062cae18eba291672fbbd723e36f57799c083de3b187a55c5c09f')]


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--download',action='store_true',help='Download missing archives after printing their known sizes')
    args=parser.parse_args()
    tools=Path.home()/'cs5291_hls_tools'
    tools.mkdir(exist_ok=True)
    for name,url,size,digest in RESOURCES:
        source=ROOT/'tools'/name
        print(f'{name}: {size/2**20:.2f} MiB download; {url}',flush=True)
        if not source.exists():
            if not args.download:
                raise SystemExit('Missing archive; rerun with --download to obtain the listed resources')
            urllib.request.urlretrieve(url,source)
        if source.stat().st_size!=size or hashlib.file_digest(source.open('rb'),'sha256').hexdigest()!=digest:
            raise SystemExit('Archive differs from the recorded experiment: '+name)
        if name.endswith('.AppImage') and not (tools/'squashfs-root/usr/bin/bambu').exists():
            binary=tools/name
            shutil.copyfile(source,binary)
            binary.chmod(0o755)
            subprocess.run([str(binary),'--appimage-extract'],cwd=tools,check=True,stdout=subprocess.DEVNULL)
        if name.endswith('.tar') and not (tools/'opt/yosys/bin/yosys').exists():
            with tarfile.open(source) as archive:
                archive.extractall(tools,filter='data')
    print('Installed at',tools,flush=True)
    print('Linux dependencies: libtcl8.6, verilator, gcc, g++, make. See docs/REPRODUCE.md.')


if __name__=='__main__':
    main()
