# SyGuS to Minimal C Converter for Frama-C Static Analysis

This tool parses SMT-LIB / SyGuS format invariant synthesis benchmark files (`.sl`) and converts them into minimal, self-contained C code with ACSL (ANSI/ISO C Specification Language) annotations. The generated C code can be directly passed to static analysis and formal verification tools such as **Frama-C 33.0 Arsenic (WP and Eva)**, **CBMC**, and standard C compilers.

---

## 1. Directory Structure

```
converter/
├── README.md         # Detailed documentation and usage instructions (this file)
├── convert.py        # Main CLI entry point with modular path resolution
├── sl_parser.py      # Lexer and parser for SMT-LIB S-expressions and SyGuS commands
├── ast_nodes.py      # Abstract Syntax Tree (AST) node definitions
├── c_generator.py    # Translates AST into valid C99 code & ACSL predicates
└── utils.py          # Identifier sanitization, C filename creation, and path resolution
```

When run on a directory of `.sl` files (e.g. `../benchmarks3`), the resulting C files are saved into a folder named:
```
c_{name_of_source_sl_file_folder}
```
For example, converting `benchmarks3` produces `c_benchmarks3/` alongside the source directory.

---

## 2. Benchmark Templates Supported

The converter supports all 461 benchmark files in `benchmarks3` across both major templates:

### A. Standard Invariant Synthesis Benchmarks (416 files)
- **Commands**:
  - `(synth-inv <inv_fun> (<params>))`
  - `(define-fun <pre_fun> (<params>) Bool <expr>)`
  - `(define-fun <trans_fun> (<params> <params_primed>) Bool <expr>)`
  - `(define-fun <post_fun> (<params>) Bool <expr>)`
  - `(define-fun <inv_fun> (<params>) Bool <expr>)` (verified inductive invariant)
  - `(inv-constraint <inv_fun> <pre_fun> <trans_fun> <post_fun>)`

### B. Reactive / Transition System Benchmarks (45 files)
- **Commands**:
  - Sub-node initialization & transition definitions: `__node_init_<Node>_0`, `__node_trans_<Node>_0`
  - Top-level `init`, `trans`, `prop`, `str_invariant`
  - `(inv-constraint str_invariant init trans prop)`

---

## 3. Translation Architecture

The converter uses a **dual-strategy generation** approach. Each `.sl` file is analysed to determine which strategy produces the best C representation.

### Strategy 1: Natural Imperative Loop (225 files)

Used when the benchmark has a single active loop branch, no array state variables, no reactive helper nodes, and all guards/updates reference only base variables. This produces clean, idiomatic C that Frama-C analyses most effectively.

```c
#include <assert.h>
#include <stdbool.h>

/*@ assigns \nothing; */
long long nondet_long(void);

/*@
  predicate inv_f(integer x, integer y) =
    ((y == 0) && (x == 1)) || ((y > 0) && (x >= y));
  @*/

static inline _Bool c_inv_f(long long x, long long y) {
    return ((y == 0) && (x == 1)) || ((y > 0) && (x >= y));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 1;
    y = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y);
      @ loop assigns x, y;
      @*/
    while (y < 100000) {
        long long _old_y = y;
        x = x + _old_y;
        y = _old_y + 1;
    }

    // 4. Post-condition assertion
    assert(x >= y);
    /*@ assert (x >= y); */

    return 0;
}
```

**Key properties:**
- Variables are initialized to their concrete pre-condition values (no `assume`).
- The loop guard comes from the transition relation's inequality constraints.
- Updates are extracted from the primed-variable equalities (`x! = x + y`).
- Temporary `_old_*` variables handle simultaneous updates when needed.

### Strategy 2: Relational Loop Harness (236 files)

Used as a fallback for reactive/Lustre nodes, multi-branch transitions, array-typed state, and any case where the natural loop extraction validation fails.

```c
#include <assert.h>
#include <stdbool.h>

/*@ assigns \nothing; */
long long nondet_long(void);

/*@ assigns \nothing; */
_Bool nondet_bool(void);

/*@
  predicate pre_f(integer x, integer y) = ...;
  predicate trans_f(integer x, integer y, integer x!, integer y!) = ...;
  predicate post_f(integer x, integer y) = ...;
  predicate inv_f(integer x, integer y) = ...;
  @*/

static inline _Bool c_pre_f(long long x, long long y) { return ...; }
static inline _Bool c_trans_f(long long x, long long y,
                               long long x_next, long long y_next) { return ...; }
static inline _Bool c_post_f(long long x, long long y) { return ...; }

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y);
      @ loop assigns x, y;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_trans_f(x, y, x_next, y_next)) break;

        // State updates
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(x, y));
    /*@ assert post_f(x, y); */

    return 0;
}
```

