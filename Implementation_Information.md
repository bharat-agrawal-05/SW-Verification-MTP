# Implementation Notes: Deviations from Paper Methodology

This document records, for each research question (RQ) studied in the paper, a short account of what the RQ investigates and where our implementation diverges from the paper's described methodology. It also covers an extended repair strategy (CeGIS-based repair) built on top of the paper's RQ2 work but not part of the original paper.

---

## RQ1.1 — Baseline Generation: Plain Prompt vs. Instruction-Augmented Prompt

**What this RQ is about**

The LLM is asked to generate *k* candidate invariants for a problem from a prompt, and each candidate is checked for validity using a solver. This is done in two variants:

1. A **simple prompt** (no extra guidance) — used as the baseline.
2. A prompt that also includes **helper/domain instructions** for the task.

The actual purpose of RQ1.1 is to measure how much adding instructions to the prompt improves results over the plain baseline.

**Implementation differences**

1. **Parenthesis balancing.** The paper reports that LLM outputs sometimes contain imbalanced parentheses that require manual correction. Our implementation automatically detects and balances missing/mismatched parentheses in generated invariants, removing the need for manual fixes.
2. **Single generation pass for all *k* values.** The paper generates *k* = 10, 30, and 50 samples as three **separate** generation runs. Our implementation generates only **50 samples once** per problem and records how many problems are solved using just the first 10 or first 30 of those samples. This avoids three separate LLM calls per problem, saving API cost and time while still reporting results at *k* = 10, 30, and 50.

---

## RQ1.2 — Divide-and-Conquer (Pre / Transition / Post)

**What this RQ is about**

The paper tests whether a divide-and-conquer strategy helps: the LLM generates results separately for the **pre**, **transition**, and **post** conditions of a problem, and then is asked to combine these three partial results into a single, valid combined invariant.

**Implementation differences**

No major differences — our implementation follows the paper's method as described.

---

## RQ1.3 — Few-Shot Prompting with Similar Solved Problems

**What this RQ is about**

This RQ introduces a few-shot strategy. For a given problem **P**, we find another already-solved problem with a known valid invariant, using one of two similarity measures:

- **Semantic/textual similarity**, or
- **Syntactic similarity**, computed over Abstract Syntax Trees (ASTs) using All-Path Tree Edit Distance (APTED).

Given a similar problem **C** (with known correct invariant **I**), the LLM is prompted with **(P, C, I)** so it can use the pattern of a valid invariant for a similar problem to produce a valid invariant for **P**. Two separate few-shot runs are performed — one using the semantically similar problem, one using the syntactically similar problem — and the paper finds that syntactic similarity produces better results.

**Implementation differences**

1. **Semantic similarity model.** The paper uses an older semantic-text-similarity library. Our implementation instead uses the **Sentence Transformer `all-MiniLM-L6-v2`** model to compute semantic similarity.
2. **Search pool for similar problems.** The paper searches the **entire corpus of 429 verified problems** when looking for a similar solved problem. Our implementation only searches within the **current batch of problems being solved in that run** (e.g., if solving a group of 50 problems, the similar problem is chosen from within that same group of 50, excluding the problem itself).
3. **Parenthesis balancing and single-pass generation.** As in RQ1.1, our implementation automatically fixes unbalanced parentheses in generated samples and generates *k* = 50 samples once, rather than regenerating separately for *k* = 10, 30, and 50.

---

## RQ1.4 — Few-Shot with Negative Examples (EX_P, EX_N, EX_Mix)

**What this RQ is about**

This RQ extends RQ1.3 by also showing the LLM **incorrect** invariants for the similar problems, so it can learn what to avoid. For each problem, three prompting strategies are compared:

- **EX_P** — Positive-only: `(P, C1, I1, C2, I2)`, i.e., the problem plus two similar problems with their correct invariants.
- **EX_N** — Negative-only: `(P, C1, I1w & r1, C2, I2w & r2)`, i.e., the problem plus two similar problems' **incorrect** invariants (`I1w`, `I2w`) along with the **reasons they failed** (`r1`, `r2`).
- **EX_Mix** — Both: `(P, C1, I1, I1w & r1, C2, I2, I2w & r2)`, i.e., the problem plus both the correct and incorrect invariants (with failure reasons) for each similar problem.

Whenever an incorrect invariant is shown, the LLM is explicitly told it is incorrect and given the reason for its failure, so it can reason about what to avoid. RQ1.4 is run **only** using syntactically similar few-shot selection (based on the RQ1.3 finding that syntactic similarity works better).

**Implementation differences**

Same as RQ1.3 (search pool restricted to the current problem batch, automatic parenthesis balancing, single-pass *k* = 50 generation), **except** the semantic-similarity library difference does not apply here since RQ1.4 uses only syntactic similarity. No other major differences.

