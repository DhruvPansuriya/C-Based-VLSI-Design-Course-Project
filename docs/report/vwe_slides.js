// Builds VWE_slides.pptx (10 slides). Run from this folder:
//   NODE_PATH=<folder with node_modules> node vwe_slides.js <path to pptx skill apply_theme.js>
const path = require("path");
const { THEME, HEX, newDeck, box, arrow, label, stat, bullets, hbars, stackbars } = require("./slides_common");
const { applyTheme } = require(process.argv[2]);

const OUT = path.join(__dirname, "VWE_slides.pptx");
const { pres, C } = newDeck("Verdicts with Evidence (VWE)", "VWE  |  C-Based VLSI Design (CS5291)  |  IIT Guwahati");
const mono = "Courier New";

// 1. Title
pres.addSection({ title: "Introduction" });
let s = pres.addSlide({ masterName: "DARK", sectionTitle: "Introduction" });
s.addText("Verdicts with Evidence (VWE)", { placeholder: "title" });
label(s, C, 0.6, 2.5, 8.8, 0.5, "Checking whether an AI-made change to a C function really does what was asked",
  { fontSize: 17, color: HEX.soft, italic: true });
s.addShape("line", { x: 0.6, y: 3.15, w: 2.2, h: 0, line: { color: HEX.gold, width: 2 } });
label(s, C, 0.6, 3.3, 5.2, 1.0,
  "Dhruvkumar R Pansuriya (230101071)\nAryan Kaushik (230101018)\nLasya Madhu Sundar (230101058)",
  { fontSize: 13, color: "FFFFFF" });
label(s, C, 5.9, 3.3, 3.5, 1.0, "Instructor: Dr. Chandan Karfa\nC-Based VLSI Design (CS5291)\nIIT Guwahati",
  { fontSize: 13, color: "FFFFFF" });
label(s, C, 0.6, 4.75, 8.8, 0.3, "github.com/DhruvPansuriya/C-Based-VLSI-Design-Course-Project  (folder approach-2-vwe)",
  { fontSize: 10, color: HEX.line });

// 2. The idea
pres.addSection({ title: "Method" });
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("The idea: several readings, checked by proof", { placeholder: "title" });
box(s, C, 0.45, 1.15, 1.5, 0.55, "P0  (old code)", "plain", { bold: true });
box(s, C, 0.45, 1.85, 1.5, 0.55, "N  (request)", "plain", { bold: true });
box(s, C, 0.45, 3.4, 1.5, 0.55, "P1  (new code)", "warn", { bold: true });
box(s, C, 2.45, 1.3, 2.3, 0.95, "Readings of N\nwritten from P0 and N only\n(LLM never sees P1)", "soft", { fontSize: 11 });
box(s, C, 5.2, 1.3, 2.0, 0.95, "Check readings on P0,\nthen freeze them", "soft", { fontSize: 11 });
box(s, C, 5.2, 3.1, 2.0, 1.1, "CBMC proofs\n(SAT and Z3 must agree)\n+ real replay", "ink", { fontSize: 11 });
box(s, C, 7.65, 3.1, 1.9, 1.1, "ACCEPT\nREJECT\nUNDECIDED", "gold", { bold: true, fontSize: 12 });
arrow(s, 1.95, 1.45, 2.45, 1.65); arrow(s, 1.95, 2.12, 2.45, 1.95);
arrow(s, 4.75, 1.78, 5.2, 1.78); arrow(s, 6.2, 2.25, 6.2, 3.1);
arrow(s, 1.95, 3.67, 5.2, 3.67, HEX.warn); arrow(s, 7.2, 3.65, 7.65, 3.65);
label(s, C, 2.2, 3.75, 2.9, 0.3, "P1 only meets the proofs, never a model", { fontSize: 10, italic: true, color: HEX.warn });
label(s, C, 0.45, 4.35, 9.1, 0.3, "Every decision carries an evidence class:", { fontSize: 12, bold: true });
[["E0", "P1 has new undefined behaviour (a crash) that P0 did not"],
 ["E1", "P1 changed old behaviour outside every reading's change zone"],
 ["E2", "P1 meets every reading (ACCEPT) or none of them (REJECT)"]].forEach(([k, t], i) => {
  const x = 0.45 + i * 3.05;
  box(s, C, x, 4.65, 0.5, 0.5, k, "acc", { bold: true });
  label(s, C, x + 0.58, 4.65, 2.35, 0.55, t, { fontSize: 10, valign: "middle" });
});

