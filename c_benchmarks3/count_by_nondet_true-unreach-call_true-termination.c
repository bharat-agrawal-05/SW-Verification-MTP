/*
 * Generated C verification file from: count_by_nondet_true-unreach-call_true-termination.sl
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
  predicate PreF(integer i, integer k, integer j) =
    ((i == 0) && (k == 0));

  predicate TransF(integer i, integer k, integer j, integer i_next, integer k_next, integer j_next) =
    ((i < 1000000) && (1 <= j_next) && (j_next < 1000000) && (i_next == (i + j_next)) && (k_next == (k + 1)));

  predicate PostF(integer i, integer k, integer j) =
    ((i < 1000000) || (k <= 1000000));

  predicate InvF(integer i, integer k, integer j) =
    ((k <= 1000000) && (i >= k));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long i, long long k, long long j) {
    return ((i == 0) && (k == 0));
}

static inline _Bool c_TransF(long long i, long long k, long long j, long long i_next, long long k_next, long long j_next) {
    return ((i < 1000000) && (1 <= j_next) && (j_next < 1000000) && (i_next == (i + j_next)) && (k_next == (k + 1)));
}

static inline _Bool c_PostF(long long i, long long k, long long j) {
    return ((i < 1000000) || (k <= 1000000));
}

static inline _Bool c_InvF(long long i, long long k, long long j) {
    return ((k <= 1000000) && (i >= k));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long k = nondet_long();
    long long j = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(i, k, j)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, k, j);
      @ loop assigns i, k, j;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long k_next = nondet_long();
        long long j_next = nondet_long();

        if (!c_TransF(i, k, j, i_next, k_next, j_next)) break;

        // State updates
        i = i_next;
        k = k_next;
        j = j_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(i, k, j));
    /*@ assert PostF(i, k, j); */

    return 0;
}
