"""Download the official Bambu release with resumable HTTP byte ranges."""

from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import shutil
import time
import urllib.request
from pathlib import Path

URL = "https://release.bambuhls.eu/bambu-2026.11.AppImage"
SIZE = 533607616
ROOT = Path(__file__).resolve().parent
TARGET = ROOT / "bambu-2026.11.AppImage"
PARTS = ROOT / "bambu-download-parts"


def main():
    if TARGET.exists() and TARGET.stat().st_size == SIZE:
        print("Already downloaded", flush=True)
        return
    PARTS.mkdir(exist_ok=True)
    # Retain the existing prefix from the initial single-connection download.
    prefix = PARTS / "prefix"
    if not prefix.exists() and TARGET.exists():
        shutil.copyfile(TARGET, prefix)
    offset = prefix.stat().st_size if prefix.exists() else 0
    count = 8
    chunk = (SIZE - offset + count - 1) // count
    jobs = [(i, offset + i * chunk, min(SIZE - 1, offset + (i + 1) * chunk - 1)) for i in range(count)]

    def get(job):
        i, start, end = job
        path = PARTS / f"chunk-{i}"
        for attempt in range(4):
            have = path.stat().st_size if path.exists() else 0
            if have == end - start + 1:
                return path
            request = urllib.request.Request(URL, headers={"Range": f"bytes={start+have}-{end}", "User-Agent": "CS5291-course-project"})
            try:
                with urllib.request.urlopen(request, timeout=60) as response:
                    if response.status != 206:
                        raise RuntimeError("Server did not honor the Range request")
                    with path.open("ab") as stream:
                        shutil.copyfileobj(response, stream, length=1024 * 1024)
                if path.stat().st_size != end - start + 1:
                    raise RuntimeError("Incomplete range")
                print(f"Chunk {i+1}/{count} complete", flush=True)
                return path
            except Exception:
                if attempt == 3: raise
                time.sleep(2)

    with ThreadPoolExecutor(max_workers=count) as pool:
        for result in as_completed([pool.submit(get, job) for job in jobs]):
            result.result()
    combined = PARTS / "complete.AppImage"
    with combined.open("wb") as output:
        for part in ([prefix] if prefix.exists() else []) + [PARTS / f"chunk-{i}" for i, _, _ in jobs]:
            with part.open("rb") as stream:
                shutil.copyfileobj(stream, output, length=1024 * 1024)
    assert combined.stat().st_size == SIZE
    combined.replace(TARGET)
    digest = hashlib.file_digest(TARGET.open("rb"), "sha256").hexdigest()
    print("Downloaded", SIZE, "bytes; SHA256", digest, flush=True)


if __name__ == "__main__":
    main()
