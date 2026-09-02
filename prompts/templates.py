"""Prompt Templates exactly as specified in the paper."""

# RQ1.1 Figure 3: Guiding Instructions (GIs) Prompt Template
PROMPT_RQ1_1_WITH_INSTRUCTIONS = """You are a helpful AI assistant who can generate invariants from program specifications. You have to find a loop invariant, which can be used to verify several programming properties. SMT is a low-level program specification. For the given problem, find the necessary loop invariant that will be verified using the Hoare triple logics.
You have to follow the instructions -
1. Make a note of the conditions of the problem.
2. Analyze the problem and make a note of the conditions.
3. Find the invariant that is true for -
3.1 Before the loop execution (pre-f)
3.2 In every iteration of the loop and (trans-f)
3.3 After the loop termination (post-f).
4. Output the inductive loop invariants in the code block. For example: ``` example loop invariant ```
Additional Rules:
**Do not use any variables or functions, that are not declared in the problem. **
**Do not make any assumptions about functions whose definitions are not given. **
**All undefined variables contain garbage values. Do not use variables that have garbage values. **
**Variables that are not explicitly initialized, could have garbage values. Do not make any assumptions about such values. **
**Do not use non-deterministic function calls. **
Now create the invariant for the following program:
```
{problem_smt}
```
Generate the invariant only, no other text or explanation is desired"""

# RQ1.1 Baseline Prompt (Without Instructions)
PROMPT_RQ1_1_WITHOUT_INSTRUCTIONS = """You are an AI assistant who can generate loop invariants for SMT program specifications.
Synthesize an inductive loop invariant for the following program:
```
{problem_smt}
```
Generate the invariant only, surrounded by ``` and ```. No other text or explanation is desired."""

# RQ1.2 Figure 4: Partial Invariant Synthesis Prompt Template
PROMPT_RQ1_2_PARTIAL = """You are an expert invariant synthesizer, find an inductive loop invariant for the following problem in sygus format
```
{partial_sygus}
```
Your task is to find an extensive invariant to satisfy the condition ``` {condition_clause} ``` using the lig-verify verifier. Start the invariant with ``` (define-fun InvF ({vars_sig}) Bool (``` and end with```))```.
Surround the invariant with <code> and </code> only. You don't need to explain the invariant, just synthesize it."""

# RQ1.2 Figure 5: Combiner Prompt Template (P_full)
PROMPT_RQ1_2_COMBINER = """You are an expert invariant synthesizer, for the following problem in SyGus format 
```
{sygus_problem}
```

For condition: ``` pre-f implies inv-f ``` 
you generated following invariants : 
{pre_invariants_block}

For condition : ``` ( trans-f and inv-f ) implies inv-f! ``` 
you generated following invariants : 
{trans_invariants_block}

For condition : ``` inv-f implies post-f ``` 
you generated following invariants : 
{post_invariants_block}

Now combine the correct invariants to generate a minimal inductive loop invariant that simultaneously satisfy all the three conditions.
Surround the invariant with <code> and </code> only. You don't need to explain the invariant, just synthesize it."""

# RQ1.3 & RQ1.4 Figure 8: Few-Shot Invariant Generation Prompt Template
PROMPT_FEW_SHOT = """A loop invariant synthesis problem is given below.
```
{problem_smt}
```
Synthesize a necessary and sufficient invariant that satisfies all 4 verification constraints. Start the invariant with "inv_fun ({var_names}) Bool (" and end with "))"
Surround the invariant with <code> and </code> only.
You don't need to explain the invariant, just synthesize it. Follow the example solution formats from the following to generate your output

####
Here are some examples
{few_shot_examples}"""

# RQ1.5 Figure 9: Integrated Instructions + Few-Shot Prompt Template
PROMPT_RQ1_5_INTEGRATED = """You are a helpful AI assistant who can generate invariants from program specifications. You have to find a loop invariant, which can be used to verify several programming properties. SMT is a low-level program specification. For the given problem, find the necessary loop invariant that will be verified using the Hoare triple logics.
You have to follow the instructions -
1. Make a note of the conditions of the problem.
2. Analyze the problem and make a note of the conditions.
3. Find the invariant that is true for -
3.1 Before the loop execution (pre-f)
3.2 In every iteration of the loop and (trans-f)
3.3 After the loop termination (post-f).
4. Output the inductive loop invariants in the code block. For example: ``` example loop invariant ```
Additional Rules:
**Do not use any variables or functions, that are not declared in the problem. **
**Do not make any assumptions about functions whose definitions are not given. **
**All undefined variables contain garbage values. Do not use variables that have garbage values. **
**Variables that are not explicitly initialized, could have garbage values. Do not make any assumptions about such values. **
**Do not use non-deterministic function calls. **
Now create the invariant for the following program:
```
{problem_smt}
```
Generate the invariant only, no other text or explanation is desired. Follow the example solution from the following to generate your output

####
Here are some examples
{few_shot_examples}"""

# RQ2.1 Figure 10: Invariant Repair with Error Cause and Details Prompt Template
PROMPT_RQ2_1_REPAIR_ERROR = """For ({problem_name}) You generated the loop invariant {inv} .
But it couldn't verify the problem -
Cause of error : ``` {error_cause} ```
Error details: ``` {error_details} ```
Now repair the invariant, considering the errors in the previous solution.
Surround the repaired invariant with <code> and </code> only."""

# RQ2.2 Figure 11: Invariant Repair with Counterexample Values Prompt Template
PROMPT_RQ2_2_REPAIR_COUNTEREXAMPLE = """For ({problem_name}) You generated loop invariant {inv}
Failed to satisfy the "condition":"{error_details}"
For the values {counterexample_values}
Now repair the invariant, considering the errors in the previous solution.
Surround the repaired invariant with <code> and </code> only."""

# Enhanced CEGIS (Beyond Paper): Integrated Instructions + Few-Shot + Cumulative Counterexample Feedback
PROMPT_ENHANCED_CEGIS_FEEDBACK = """You are an expert formal verification AI assistant synthesizing an inductive loop invariant.

Target Program Specification:
```
{problem_smt}
```

Reference Working Example:
{reference_example}

### Feedback on Previous Synthesis Attempts (Turn {turn}):
{attempt_history}

### Generalization & Inductive Constraints (CRITICAL):
1. **DO NOT OVERFIT**: Do NOT create point-wise disjunctions or hardcoded equality checks for specific counterexample numbers (e.g., do NOT write `(or ... (= n -1))` or `(or ... (= n -2))`).
2. **GENERALIZE**: Deduce the general algebraic inequality or equation (e.g. bounds like `>= 0`, `<= n`, or linear relations) that naturally holds for ALL loop iterations while excluding the counterexample states above.
3. **INDUCTIVENESS**: The invariant must hold at loop entry (PreF => InvF), be preserved by the loop body ((InvF and TransF) => InvF!), and guarantee the postcondition (InvF => PostF).
4. **AVOID PREVIOUS MISTAKES**: Do NOT re-submit any previously attempted invariant.

Output the newly refined inductive invariant starting with `(define-fun InvF ({vars_sig}) Bool ` and surrounded by <code> and </code> only."""
