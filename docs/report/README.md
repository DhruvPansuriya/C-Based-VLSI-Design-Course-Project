# Reports and slides

| File | What it is |
|---|---|
| `VWE_report.pdf` (`.tex`) | VWE (Approach-2): full report, 12 pages |
| `VWE_slides.pptx` (`vwe_slides.js`) | VWE: 10 slides on the pipeline, method and evaluation |
| `Approach1_report.pdf` (`.tex`) | HLSCheck (Approach-1): full report, 7 pages |
| `HLSCheck_slides.pptx` (`hlscheck_slides.js`) | HLSCheck: 10 slides on the pipeline, method and evaluation |
| `slides_common.js` | shared theme, layouts and diagram helpers for both decks |

Build:

```sh
tectonic VWE_report.tex && tectonic Approach1_report.tex
npm install pptxgenjs@3.12.0          # once, in any folder; point NODE_PATH at its node_modules
NODE_PATH=<that folder>/node_modules node vwe_slides.js <pptx skill>/scripts/apply_theme.js
NODE_PATH=<that folder>/node_modules node hlscheck_slides.js <pptx skill>/scripts/apply_theme.js
```

HLSCheck numbers come from its recorded results (`approach-1-hlscheck/RESULTS.md` at the top of the repository); VWE numbers
from `evaluation/results/` in this repository. Bar charts are drawn as shapes so they look the same in
PowerPoint, Keynote and Google Slides.
