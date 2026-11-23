# Version-pinned tools; base digest and apt snapshot still require release sealing.
FROM ubuntu:24.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
      ca-certificates curl unzip gcc g++ make python3 python3-venv git bash-completion \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /vwe
COPY requirements.txt /vwe/requirements.txt
COPY tools/install_tools.sh /vwe/tools/install_tools.sh
RUN VWE_SKIP_PYTHON_INSTALL=1 bash tools/install_tools.sh \
    && python3 -m venv /opt/vwe-venv
ENV PATH=/opt/vwe-venv/bin:/opt/cbmc/usr/bin:/opt/esbmc/release/bin:$PATH
COPY . .
RUN python -m pip install -e .
CMD ["make", "test"]
