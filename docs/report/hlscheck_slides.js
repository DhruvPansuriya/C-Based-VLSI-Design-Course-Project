// Builds HLSCheck_slides.pptx (Approach-1, 10 slides). Run from anywhere:
//   NODE_PATH=<folder with node_modules> node hlscheck_slides.js <path to pptx skill apply_theme.js>
const path = require("path");
const { THEME, HEX, newDeck, box, arrow, label, stat, bullets, hbars } = require("./slides_common");
const { applyTheme } = require(process.argv[2]);

const OUT = path.join(__dirname, "HLSCheck_slides.pptx");
const { pres, C } = newDeck("HLSCheck (Approach-1)", "HLSCheck (Approach-1)  |  C-Based VLSI Design (CS5291)  |  IIT Guwahati");
const mono = "Courier New";

// 1. Title
pres.addSection({ title: "Introduction" });
let s = pres.addSlide({ masterName: "DARK", sectionTitle: "Introduction" });
s.addText("HLSCheck  (Approach-1)", { placeholder: "title" });
label(s, C, 0.6, 2.5, 8.8, 0.5, "Formal equivalence checking of LLM-optimised HLS code, followed by measured hardware",
  { fontSize: 17, color: HEX.soft, italic: true });
s.addShape("line", { x: 0.6, y: 3.15, w: 2.2, h: 0, line: { color: HEX.gold, width: 2 } });
label(s, C, 0.6, 3.3, 5.2, 1.0,
  "Dhruvkumar R Pansuriya (230101071)\nAryan Kaushik (230101018)\nLasya Madhu Sundar (230101058)",
  { fontSize: 13, color: "FFFFFF" });
label(s, C, 5.9, 3.3, 3.5, 1.0, "Instructor: Dr. Chandan Karfa\nC-Based VLSI Design (CS5291)\nIIT Guwahati",
  { fontSize: 13, color: "FFFFFF" });

// 2. Pipeline
pres.addSection({ title: "Method" });
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("Two questions, seven stages", { placeholder: "title" });
box(s, C, 0.45, 1.05, 4.45, 0.6, "1. Is the rewrite the same function?  (proof)", "ink", { bold: true, fontSize: 13 });
box(s, C, 5.1, 1.05, 4.45, 0.6, "2. Is its hardware better?  (measurement)", "acc", { bold: true, fontSize: 13 });
const st = [
  ["Input checks", "types, arrays, ranges"], ["Formal C-to-C", "equivalence proof"], ["Evidence replay", "hashes, SMT queries"],
  ["Compiled C", "264 typed inputs"], ["Bambu + Verilator", "HLS and RTL sim"], ["Yosys + OpenSTA", "area and timing"], ["Compare", "original vs candidate"],
];
st.forEach(([h, t], i) => {
  const x = 0.45 + i * 1.32;
  s.addShape("ellipse", { x: x + 0.38, y: 1.95, w: 0.5, h: 0.5, fill: { color: i === 1 ? C.accent2 : (i < 4 ? C.text1 : C.accent1) }, line: { color: "FFFFFF", width: 0 } });
  label(s, C, x + 0.38, 1.95, 0.5, 0.5, String(i + 1), { fontSize: 16, bold: true, color: "FFFFFF", align: "center", valign: "middle" });
  if (i < st.length - 1) arrow(s, x + 0.92, 2.2, x + 1.66, 2.2, HEX.line);
  box(s, C, x, 2.6, 1.25, 0.55, h, i === 1 ? "warn" : "soft", { bold: true, fontSize: 11 });
  label(s, C, x, 3.22, 1.25, 0.5, t, { fontSize: 10, align: "center" });
});
box(s, C, 0.45, 3.95, 4.45, 1.0, "Not equivalent or unproved: stop before HLS, keep the witness input. Unknown is never called equivalent.",
  "warn", { fontSize: 12, margin: 8 });
box(s, C, 5.1, 3.95, 4.45, 1.0, "A correct but worse rewrite is reported as exactly that: equivalence and hardware benefit are separate results.",
  "plain", { fontSize: 12, margin: 8 });

