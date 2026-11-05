/*
 * Generated C verification file from: seq_true-unreach-call_true-termination.sl
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
  predicate PreF(integer n0, integer n1, integer i0, integer k, integer i1, integer j1) =
    (((0 - 1000000) <= n0) && (n0 < 1000000) && ((0 - 1000000) <= n1) && (n1 < 1000000) && (i1 == 0) && (j1 == 0) && (i0 == 0) && (k == 0));

  predicate TransF(integer n0, integer n1, integer i0, integer k, integer i1, integer j1, integer n0_next, integer n1_next, integer i0_next, integer k_next, integer i1_next, integer j1_next) =
    (((i0 < n0) && (i0_next == (i0 + 1)) && (k_next == (k + 1)) && (n0_next == n0) && (n1_next == n1) && (i1_next == i1) && (j1_next == j1)) || ((i0 >= n0) && (i1 < n1) && (i1_next == (i1 + 1)) && (k_next == (k + 1)) && (n0_next == n0) && (n1_next == n1) && (i0_next == i0) && (j1_next == j1)) || ((i0 >= n0) && (i1 >= n1) && (j1 < (n0 + n1)) && (j1_next == (j1 + 1)) && (k_next == (k - 1)) && (n0_next == n0) && (n1_next == n1) && (i0_next == i0) && (i1_next == i1)));

  predicate PostF(integer n0, integer n1, integer i0, integer k, integer i1, integer j1) =
    (!(((i0 >= n0) && (i1 >= n1) && (j1 < (n0 + n1)))) || (k > 0));

  predicate InvF(integer n0, integer n1, integer i0, integer k, integer i1, integer j1) =
    (j1 >= ((i0 + i1) - k));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long n0, long long n1, long long i0, long long k, long long i1, long long j1) {
    return (((0 - 1000000) <= n0) && (n0 < 1000000) && ((0 - 1000000) <= n1) && (n1 < 1000000) && (i1 == 0) && (j1 == 0) && (i0 == 0) && (k == 0));
}

static inline _Bool c_TransF(long long n0, long long n1, long long i0, long long k, long long i1, long long j1, long long n0_next, long long n1_next, long long i0_next, long long k_next, long long i1_next, long long j1_next) {
    return (((i0 < n0) && (i0_next == (i0 + 1)) && (k_next == (k + 1)) && (n0_next == n0) && (n1_next == n1) && (i1_next == i1) && (j1_next == j1)) || ((i0 >= n0) && (i1 < n1) && (i1_next == (i1 + 1)) && (k_next == (k + 1)) && (n0_next == n0) && (n1_next == n1) && (i0_next == i0) && (j1_next == j1)) || ((i0 >= n0) && (i1 >= n1) && (j1 < (n0 + n1)) && (j1_next == (j1 + 1)) && (k_next == (k - 1)) && (n0_next == n0) && (n1_next == n1) && (i0_next == i0) && (i1_next == i1)));
}

static inline _Bool c_PostF(long long n0, long long n1, long long i0, long long k, long long i1, long long j1) {
    return (!(((i0 >= n0) && (i1 >= n1) && (j1 < (n0 + n1)))) || (k > 0));
}

static inline _Bool c_InvF(long long n0, long long n1, long long i0, long long k, long long i1, long long j1) {
    return (j1 >= ((i0 + i1) - k));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long n0 = nondet_long();
    long long n1 = nondet_long();
    long long i0 = nondet_long();
    long long k = nondet_long();
    long long i1 = nondet_long();
    long long j1 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(n0, n1, i0, k, i1, j1)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(n0, n1, i0, k, i1, j1);
      @ loop assigns n0, n1, i0, k, i1, j1;
      @*/
    while (1) {
        long long n0_next = nondet_long();
        long long n1_next = nondet_long();
        long long i0_next = nondet_long();
        long long k_next = nondet_long();
        long long i1_next = nondet_long();
        long long j1_next = nondet_long();

        if (!c_TransF(n0, n1, i0, k, i1, j1, n0_next, n1_next, i0_next, k_next, i1_next, j1_next)) break;

        // State updates
        n0 = n0_next;
        n1 = n1_next;
        i0 = i0_next;
        k = k_next;
        i1 = i1_next;
        j1 = j1_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(n0, n1, i0, k, i1, j1));
    /*@ assert PostF(n0, n1, i0, k, i1, j1); */

    return 0;
}
