// Shared theme, layouts and drawing helpers for the course slide decks.
// Needs pptxgenjs (npm install pptxgenjs@3.12.0) on NODE_PATH.
const pptxgen = require("pptxgenjs");

const THEME = {
  name: "VWE Course",
  headFontFace: "Cambria",
  bodyFontFace: "Calibri",
  colors: {
    dk1: "1F2A44", lt1: "FFFFFF", dk2: "0F7B6C", lt2: "F3F6F8",
    accent1: "0F7B6C", accent2: "B5462E", accent3: "1F2A44",
    accent4: "D9A441", accent5: "E8F3F1", accent6: "F7E9E5",
    hlink: "0F7B6C", folHlink: "1F2A44",
  },
};
const HEX = { ink: "1F2A44", acc: "0F7B6C", warn: "B5462E", gold: "D9A441",
  soft: "E8F3F1", softw: "F7E9E5", grey: "5B6475", light: "F3F6F8", line: "C9D1DA" };

function newDeck(title, footer) {
  const pres = new pptxgen();
  pres.layout = "LAYOUT_16x9"; // 10 x 5.625 in
  pres.title = title;
  pres.author = "Dhruvkumar R Pansuriya, Aryan Kaushik, Lasya Madhu Sundar";
  pres.theme = { headFontFace: THEME.headFontFace, bodyFontFace: THEME.bodyFontFace };
  const C = pres.SchemeColor;
  pres.defineSlideMaster({
    title: "DARK", background: { color: C.text1 },
    objects: [{ placeholder: { options: { name: "title", type: "title", x: 0.6, y: 1.0, w: 8.8, h: 1.25, align: "left",
      fontFace: THEME.headFontFace, fontSize: 36, bold: true, color: C.background1, valign: "bottom", margin: 0 },
      text: "Title" } }],
  });
  pres.defineSlideMaster({
    title: "CONTENT", background: { color: C.background1 },
    margin: [0.3, 0.4, 0.4, 0.4],
    objects: [
      { placeholder: { options: { name: "title", type: "title", x: 0.45, y: 0.22, w: 9.1, h: 0.6, align: "left",
        fontFace: THEME.headFontFace, fontSize: 24, bold: true, color: C.text1, valign: "middle", margin: 0 },
        text: "Title" } },
      { line: { x: 0.45, y: 0.86, w: 0.9, h: 0, line: { color: HEX.acc, width: 2.5 } } },
      { text: { text: footer, options: { x: 0.45, y: 5.28, w: 7, h: 0.25, fontSize: 9, color: C.text2, margin: 0 } } },
    ],
    slideNumber: { x: 9.1, y: 5.28, w: 0.45, h: 0.25, fontSize: 9, color: HEX.grey, align: "right" },
  });
  return { pres, C };
}

// A rounded box with text. kind: "soft" | "warn" | "ink" | "plain" | "gold"
function box(slide, C, x, y, w, h, text, kind = "soft", opts = {}) {
  const fills = { soft: C.accent5, warn: C.accent6, ink: C.text1, plain: C.background1, gold: C.accent4, acc: C.accent1 };
  const lines = { soft: HEX.acc, warn: HEX.warn, ink: HEX.ink, plain: HEX.line, gold: HEX.gold, acc: HEX.acc };
  const dark = kind === "ink" || kind === "acc";
  slide.addText(text, {
    shape: "roundRect", rectRadius: 0.08, x, y, w, h, isTextBox: true,
    fill: { color: fills[kind] }, line: { color: lines[kind], width: 1 },
    fontSize: opts.fontSize || 12, color: dark ? C.background1 : C.text1, bold: !!opts.bold,
    align: opts.align || "center", valign: opts.valign || "middle", margin: opts.margin ?? 4,
    fontFace: opts.fontFace, objectName: opts.name,
  });
}

function arrow(slide, x1, y1, x2, y2, color = HEX.ink) {
  const flipH = x2 < x1, flipV = y2 < y1;
  slide.addShape("line", { x: Math.min(x1, x2), y: Math.min(y1, y2), w: Math.abs(x2 - x1), h: Math.abs(y2 - y1),
    flipH, flipV, line: { color, width: 1.5, endArrowType: "triangle" } });
}

