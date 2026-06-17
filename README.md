# Add Two Numbers — Interactive Explainer

An interactive, single-page explainer for [LeetCode #2 — Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) (Medium).

Two numbers are stored as linked lists with digits in reverse order. This page walks through *why* that reversal is actually convenient, builds the grade-school addition analogy, and lets you step through the algorithm node-by-node — including the carry-leftover edge case — before showing the code.

## What's inside

- **The setup** — a static diagram of the two input lists and what the result should look like.
- **Grade-school addition stepper** — click through 342 + 465 column by column to build the core intuition before any code appears.
- **Main algorithm stepper** — step through `[2→4→3] + [5→6→4]`, watching both pointers move, the carry bubble update, and result nodes get created in real time.
- **Edge case stepper** — `[9→9→9] + [1]` (999 + 1 = 1000), demonstrating the case where a leftover carry creates an extra node after both lists are exhausted.
- **Annotated Python solution** with syntax highlighting and a copy button.
- **Complexity breakdown** — time and space, explained.
- **Try it yourself** — enter your own digit lists and see the result computed live.

## Tech

Single self-contained `index.html`. No build step, no dependencies beyond Google Fonts (Lora, Inter, JetBrains Mono) loaded via CDN. Open the file directly in a browser, or serve it with any static host.

## Run locally

```bash
git clone https://github.com/<your-username>/add-two-numbers-explainer.git
cd add-two-numbers-explainer
open index.html   # or just double-click it
```

## Live site

[Live link goes here once deployed]