// 4. Pipeline
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("The pipeline, stage by stage", { placeholder: "title" });
const stages = [
  ["1", "Admission", "Parse P0 and P1, same signature, only supported C"],
  ["2", "Readings", "Strict, permissive and adversarial meanings of N"],
  ["3", "Validate", "Check each reading on P0 alone, then freeze"],
  ["4", "Prove", "E0 safety, E1 preservation, E2 per reading"],
  ["5", "Confirm", "Fixed-input re-proof, ASan/UBSan replay"],
  ["6", "Verdict", "Decision + evidence class + conditions"],
  ["7", "Report", "HTML/JSON with every proof and witness"],
];
stages.forEach(([n, h, t], i) => {
  const x = 0.45 + i * 1.32;
  s.addShape("ellipse", { x: x + 0.38, y: 1.15, w: 0.5, h: 0.5, fill: { color: i === 3 ? C.accent2 : C.accent1 }, line: { color: "FFFFFF", width: 0 } });
  label(s, C, x + 0.38, 1.15, 0.5, 0.5, n, { fontSize: 16, bold: true, color: "FFFFFF", align: "center", valign: "middle" });
  if (i < stages.length - 1) arrow(s, x + 0.92, 1.4, x + 1.66, 1.4, HEX.line);
  box(s, C, x, 1.8, 1.25, 0.45, h, i === 3 ? "warn" : "soft", { bold: true, fontSize: 12 });
  label(s, C, x + 0.02, 2.35, 1.2, 1.2, t, { fontSize: 10, align: "center" });
});
box(s, C, 0.45, 3.6, 4.45, 1.35, "Every CBMC run uses the same mandatory flags (unwinding assertions, no malloc failure, "
  + "all safety checks). Buffers get their exact symbolic size.", "plain", { fontSize: 11, align: "left", margin: 10 });
box(s, C, 5.1, 3.6, 4.45, 1.35, "A timeout, a solver disagreement or a failed replay never becomes a decision. "
  + "It becomes UNDECIDED, with the reason written down.", "warn", { fontSize: 11, align: "left", margin: 10 });

// 5. Verdict rules
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("How the verdict is decided", { placeholder: "title" });
const q = [["New crash or UB in P1 where P0 is safe?", "REJECT  E0"],
  ["Old behaviour changed outside every change zone?", "REJECT  E1"],
  ["Does P1 meet every surviving reading?", "ACCEPT  E2"]];
q.forEach(([t, v], i) => {
  const y = 1.1 + i * 1.05;
  box(s, C, 0.6, y, 4.4, 0.7, t, "soft", { fontSize: 13 });
  arrow(s, 5.0, y + 0.35, 6.2, y + 0.35);
  label(s, C, 5.2, y + 0.05, 0.8, 0.3, "yes, proved", { fontSize: 9, color: HEX.grey });
  box(s, C, 6.2, y + 0.07, 1.8, 0.56, v, i === 2 ? "acc" : "warn", { bold: true, fontSize: 13 });
  if (i < 2) { arrow(s, 2.8, y + 0.7, 2.8, y + 1.05); label(s, C, 2.9, y + 0.72, 0.5, 0.3, "no", { fontSize: 9, color: HEX.grey }); }
});
arrow(s, 2.8, 3.95, 2.8, 4.3);
box(s, C, 0.6, 4.3, 4.4, 0.6, "fails every reading: REJECT E2\nmixed, or anything not proved: UNDECIDED", "plain", { fontSize: 11 });
box(s, C, 8.2, 1.1, 1.35, 3.8, "SAT and Z3 must give the same answer, and each REJECT witness is re-run as real code before it counts.",
  "plain", { fontSize: 10, margin: 6 });

// 5b. Stages 3-5 in detail
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("Inside stages 3 to 5: regions and proofs", { placeholder: "title" });
s.addShape("rect", { x: 0.45, y: 1.1, w: 4.6, h: 3.4, fill: { color: C.background2 }, line: { color: HEX.ink, width: 1.25 } });
label(s, C, 0.6, 1.17, 4.3, 0.3, "Declared inputs (e.g. sizes up to K, values in a range)", { fontSize: 10, bold: true });
s.addShape("ellipse", { x: 0.75, y: 1.6, w: 2.3, h: 1.5, fill: { color: C.accent5 }, line: { color: HEX.acc, width: 1.25 } });
label(s, C, 0.85, 1.95, 2.1, 0.8, "Change zone\nreadings say what P1\nmust do here (E2)", { fontSize: 10, align: "center" });
s.addShape("rect", { x: 3.35, y: 3.25, w: 1.5, h: 1.05, fill: { color: C.accent6 }, line: { color: HEX.warn, width: 1.25, dashType: "dash" } });
label(s, C, 3.4, 3.3, 1.4, 0.95, "P0 itself is undefined here: left out by the guard", { fontSize: 9, align: "center", valign: "middle" });
label(s, C, 0.65, 3.45, 2.6, 0.9, "Everywhere else:\nP1 must give the same\noutputs as P0 (E1)", { fontSize: 10, italic: true });
const proofs = [
  ["Guard", "from P0 alone: where is P0 safe and deterministic?"],
  ["Validate", "drop readings P0 already meets; keep UNKNOWN as unresolved"],
  ["Harness", "inputs as symbols, exact-size malloc, P0 and P1 side by side"],
  ["CBMC", "SAT and Z3 run the same check and must agree"],
  ["Confirm", "re-prove with the witness fixed, run it under ASan/UBSan; ESBMC can only veto"],
];
proofs.forEach(([h, t], i) => {
  const y = 1.1 + i * 0.7;
  box(s, C, 5.3, y, 1.15, 0.55, h, i === 3 ? "acc" : "ink", { bold: true, fontSize: 12 });
  label(s, C, 6.55, y, 3.0, 0.6, t, { fontSize: 10.5, valign: "middle" });
});