**Key properties:**
- No `/*@ assume ... */` annotations (invalid in ACSL function bodies).
- Pre-condition is enforced via `if (!c_pre_f(...)) return 0;` — a safe C guard.
- Transition is enforced via `if (!c_trans_f(...)) break;` inside the loop.
- Functions whose bodies contain quantifiers (`\forall`, `\exists`) are emitted only as ACSL predicates, not as C helpers.

### Validation Gate: `is_valid_natural_loop()`

Before emitting a natural loop, the converter validates the extraction result:
1. **No reactive helper functions** (`other_funs` must be empty).
2. **No array-typed state variables** (scalar assignments only).
3. **No primed variables** (`*!` or `*_next`) remaining in guards/updates/inits.
4. **No `store` operations** in any expressions.
5. **All referenced variables** must be in the base variable set.

If any check fails, the file cleanly falls back to the relational harness.

---

## 4. Design Decisions for Frama-C Compatibility

### 64-bit Integer Types
- **C variables**: `long long` (64-bit) instead of `int` (32-bit). Many benchmarks have variables that exceed `INT_MAX` (e.g., `1.c.sl` where `x` reaches ~5 billion).
- **ACSL predicates**: `integer` (mathematical unbounded integers in ℤ), preventing any logic-level overflow.

### No `/*@ assume ... */` Annotations
ACSL has no `assume` annotation for function bodies. The converter uses pure C guards:
- `if (!c_pre_f(...)) return 0;` — pre-condition filter
- `if (!c_trans_f(...)) break;` — transition filter inside the loop

### Dual Assertions
Both `assert(...)` (for Eva / runtime analysis) and `/*@ assert ...; */` (for WP / deductive verification) are emitted. When the post-condition contains quantifiers, only the ACSL assertion is emitted (since quantified expressions cannot be evaluated as C).

---

## 5. Operator Mappings

| SMT-LIB | C / ACSL Equivalent |
|---|---|
| `(and a b ...)` | `(a && b && ...)` |
| `(or a b ...)` | `(a \|\| b \|\| ...)` |
| `(not a)` | `!a` |
| `(=> a b)` | `(!a \|\| b)` in C / `(a ==> b)` in ACSL |
| `(= a b)` | `(a == b)` |
| `<=, >=, <, >` | `<=, >=, <, >` |
| `+, -, *, /, div, mod` | `+, -, *, /, /, %` |
| `(ite c t e)` | `(c ? t : e)` |
| `(let ((x e)) body)` | Inlined into pure expression |
| `(select a i)` | `a[i]` |
| `(= a! (store a i v))` | `(a_next[i] == v && \forall integer _k; _k != i ==> a_next[_k] == a[_k])` |
| `(forall ((j Int)) ...)` | `(\forall integer j; ...)` |

---

## 6. Usage Instructions

### Running from the `converter` directory
The script is modular and accepts paths relative to its location:

```bash
cd converter

# 1. Convert the entire benchmarks3 directory
python3 convert.py --sl-dir ../benchmarks3

# 2. Output is automatically written to ../c_benchmarks3
```

### Specifying Custom Output Directory
```bash
python3 convert.py --sl-dir ../benchmarks3 --out-dir /path/to/custom_dir
```

### Converting a Single File
```bash
python3 convert.py --file ../benchmarks3/1.c.sl
```

### Command Line Arguments
- `--sl-dir PATH`: Directory containing `.sl` files (default: `../benchmarks3`).
- `--out-dir PATH`: Directory where `.c` files will be saved (default: `../c_{source_folder_name}`).
- `--file PATH`: Convert a specific `.sl` file.
- `--verbose`: Print detailed progress for each file.

---

## 7. Running Static Analysis with Frama-C

### Using Frama-C WP (Weakest Precondition / Deductive Verification)
To prove the loop invariant and postcondition:
```bash
frama-c -wp -wp-rte c_benchmarks3/1.c
```
To verify with Alt-Ergo or Z3:
```bash
frama-c -wp -wp-prover alt-ergo,z3 c_benchmarks3/1.c
```

### Using Frama-C Eva (Value Analysis / Abstract Interpretation)
To analyse reachable values and assertion validation:
```bash
frama-c -eva c_benchmarks3/1.c
```

### Syntax and Compilation Check with GCC or Clang
The generated C files are valid C99 code:
```bash
clang -fsyntax-only -std=c99 c_benchmarks3/1.c
gcc -fsyntax-only -std=c99 c_benchmarks3/1.c
```
