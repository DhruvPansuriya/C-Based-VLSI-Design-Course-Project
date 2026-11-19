PYTHON ?= $(if $(wildcard .venv/bin/python),.venv/bin/python,python3)
export PATH := $(CURDIR)/.venv/bin:$(PATH)

.PHONY: install test golden admission spikes demo eval clean
install:
	$(PYTHON) -m pip install -e .
test:
	$(PYTHON) -m pytest -q tests
golden:
	$(PYTHON) scripts/run_golden_examples.py --out runs/golden
admission:
	$(PYTHON) scripts/run_admission_examples.py
spikes:
	bash spikes/tool_behaviour/run_spikes.sh
demo:
	@echo "T11 demo is not implemented yet; use make golden for the existing prototype."
	@exit 2
eval:
	@echo "T18 evaluation is not implemented yet."
	@exit 2
clean:
	$(PYTHON) -c 'import shutil; shutil.rmtree("runs", ignore_errors=True)'