---

## RQ1.5 — Combining Domain Instructions with Positive Few-Shot Examples

**What this RQ is about**

RQ1.5 combines the two best-performing ingredients from earlier RQs: the **domain-knowledge instructions** from RQ1.1 and the **positive few-shot examples based on syntactic similarity** from RQ1.3.

**Implementation differences**

Since RQ1.5 is a combination of RQ1.1 and RQ1.3, the same implementation differences described for those two RQs apply here (automatic parenthesis balancing, single-pass *k* = 50 generation, restricted similarity search pool).

---

## RQ2.1 — Invariant Repair with Solver Error Messages

**What this RQ is about**

From this RQ onward, the paper shifts focus from pure invariant **generation** to generation **plus repair**. For each problem, two failed candidate invariants produced by the LLM are selected. The LLM is then given the problem, each failed invariant, and the solver's error message for that invariant, and is asked to repair each one. (The paper does not explain why it repairs exactly two failed invariants per problem — likely just to increase the number of repair attempts available for evaluation.)

**Implementation differences**

The main difference concerns "fake" successful repairs. The paper's authors manually reviewed cases where an invariant was rejected on the first try only due to **incorrect syntax or unbalanced parentheses** (not a genuine logical flaw), and which then appeared to be "successfully repaired." Because our implementation **sanitizes the LLM's output before the first validity check** (see RQ1.1), we never produce these syntax-only rejections in the first place, so this category of fake successful repairs does not occur in our results.

---

## RQ2.2 — Repair with Counterexamples

**What this RQ is about**

RQ2.2 builds on RQ2.1 by additionally providing the LLM with a **concrete counterexample** demonstrating the failure, in addition to the failed invariant and the solver's error message.

**Implementation differences**

1. **Multiple repair turns.** The paper reports results for a **single turn** of repair only. Our implementation runs repair for **3 turns**, and reports results at both **1 turn** and **3 turns**.
2. **Automatic oscillation detection.** For the multi-turn case, the paper's authors **manually inspected** repair trajectories to check for oscillation loops (the LLM cycling back to previously failed invariants). Our implementation performs this oscillation check **automatically**.

---

## Extended Implementation (Not Part of the Paper): CeGIS-Based Repair

This section describes additional work by our team, built on top of the paper's repair setup (RQ2.1/RQ2.2), aimed at improving repair performance further. It is **not** part of the original paper.

**Approach: Counterexample-Guided Inductive Synthesis (CeGIS)**

1. **Full failure history instead of last-failure-only.** In RQ2.1/RQ2.2, only the counterexample from the *most recent* failure was given to the LLM. Over multiple turns, the LLM would "forget" earlier failures and oscillate back to invariants it had already tried and failed. In this approach, we instead provide the **entire history of previous attempts and failures** in every prompt.
2. **Anti-overfitting instructions.** The LLM tended toward reactive point-patching — e.g., adding narrow conditions like `var != n` to patch a single counterexample rather than generalizing. We now include explicit prompt instructions telling the LLM to avoid overfitting to individual counterexamples and instead find the true, general algebraic boundary condition.
3. **Syntactic few-shot example during repair.** Since the RQ1 experiments showed that few-shot examples based on syntactic similarity improve generation results, we also provide **one positive syntactically-similar example** as a few-shot reference during the repair process itself.
4. **Tabu list to prevent infinite loops.** The paper notes that the LLM often falls into infinite loops, regenerating invariants it has already tried. We maintain a **Tabu List** of all previously tried invariants for a problem. If the LLM regenerates an invariant already in the list, we flag it, explicitly instruct the LLM (in the next prompt) not to repeat these previously-tried incorrect invariants, and resample **at a higher temperature** to encourage a genuinely new candidate.

**Open items / notes to address**

- **Growing prompt/history size.** Because the full attempt/failure history is appended to every prompt, the prompt size grows linearly with the number of repair turns. This could realistically hit the token limit for problems that require many repair attempts. We need a strategy for bounding or summarizing this history (e.g., truncation, summarization, or keeping only the most informative subset of past attempts) rather than appending every attempt indefinitely.
- **Handling repeated Tabu-List hits after retries.** Currently, if the LLM regenerates an invariant already in the Tabu List, we retry generation up to 2 times to get a novel candidate. If, after both retries, the LLM still produces an invariant already in the Tabu List, we currently **proceed anyway** by sending this repeated invariant to the solver. This doesn't seem ideal — a better approach might be to skip this invariant entirely and mark the problem as unsolved (or use some other fallback), but we don't yet have a concrete design for this. This needs further thought.