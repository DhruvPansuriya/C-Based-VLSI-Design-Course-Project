PYTHON ?= $(if $(wildcard .venv/bin/python),.venv/bin/python,python3)
export PATH := $(CURDIR)/.venv/bin:$(PATH)

.PHONY: install test golden admission contracts spikes demo demo-steps portal eval clean
install:
	$(PYTHON) -m pip install -e .
test:
	$(PYTHON) -m pytest -q tests
golden:
	$(PYTHON) scripts/run_golden_examples.py --out runs/golden
admission:
	$(PYTHON) scripts/run_admission_examples.py
contracts:
	$(PYTHON) scripts/check_contracts.py
spikes:
	bash spikes/tool_behaviour/run_spikes.sh
demo:
	$(PYTHON) scripts/demo.py --out runs/demo
demo-steps:
	$(PYTHON) scripts/demo_steps.py --interactive
portal:
	$(PYTHON) scripts/demo_portal.py
eval:
	$(PYTHON) scripts/run_eval.py
clean:
	$(PYTHON) -c 'import shutil; shutil.rmtree("runs", ignore_errors=True)'