// Small label text with no box.
function label(slide, C, x, y, w, h, text, opts = {}) {
  slide.addText(text, { x, y, w, h, isTextBox: true, margin: 0, fontSize: opts.fontSize || 10,
    color: opts.color || C.text1, italic: !!opts.italic, bold: !!opts.bold, align: opts.align || "left",
    valign: opts.valign || "top", fontFace: opts.fontFace });
}

// Big number with a caption underneath.
function stat(slide, C, x, y, w, num, caption, color) {
  slide.addText(num, { x, y, w, h: 0.75, isTextBox: true, margin: 0, fontSize: 40, bold: true,
    color: color || C.accent1, align: "center", fontFace: THEME.headFontFace });
  slide.addText(caption, { x, y: y + 0.75, w, h: 0.5, isTextBox: true, margin: 0, fontSize: 11,
    color: C.text1, align: "center", valign: "top" });
}

function bullets(slide, C, x, y, w, h, items, fontSize = 13) {
  slide.addText(items.map((t, i) => ({ text: t, options: { bullet: true, breakLine: i < items.length - 1 } })),
    { x, y, w, h, isTextBox: true, fontSize, color: C.text1, valign: "top", paraSpaceAfter: 5, margin: 2 });
}

// Horizontal bars drawn with shapes (renders the same in PowerPoint, Keynote and Google Slides).
function hbars(slide, C, x, y, w, rows, opts = {}) {
  const max = opts.max || Math.max(...rows.map(r => r[1]), 1);
  const lw = opts.labelW || 1.7, rh = opts.rowH || 0.5, bw = w - lw - 0.5;
  if (opts.title) label(slide, C, x, y - 0.4, w, 0.3, opts.title, { fontSize: 12, bold: true });
  rows.forEach(([name, v, color], i) => {
    const yy = y + i * rh;
    label(slide, C, x, yy, lw - 0.1, rh * 0.8, name, { fontSize: 11, align: "right", valign: "middle" });
    const len = Math.max(bw * v / max, 0.02);
    slide.addShape("rect", { x: x + lw, y: yy + 0.08, w: len, h: rh * 0.8 - 0.16, fill: { color: color || HEX.warn }, line: { color: color || HEX.warn, width: 0 } });
    label(slide, C, x + lw + len + 0.06, yy, 0.6, rh * 0.8, String(v), { fontSize: 12, bold: true, valign: "middle" });
  });
}

// Horizontal stacked bars: segs = [[name, color]], rows = [[label, [v1, v2, ...]]].
function stackbars(slide, C, x, y, w, rows, segs, opts = {}) {
  const lw = opts.labelW || 1.4, rh = opts.rowH || 0.55, bw = w - lw;
  const max = Math.max(...rows.map(r => r[1].reduce((a, b) => a + b, 0)));
  if (opts.title) label(slide, C, x, y - 0.4, w, 0.3, opts.title, { fontSize: 12, bold: true });
  rows.forEach(([name, vals], i) => {
    const yy = y + i * rh; let cx = x + lw;
    label(slide, C, x, yy, lw - 0.1, rh * 0.8, name, { fontSize: 11, align: "right", valign: "middle" });
    vals.forEach((v, k) => {
      if (!v) return;
      const len = bw * v / max;
      slide.addText(len > 0.3 ? String(v) : "", { shape: "rect", x: cx, y: yy + 0.06, w: len, h: rh * 0.8 - 0.12, isTextBox: true,
        fill: { color: segs[k][1] }, line: { color: "FFFFFF", width: 0.75 }, fontSize: 10, bold: true,
        color: segs[k][2] || "FFFFFF", align: "center", valign: "middle", margin: 0 });
      cx += len;
    });
  });
  const ly = y + rows.length * rh + 0.05;
  segs.forEach(([name, color], k) => {
    slide.addShape("rect", { x: x + 0.3 + k * 1.3, y: ly + 0.07, w: 0.16, h: 0.16, fill: { color }, line: { color, width: 0 } });
    label(slide, C, x + 0.3 + k * 1.3 + 0.22, ly, 1.05, 0.3, name, { fontSize: 10, valign: "middle" });
  });
}

module.exports = { THEME, HEX, newDeck, box, arrow, label, stat, bullets, hbars, stackbars };
