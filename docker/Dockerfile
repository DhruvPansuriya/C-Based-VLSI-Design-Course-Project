# Reproducible environment for Verdicts with Evidence (verification side; Vitis HLS not included).
FROM ubuntu:24.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
      ca-certificates curl unzip gcc g++ make python3 python3-pip git bash-completion \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /vwe
COPY requirements.txt tools/install_tools.sh ./tools/
RUN cp tools/requirements.txt ./requirements.txt && \
    PIP_BREAK_SYSTEM_PACKAGES=1 bash tools/install_tools.sh
ENV PATH=/opt/cbmc/usr/bin:/opt/esbmc/release/bin:$PATH
COPY . .
CMD ["python3", "-m", "pytest", "-q", "tests"]