// 3. Product program with proved regions
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("Stage 2: shrink the product program with proved regions", { placeholder: "title" });
box(s, C, 0.45, 1.15, 2.0, 0.7, "prefix of original\n(loops i-j-k)", "soft", { fontSize: 11 });
box(s, C, 0.45, 2.05, 2.0, 0.7, "prefix of candidate\n(loops k-i-j)", "soft", { fontSize: 11 });
box(s, C, 2.95, 1.45, 2.1, 1.0, "own symbolic executor + Z3:\nboth safe, equal states", "plain", { fontSize: 11 });
box(s, C, 5.55, 1.45, 2.1, 1.0, "one product program:\nshared arbitrary state,\nthen both suffixes", "soft", { fontSize: 11 });
box(s, C, 8.1, 1.45, 1.45, 1.0, "ESBMC + Z3\ncheck the\nresidual", "warn", { fontSize: 11, bold: true });
arrow(s, 2.45, 1.5, 2.95, 1.8); arrow(s, 2.45, 2.4, 2.95, 2.1); arrow(s, 5.05, 1.95, 5.55, 1.95); arrow(s, 7.65, 1.95, 8.1, 1.95);
label(s, C, 5.05, 1.62, 0.5, 0.3, "proved", { fontSize: 9, color: HEX.grey, align: "center" });
const steps3 = [
  ["Pick a boundary", "a leading block (or the whole function) that no later code depends on except through arrays"],
  ["Prove the blocks equal", "our symbolic executor unrolls the loops; Z3 proves safety and equal states for all inputs"],
  ["Share one unknown state", "both blocks are replaced by the same arbitrary arrays; ESBMC checks only what is left"],
];
steps3.forEach(([h, t], i) => {
  const x = 0.45 + i * 3.08;
  box(s, C, x, 3.05, 2.9, 0.45, `${i + 1}. ${h}`, "ink", { bold: true, fontSize: 12 });
  box(s, C, x, 3.5, 2.9, 0.95, t, "plain", { fontSize: 11, valign: "top", margin: 6 });
});
label(s, C, 0.45, 4.6, 9.1, 0.5, "Sound because every real pair of prefix results is one of the equal arbitrary states: "
  + "if the suffixes agree for all of them, they agree for the real ones.", { fontSize: 11, italic: true });

// 4. Refinement
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("When the shortcut is too coarse: refine, then confirm", { placeholder: "title" });
const loop = [["ESBMC finds a mismatch\nin the abstract product", "warn"], ["generate an exact C\nsummary of the prefix", "soft"],
  ["prove the summary equals\nthe source (own SMT check)", "soft"], ["recheck the residual\nwith the summary", "acc"]];
loop.forEach(([t, k], i) => {
  const x = 0.45 + i * 2.35;
  box(s, C, x, 1.15, 2.05, 0.95, t, k, { fontSize: 11, bold: k === "acc" });
  if (i < 3) arrow(s, x + 2.05, 1.62, x + 2.35, 1.62);
});
box(s, C, 2.8, 2.45, 2.05, 0.75, "cannot summarise:\nput the original code back", "plain", { fontSize: 10 });
arrow(s, 3.82, 2.1, 3.82, 2.45, HEX.warn);
s.addText([
  { text: "return out[i];", options: { breakLine: true } },
  { text: "return 13*a[i];     // equal: prefix set out[i]=13*a[i]", options: { breakLine: true } },
  { text: "return 13*a[i] + 1; // still a real mismatch" },
], { x: 5.1, y: 2.4, w: 4.45, h: 0.85, isTextBox: true, fontFace: mono, fontSize: 9, color: C.text1,
  fill: { color: C.background2 }, line: { color: HEX.line, width: 0.75 }, margin: 6 });
box(s, C, 0.45, 3.55, 9.1, 1.4, "Counterexamples are checked too: a whole-function SMT mismatch proposes an input, ESBMC rechecks the real "
  + "unabstracted pair at that input, and the input is compiled and run natively. Agreement at one input proves nothing, "
  + "so a false proposal is dropped and the full domain is checked. Every accepted SMT query is exported and replayed.",
  "soft", { fontSize: 12, align: "left", margin: 10 });

// 5. Worked example
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("One real run: 4x4 matmul, i-j-k vs k-i-j", { placeholder: "title" });
s.addText([
  "[2/7] region_equality: equivalent [symbolic / Z3]",
  "      residual_0: equivalent [ESBMC / Z3]",
  "      VERDICT: equivalent (0.532 s)",
  "[3/7] accepted SMT queries replayed: 1",
  "[4/7] PASS: 264 typed edge/random comparisons",
  "[5/7] RTL: 266 vs 314 average cycles",
  "[6/7] area 4612.97 vs 5004.26 um^2",
  "[7/7] Area x latency outcome: REGRESSED",
].map((t, i, a) => ({ text: t, options: { breakLine: i < a.length - 1 } })),
{ x: 0.45, y: 1.1, w: 4.7, h: 2.6, isTextBox: true, fontFace: mono, fontSize: 10, color: C.text1,
  fill: { color: C.background2 }, line: { color: HEX.line, width: 0.75 }, margin: 8, valign: "top" });