// 6. Worked example
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Method" });
s.addText("One real run: saturating 8-bit addition", { placeholder: "title" });
s.addText([
  { text: "P0:  ", options: { bold: true } }, { text: "return (unsigned char)(a + b);   // 200+100 gives 44", options: { breakLine: true } },
  { text: "N:   ", options: { bold: true } }, { text: "Saturate at 255 rather than wrapping.", options: { breakLine: true } },
  { text: "P1:  ", options: { bold: true, color: HEX.warn } }, { text: "return 255u;   // candidate v3, a bad fix" },
], { x: 0.45, y: 1.05, w: 9.1, h: 0.85, isTextBox: true, fontFace: mono, fontSize: 11, color: C.text1,
  fill: { color: C.background2 }, line: { color: HEX.line, width: 0.75 }, margin: 8, valign: "middle" });
const steps = [
  ["Readings", "change zone a+b > 255;\nelsewhere keep P0"],
  ["P0 guard", "unsigned add never has UB: safe everywhere"],
  ["E0 proof", "P1 adds no new UB\nPROVED (SAT, Z3)"],
  ["E1 proof", "witness a=0, b=0\nP0 gives 0, P1 gives 255"],
  ["Replay", "ASan/UBSan run\nconfirms 0 vs 255"],
];
steps.forEach(([h, t], i) => {
  const x = 0.45 + i * 1.86;
  box(s, C, x, 2.15, 1.62, 0.42, h, i === 3 ? "warn" : "soft", { bold: true });
  label(s, C, x, 2.65, 1.62, 0.9, t, { fontSize: 10.5, align: "center" });
  if (i < steps.length - 1) arrow(s, x + 1.64, 2.36, x + 1.86, 2.36);
});
box(s, C, 0.45, 3.65, 4.4, 1.25, "Verdict for v3:  REJECT  E1\nthe sum 0+0 has no overflow, yet P1 changed it\n(16.4 s)",
  "warn", { fontSize: 13, bold: true });
box(s, C, 5.15, 3.65, 4.4, 1.25, "Correct fix v1 (s > 255 ? 255 : s):  ACCEPT  E2\nmeets both readings; zone reachable\n(20.3 s)",
  "acc", { fontSize: 13, bold: true });

// 7. Evaluation setup
pres.addSection({ title: "Evaluation" });
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("How we evaluated", { placeholder: "title" });
const sets = [
  ["Chrysalis-HLS (public bugs)", ["20 tasks, 97 candidates: correct code, unchanged buggy code, small mutations",
    "Labels: bounded proof against the correct code + 10,000 sanitizer runs",
    "Requests from templates; sizes shrunk to 4"]],
  ["HLSCheck (Approach-1)", ["181 candidates from our first approach: rewrites, one-bit faults, 80 subtle faults",
    "HLSCheck's equivalence labels",
    "One computed \"keep behaviour\" reading, no LLM; sizes up to 32"]],
  ["Baselines", ["B1: tests only (no crash = accept)", "B3: our pipeline, strict reading only",
    "B4: regression check only", "B2 (LLM judge) not built: it would show P1 to a model"]],
];
sets.forEach(([h, items], i) => {
  const x = 0.45 + i * 3.08;
  box(s, C, x, 1.1, 2.9, 0.5, h, i === 2 ? "ink" : "acc", { bold: true, fontSize: 13 });
  s.addShape("rect", { x, y: 1.6, w: 2.9, h: 2.05, fill: { color: C.background1 }, line: { color: HEX.line, width: 1 } });
  bullets(s, C, x + 0.05, 1.7, 2.8, 2.3, items, 11);
});
box(s, C, 0.45, 3.95, 9.1, 0.8, "Labels stay hidden until every verdict is written. Cases from one task are related, "
  + "so intervals resample whole tasks and comparisons are made task by task.", "soft", { fontSize: 12, margin: 8 });

