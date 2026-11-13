# HLSCheck report and slides

| File | What it is |
|---|---|
| `HLSCheck_report.pdf` (`HLSCheck_report.tex`) | the full HLSCheck report, 7 pages |
| `HLSCheck_slides.pptx` (`hlscheck_slides.js`) | 10 slides on the pipeline, method and results |

The numbers in both come from [../RESULTS.md](../RESULTS.md) and the files in [../results/](../results/).

Build:

```sh
tectonic HLSCheck_report.tex
NODE_PATH=<folder with pptxgenjs 3.12.0>/node_modules node hlscheck_slides.js <path to apply_theme.js>
```

The slide script reuses the drawing helpers in `approach-2-vwe/docs/report/slides_common.js`.