s.addTable([
  [{ text: "Metric", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Original", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Candidate", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Change", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } }],
  ["Area (um^2)", "4612.97", "5004.26", { text: "-8.48%", options: { color: HEX.warn, bold: true } }],
  ["Cycles", "266", "314", { text: "-18.05%", options: { color: HEX.warn, bold: true } }],
  ["Delay (ns)", "1.866", "1.835", { text: "+1.66%", options: { color: HEX.acc, bold: true } }],
  ["Area x latency", "1.227e7", "1.571e7", { text: "-28.06%", options: { color: HEX.warn, bold: true } }],
], { x: 5.35, y: 1.1, w: 4.2, colW: [1.3, 0.95, 0.95, 1.0], fontSize: 11, color: C.text1,
  border: { type: "solid", color: HEX.line, pt: 0.75 }, rowH: 0.42 });
box(s, C, 0.45, 3.95, 9.1, 1.0, "Proved equal in half a second, yet the \"optimised\" loop order is worse hardware. "
  + "matmul_wrong.cpp (one * changed to +) gets a native witness and stops before HLS.", "warn",
  { fontSize: 13, bold: true, margin: 10 });

// 6. Evaluation setup
pres.addSection({ title: "Evaluation" });
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("How we evaluated", { placeholder: "title" });
const sets = [
  ["Main cohort", "50 LLM-assisted rewrites (47 distinct originals) + 50 planted faults; 100 hardware builds"],
  ["Subtle faults", "50 small edits, 4 traps, 20 equivalent edits, 6 undefined-C; labels fixed before running"],
  ["Two models", "12 MachSuite / CHStone / HLS-Eval inputs; one first answer each from Qwen 1.5B and GPT-6.1-Sol"],
  ["Local model", "20 kernels x 2 settings of Qwen 1.5B: 40 raw first answers"],
  ["Integrated", "239 rechecks of all groups with the final checker"],
  ["Public / scale", "8 real leaf functions (+8 bugs), 14 EqBench pairs, 27 larger pairs up to 16x16 GEMM"],
];
sets.forEach(([h, t], i) => {
  const x = 0.45 + (i % 2) * 4.6, y = 1.1 + Math.floor(i / 2) * 1.0;
  box(s, C, x, y, 1.45, 0.82, h, i < 2 ? "acc" : "ink", { bold: true, fontSize: 12 });
  box(s, C, x + 1.45, y, 3.0, 0.82, t, "plain", { fontSize: 10.5, align: "left", margin: 6 });
});
label(s, C, 0.45, 4.2, 9.1, 0.7, "Groups overlap (some pairs are rechecked later), so counts are not added. Hardware: Bambu 2026.11, "
  + "Verilator, Yosys 0.36, OpenSTA 2.0.18, Nangate45, common 10 ns clock; 60 s per solver call.", { fontSize: 11, italic: true });

// 7. Correctness
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("Correctness: every planted and subtle fault caught", { placeholder: "title" });
stat(s, C, 0.45, 1.05, 2.2, "50/50", "rewrites proved\nequivalent", undefined, 34);
stat(s, C, 2.7, 1.05, 2.2, "50/50", "planted faults\nrejected", HEX.warn, 34);
stat(s, C, 4.95, 1.05, 2.2, "80/80", "subtle-fault labels\nmatch", undefined, 34);
stat(s, C, 7.2, 1.05, 2.35, "236/237", "known labels match\n(1 inconclusive)", undefined, 34);
box(s, C, 0.45, 2.55, 4.45, 2.4, "5 faults passed all 264 test inputs but the proof caught them:\n"
  + "all_equal16, clamp16, threshold_pack8, search_count16, fault_rare_magic.\nEach witness was replayed in compiled C.",
  "warn", { fontSize: 12, margin: 10 });
bullets(s, C, 5.1, 2.55, 4.45, 2.4, [
  "Local Qwen: 28 equivalent, 8 real mistakes (FIR coefficients, XOR as abs-diff, SYRK indexing...), 2 undefined",
  "Summaries used in 120 checks, refinement in 22",
  "All 121 mismatch inputs reproduced in compiled C",
  "Larger pairs: 22 equivalent, 3 not, 4 inconclusive",
], 11.5);

// 8. Hardware
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("Hardware: correct does not mean better", { placeholder: "title" });
stat(s, C, 0.45, 1.05, 1.45, "22", "ALP improved", HEX.acc);
stat(s, C, 1.95, 1.05, 1.45, "25", "ALP worse", HEX.warn);
stat(s, C, 3.45, 1.05, 1.45, "3", "unchanged", HEX.grey);
bullets(s, C, 0.45, 2.45, 4.45, 2.5, [
  "ALP = area x latency, over all 50 proved-equivalent rewrites",
  "Area better in 14, cycles in 34, delay in 11",
  "Wins: real algorithm changes (prefix reuse, XOR-fold parity, byte-parallel popcount)",
  "Losses: unrolling cuts cycles but multiplies area (sum32: 35 to 19 cycles, -278% ALP)",
], 11.5);
hbars(s, C, 5.1, 1.4, 4.45, [
  ["bitreverse32", 100.0, HEX.acc], ["popcount8", 99.11, HEX.acc], ["parity32", 98.87, HEX.acc], ["prefix", 79.38, HEX.acc],
  ["gemm", -130.3], ["sum32", -278.26], ["boxfilter", -370.87], ["symv4", -386.03]].map(([n, v, c]) => [n, Math.abs(v), c, (v > 0 ? "+" : "") + v + "%"]),
  { title: "ALP change, best 4 (green) and worst 4 (red), %", labelW: 1.3, rowH: 0.43 });
label(s, C, 5.1, 4.9, 4.45, 0.3, "Bar length = size of the change; green is better, red is worse.", { fontSize: 9, italic: true, color: HEX.grey });

// 9. Two models and time
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("Two models, and how long proofs take", { placeholder: "title" });
s.addTable([
  [{ text: "Model (12 inputs)", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Equivalent", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Speedup*", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "ALP ratio*", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } }],
  ["Qwen Coder 1.5B", "12 (9 unchanged code)", "0.937x", "1.066"],
  ["GPT-6.1-Sol", "10 (2 inconclusive)", "1.258x", "0.972"],
], { x: 0.45, y: 1.1, w: 4.7, colW: [1.4, 1.5, 0.9, 0.9], fontSize: 11, color: C.text1,
  border: { type: "solid", color: HEX.line, pt: 0.75 }, rowH: 0.45 });
label(s, C, 0.45, 2.5, 4.7, 0.3, "* geometric mean over the 10 cases measured for both models; ALP ratio below 1 is better",
  { fontSize: 9, italic: true, color: HEX.grey });
box(s, C, 0.45, 3.0, 4.7, 1.9, "Best single result: GPT's SYRK rewrite, 232 to 100 cycles, about 40% less area, +74% ALP. "
  + "Its GEMM, stencil and MVT rewrites were faster but larger overall. Nine of Qwen's twelve answers did not change the code.",
  "soft", { fontSize: 12, margin: 10, align: "left" });
hbars(s, C, 5.4, 1.45, 4.15, [["4x4 matmul", 0.53, HEX.acc], ["64-tap FIR", 0.71, HEX.acc], ["128 dot", 0.96, HEX.acc],
  ["16x16 stencil", 2.49, HEX.acc], ["128 prefix", 2.64, HEX.acc], ["16x16 GEMM", 3.38, HEX.acc], ["indexed GEMM", 15.76, HEX.acc]],
  { title: "Proof time, seconds (limit 60 s per solver call)", labelW: 1.35, rowH: 0.47 });

// 10. Conclusion
pres.addSection({ title: "Conclusion" });
s = pres.addSlide({ masterName: "DARK", sectionTitle: "Conclusion" });
s.addText("Prove it is safe, then measure if it is worth it", { placeholder: "title" });
label(s, C, 0.6, 2.75, 4.3, 0.35, "What we showed", { fontSize: 15, bold: true, color: HEX.gold });
label(s, C, 0.6, 3.15, 4.3, 1.9, "Every planted and subtle fault was caught, including 5 that tests missed. Half of the "
  + "proved-correct rewrites made the hardware worse. A later check by VWE agreed on all 125 cases it decided.",
  { fontSize: 12, color: "FFFFFF" });
label(s, C, 5.2, 2.75, 4.3, 0.35, "Limits", { fontSize: 15, bold: true, color: HEX.gold });
label(s, C, 5.2, 3.15, 4.3, 1.9, "Integer kernels with fixed, non-overlapping arrays only; one abstracted region; no loop "
  + "invariants. Hardware numbers are pre-layout ASIC estimates on related teaching kernels.", { fontSize: 12, color: "FFFFFF" });

(async () => {
  await pres.writeFile({ fileName: OUT });
  await applyTheme(OUT, THEME);
  console.log("wrote", OUT);
})();
