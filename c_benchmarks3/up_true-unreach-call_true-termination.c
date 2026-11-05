/*
 * Generated C verification file from: up_true-unreach-call_true-termination.sl
 * SMT-LIB Logic: LIA
 * Suitable for static analysis via Frama-C (WP and Eva).
 */

#include <assert.h>
#include <stdbool.h>

/*@ assigns \nothing; */
long long nondet_long(void);

/*@ assigns \nothing; */
_Bool nondet_bool(void);

/*@
  // ACSL Logic Predicates
  predicate PreF(integer n, integer i, integer k, integer j) =
    ((i == 0) && (k == 0) && (j == 0));

  predicate TransF(integer n, integer i, integer k, integer j, integer n_next, integer i_next, integer k_next, integer j_next) =
    (((i < n) && (i_next == (i + 1)) && (k_next == (k + 1)) && (n_next == n) && (j_next == j)) || ((i >= n) && (j < n) && (j_next == (j + 1)) && (k_next == (k - 1)) && (n_next == n) && (i_next == i)));

  predicate PostF(integer n, integer i, integer k, integer j) =
    (!(((i >= n) && (j < n))) || (k > 0));

  predicate InvF(integer n, integer i, integer k, integer j) =
    ((i >= j) && (k == (i - j)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long n, long long i, long long k, long long j) {
    return ((i == 0) && (k == 0) && (j == 0));
}

static inline _Bool c_TransF(long long n, long long i, long long k, long long j, long long n_next, long long i_next, long long k_next, long long j_next) {
    return (((i < n) && (i_next == (i + 1)) && (k_next == (k + 1)) && (n_next == n) && (j_next == j)) || ((i >= n) && (j < n) && (j_next == (j + 1)) && (k_next == (k - 1)) && (n_next == n) && (i_next == i)));
}

static inline _Bool c_PostF(long long n, long long i, long long k, long long j) {
    return (!(((i >= n) && (j < n))) || (k > 0));
}

static inline _Bool c_InvF(long long n, long long i, long long k, long long j) {
    return ((i >= j) && (k == (i - j)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long n = nondet_long();
    long long i = nondet_long();
    long long k = nondet_long();
    long long j = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(n, i, k, j)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(n, i, k, j);
      @ loop assigns n, i, k, j;
      @*/
    while (1) {
        long long n_next = nondet_long();
        long long i_next = nondet_long();
        long long k_next = nondet_long();
        long long j_next = nondet_long();

        if (!c_TransF(n, i, k, j, n_next, i_next, k_next, j_next)) break;

        // State updates
        n = n_next;
        i = i_next;
        k = k_next;
        j = j_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(n, i, k, j));
    /*@ assert PostF(n, i, k, j); */

    return 0;
}
