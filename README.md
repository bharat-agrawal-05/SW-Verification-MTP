# LLM For Loop Invariant Generation and Fixing: Empirical Replication Framework

Implementation and empirical evaluation framework for the paper:  
**"LLM For Loop Invariant Generation and Fixing: How Far Are We?"**  
*(Mostafijur Rahman Akhond, Saikat Chakraborty, Gias Uddin, 2025)*

This repository implements the complete end-to-end empirical study for inductive loop invariant generation and fixing, configured for **`qwen3.8:27b`** (and compatible Qwen 27B / 32B models) on an **NVIDIA RTX A5000 (24GB VRAM)** machine or any remote/local server.

---

## Architecture Overview

```
mtp_agy/
├── config/
│   └── default_config.yaml         # Config for Ollama, vLLM, HuggingFace, sampling & Z3
├── core/
│   ├── problem.py                  # SyGuS / SMT2 Problem data structures (PreF, TransF, PostF)
│   ├── parser.py                   # S-expression parser & AST converter
│   ├── extractor.py                # LLM response extractor & parenthesis balancer
│   └── verifier.py                 # Z3 formal verifier (R1, R2, R3, counterexamples)
├── similarity/
│   ├── syntactic.py                # AST converter + APTED Tree Edit Distance (S_syntactic)
│   ├── semantic.py                 # Sentence Transformers embedding similarity (S_semantic)
│   └── example_finder.py           # Example retriever (EX_P, EX_N, EX_Mix)
├── prompts/
│   ├── templates.py                # Exact prompt templates (Figures 3, 4, 5, 8, 9, 10, 11)
│   └── builder.py                  # Prompt builders for RQ1.1 - RQ2.2
├── llm/
│   ├── base.py                     # Base LLM client interface
│   ├── ollama_client.py            # Ollama API client (default for qwen3.8:27b)
│   ├── openai_client.py            # OpenAI / vLLM / LMDeploy client
│   ├── hf_client.py                # Direct HuggingFace GPU client (4-bit/bfloat16 for RTX A5000)
│   └── mock_client.py              # Offline test client
├── experiments/
│   ├── rq1_1_instructions.py       # Baseline vs Guiding Instructions (Tables II & III)
│   ├── rq1_2_partitioning.py       # Divide-and-conquer problem partitioning (Figs 4-7)
│   ├── rq1_3_similarity.py         # S_semantic vs S_syntactic (Table V)
│   ├── rq1_4_example_types.py      # EX_P, EX_N, EX_Mix few-shot comparisons (Tables VI & VII)
│   ├── rq1_5_integrated.py         # Integrated Instructions + Few-Shot (Table VIII)
│   ├── rq2_1_repair_errors.py      # Invariant repair using error causes & details (Table IX)
│   ├── rq2_2_repair_counterexamples.py # Invariant repair using Z3 counterexample values (Table X, Fig 12)
│   └── runner.py                   # Master experiment runner & table formatter
├── benchmarks/                     # SyGuS/SMT2 loop invariant benchmark problems & loader
├── tests/                          # Full pytest unit & integration test suite
├── run_experiments.py              # Main CLI entrypoint
└── requirements.txt                # Python package dependencies
```

---

## Quickstart & Setup on NVIDIA RTX A5000 (24GB VRAM)

### 1. Install Dependencies
```bash
pip install -r requirements.txt
```

### 2. Choose Your LLM Backend

#### Option A: Ollama (Recommended)
Launch Ollama on your machine with your model:
```bash
ollama run qwen3.8:27b
# or: ollama run qwen2.5:32b
```
In `config/default_config.yaml`:
```yaml
llm:
  provider: "ollama"
  model: "qwen3.8:27b"
  ollama:
    host: "http://localhost:11434"
```

#### Option B: vLLM (High Throughput / Batching on A5000)
Launch vLLM with 4-bit quantization or bfloat16:
```bash
python3 -m vllm.entrypoints.openai.api_server \
    --model Qwen/Qwen2.5-32B-Instruct \
    --quantization bitsandbytes \
    --load-format bitsandbytes \
    --port 8000 \
    --max-model-len 4096
```
In `config/default_config.yaml`:
```yaml
llm:
  provider: "openai"
  model: "Qwen/Qwen2.5-32B-Instruct"
  openai:
    base_url: "http://localhost:8000/v1"
    api_key: "EMPTY"
```

#### Option C: Direct HuggingFace Transformers (Local Pipeline)
In `config/default_config.yaml`:
```yaml
llm:
  provider: "huggingface"
  huggingface:
    model_id: "Qwen/Qwen2.5-32B-Instruct"
    load_in_4bit: true # Fits comfortably within 24GB VRAM on RTX A5000
    torch_dtype: "bfloat16"
```

---

## Running the Experiments

You can run individual Research Questions or execute the entire benchmark evaluation:

### Run All Research Questions (End-to-End Replication)
```bash
python3 run_experiments.py --provider ollama --model qwen3.8:27b --rq all
```

