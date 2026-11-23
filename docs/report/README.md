# Reports and slides (VWE, Approach-2)

| File | What it is |
|---|---|
| `VWE_report.pdf` (`VWE_report.tex`) | the full VWE report, 12 pages |
| `VWE_slides.pptx` (`vwe_slides.js`) | 10 slides on the pipeline, method and results |
| `slides_common.js` | theme and drawing helpers shared with the HLSCheck slides |

The HLSCheck (Approach-1) report and slides are in `approach-1-hlscheck/report/` at the top of the
repository.

Build:

```sh
tectonic VWE_report.tex
npm install pptxgenjs@3.12.0      # once, in any folder; point NODE_PATH at its node_modules
NODE_PATH=<that folder>/node_modules node vwe_slides.js <path to apply_theme.js>
```

`apply_theme.js` writes the colours and fonts into the deck after it is generated. VWE numbers come
from `evaluation/results/`. Bar charts are drawn as shapes so they look the same in PowerPoint,
Keynote and Google Slides.
