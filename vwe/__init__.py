"""Verdicts with Evidence (vwe): prototype components.

This package currently contains the pieces that are implemented and tested:
  - vwe.tools.cbmc   : run CBMC with the project's pinned flag set and parse --json-ui output
  - vwe.verdict      : the verdict rules of the research draft (Section 5.2) as a pure function
  - vwe.schemas      : JSON Schema validation for interpretations, tasks and reports
All other stages are specified in docs/technical-design/02_technical_design_document.md.
"""
__version__ = "0.1.0"