### Run Specific Research Questions

#### RQ1.1: Guiding Instructions (Domain Knowledge) vs Baseline
```bash
python3 run_experiments.py --rq rq1_1 --k 50
```
*Outputs: Table II (% Followed template, % Syntactically correct) & Table III (% Solved at $k=10, 30, 50$).*

#### RQ1.2: Problem Partitioning & Divide-and-Conquer
```bash
python3 run_experiments.py --rq rq1_2
```
*Evaluates subproblems $P_{pre}$, $P_{trans}$, $P_{post}$ independently and tests combiner $P_{full}$ (Figures 4–7).*

#### RQ1.3: Few-Shot Prompting with Similarity Selection ($S_{semantic}$ vs $S_{syntactic}$)
```bash
python3 run_experiments.py --rq rq1_3 --k 50
```
*Computes AST Tree Edit Distance (APTED) for syntactic similarity and Sentence Transformers for semantic similarity (Table V).*

#### RQ1.4: Few-Shot Example Types ($EX_P$, $EX_N$, $EX_{Mix}$)
```bash
python3 run_experiments.py --rq rq1_4 --k 50
```
*Compares positive examples, negative counterexamples, and mixed few-shot prompting (Tables VI & VII).*

#### RQ1.5: Integrated Domain Instructions + Few-Shot Prompting
```bash
python3 run_experiments.py --rq rq1_5 --k 50
```
*Evaluates combined instructions with few-shot examples and monitors token limits (Table VIII).*

#### RQ2.1: Invariant Repair using Verifier Error Causes
```bash
python3 run_experiments.py --rq rq2_1
```
*Prompts LLM to repair failed invariants using verifier error causes and condition details (Table IX).*

#### RQ2.2: Invariant Repair using Concrete Counterexample Models
```bash
python3 run_experiments.py --rq rq2_2
```
*Prompts LLM to repair failed invariants with concrete Z3 variable assignments and tracks multi-turn trajectories & cycle detection (Table X & Figure 12).*

#### Beyond the Paper: Enhanced Multi-Turn CEGIS Framework
```bash
python3 run_experiments.py --rq cegis --subset-size 50
```
*Runs our Enhanced Counterexample-Guided Inductive Synthesis (CEGIS) loop combining Integrated Prompting with Cumulative Counterexample Memory and Generalization Directives (Table XI).*

---

## Beyond the Paper: What We Did Extra & Why It Is Better

The original paper discovered two separate insights:
1. **RQ1.5**: *Integrated Instructions + Few-Shot* achieved the highest initial generation accuracy (78%), but operated as independent zero-feedback sampling ($k=50$).
2. **RQ2.2**: *Iterative Invariant Repair* suffered from severe degradation (**only 16% repair success**), with models falling into **localized point-patch loops** (e.g., patching $n = -1$, then failing on $n = -2$, and oscillating in cycles without general inductive learning).

### What We Added (Enhanced CEGIS):
To bridge this gap, we implemented an advanced **Counterexample-Guided Inductive Synthesis (CEGIS) loop (`--rq cegis`)** that systematically fixes the 4 root causes of repair failure:

| Feature | Paper's RQ2 Setup | Our Enhanced CEGIS (`--rq cegis`) | Why It Is Better |
| :--- | :--- | :--- | :--- |
| **Feedback Memory** | Single transient counterexample (forgets previous failures). | **Cumulative Counterexample History**: Retains all attempted invariants & failed states across turns $1 \dots T$. | Prevents the model from creating fixes that re-break previous counterexample states. |
| **Overfitting Prevention** | None (Model tended to write `(or ... (= n -1))`). | **Anti-Overfitting Directive**: Explicit prompt rules forbidding point-wise disjunctions and requiring generalized algebraic bounds. | Forces the LLM to deduce the true inductive property (e.g. $i \ge 0 \land i \le n$) instead of reactive patches. |
| **Syntactic Context** | Stripped few-shot examples during repair. | **Exemplar Preservation**: Retains the top positive syntactic AST exemplar throughout all repair turns. | Ensures the model retains correct AST syntax and inductive formula shape. |
| **Cycle Prevention** | Unchecked (observed models repeating $I_1 \to I_2 \to I_3 \to I_1$). | **Tabu / Cycle Detection Engine**: Tracks formula history and prohibits re-generating identical hypotheses. | Eliminates wasted attempts on repetitive invariant loops. |

---

## Interactive Invariant Verification
You can directly test candidate invariants against loop specifications using Z3:
```bash
python3 run_experiments.py --verify-invariant "(define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024))))"
```

---

## Running the Unit & Integration Test Suite
```bash
pytest tests/ -v
```
Verifies:
- S-expression and SyGuS AST parsing
- Z3 formal verification ($R_1$, $R_2$, $R_3$) and counterexample generation
- APTED Tree Edit Distance AST calculation
- Semantic similarity embedding calculation
- LLM output extraction and parenthesis balancing heuristics
- Multi-turn repair trajectory tracking & CEGIS loop

