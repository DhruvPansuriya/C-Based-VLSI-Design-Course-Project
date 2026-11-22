PYTHON ?= $(if $(wildcard .venv/bin/python),.venv/bin/python,python3)
export PATH := $(CURDIR)/.venv/bin:$(PATH)

.PHONY: install test golden admission contracts spikes demo demo-steps portal demo-reset eval clean
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
demo-reset:
	$(PYTHON) -c 'import shutil, pathlib; [shutil.rmtree(p, ignore_errors=True) for p in ("runs/demo-steps", "runs/demo")]; pathlib.Path("runs/index.html").unlink(missing_ok=True); print("demo outputs cleared: runs/demo-steps, runs/demo, runs/index.html (LLM answer cache included)")'
eval:
	$(PYTHON) scripts/run_eval.py
clean:
	$(PYTHON) -c 'import shutil; shutil.rmtree("runs", ignore_errors=True)'