// 8. Results overview
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("Results across all test sets", { placeholder: "title" });
s.addTable([
  [{ text: "Test set", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Cases", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } },
   { text: "Result", options: { bold: true, color: "FFFFFF", fill: { color: C.text1 } } }],
  ["Golden examples (ours)", "20", "20 of 20 match"],
  ["Demo", "9", "9 of 9, 65 s total"],
  ["Chrysalis-HLS bugs", "89", "1 decided, 0 wrong"],
  ["HLSCheck cases", "181", "125 decided, 0 wrong"],
  ["Live LLM readings", "10", "3 same, 7 undecided, 0 opposite"],
], { x: 0.45, y: 1.1, w: 4.7, colW: [1.9, 0.7, 2.1], fontSize: 11, color: C.text1,
  border: { type: "solid", color: HEX.line, pt: 0.75 }, rowH: 0.42 });
hbars(s, C, 5.4, 1.5, 4.15, [["VWE", 0, HEX.acc], ["Strict only (B3)", 0, HEX.acc], ["Regression only (B4)", 10],
  ["Tests only (B1)", 41]], { title: "Wrong decisions on 89 Chrysalis cases", labelW: 1.75, rowH: 0.6 });
box(s, C, 0.45, 4.15, 9.1, 0.8, "No wrong decision anywhere. The cost is coverage: on Chrysalis VWE decided only 1 of 89, "
  + "mostly because solvers timed out on 64-bit products or the injected bug could not be seen at size 4.", "soft",
  { fontSize: 12, align: "left", margin: 10 });

// 9. Approach-1
s = pres.addSlide({ masterName: "CONTENT", sectionTitle: "Evaluation" });
s.addText("VWE on HLSCheck's 181 cases (Approach-1)", { placeholder: "title" });
stat(s, C, 0.45, 1.05, 1.5, "181", "candidates");
stat(s, C, 2.0, 1.05, 1.5, "125", "decided (69%)");
stat(s, C, 3.55, 1.05, 1.5, "0", "disagree with\nHLSCheck labels", HEX.warn);
stackbars(s, C, 5.3, 1.45, 4.25, [["equivalent", [48, 0, 23]], ["not equivalent", [0, 73, 31]], ["undefined (4 / 2)", [0, 4, 2]]],
  [["ACCEPT", HEX.acc], ["REJECT", HEX.warn], ["UNDECIDED", HEX.line, HEX.ink]], { title: "VWE answer, by HLSCheck label", rowH: 0.62 });
bullets(s, C, 0.45, 2.45, 4.7, 2.6, [
  "HLSCheck asks: is an LLM-optimised HLS kernel equal to the original? VWE ran each as \"optimise without changing behaviour\", with no LLM.",
  "Evidence: E0 = 4, E1 = 73, E2 = 48. Median 17.7 s when decided.",
  "All 5 faults that escaped the 264 test inputs were caught (REJECT E1).",
  "One CBMC false alarm (gaussian5) was stopped by the real replay.",
], 11.5);
box(s, C, 5.3, 4.1, 4.25, 0.85, "Undecided: 48 no safe reference guard, 5 solver timeouts, 3 replay mismatches.",
  "plain", { fontSize: 11, margin: 8 });

// 10. Conclusion
pres.addSection({ title: "Conclusion" });
s = pres.addSlide({ masterName: "DARK", sectionTitle: "Conclusion" });
s.addText("Abstaining is cheap. Being wrong is not.", { placeholder: "title" });
label(s, C, 0.6, 2.75, 4.3, 0.35, "Where we stand", { fontSize: 15, bold: true, color: HEX.gold });
label(s, C, 0.6, 3.15, 4.3, 1.9, "Across every test set VWE made no wrong decision. Its answers are bounded to the "
  + "declared input sizes, and it abstains when solvers time out. HLS area and latency were not measured.",
  { fontSize: 12, color: "FFFFFF" });
label(s, C, 5.2, 2.75, 4.3, 0.35, "Next steps", { fontSize: 15, bold: true, color: HEX.gold });
label(s, C, 5.2, 3.15, 4.3, 1.9, "A Z3-only path for SAT timeouts, a check for uninitialised arrays, human-written "
  + "requests instead of templates, and HLS pragma checks.", { fontSize: 12, color: "FFFFFF" });

(async () => {
  await pres.writeFile({ fileName: OUT });
  await applyTheme(OUT, THEME);
  console.log("wrote", OUT);
})();
