/*
 * Generated C verification file from: non-lin-ineq-3.desugared.sl
 * SMT-LIB Logic: NIA
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
  predicate pre_f(integer i, integer k) =
    ((i == 0) && (k == 0));

  predicate trans_f(integer i, integer k, integer i_next, integer k_next) =
    ((i < 1000) && (i_next == (i + 1)) && (k_next == (k + (i_next * i_next))));

  predicate post_f(integer i, integer k) =
    ((i < 1000) || (1000000 <= k));

  predicate inv_f(integer i, integer k) =
    ((i >= 0) && ((i * i) <= k));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long i, long long k) {
    return ((i == 0) && (k == 0));
}

static inline _Bool c_trans_f(long long i, long long k, long long i_next, long long k_next) {
    return ((i < 1000) && (i_next == (i + 1)) && (k_next == (k + (i_next * i_next))));
}

static inline _Bool c_post_f(long long i, long long k) {
    return ((i < 1000) || (1000000 <= k));
}

static inline _Bool c_inv_f(long long i, long long k) {
    return ((i >= 0) && ((i * i) <= k));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long k = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(i, k)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, k);
      @ loop assigns i, k;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long k_next = nondet_long();

        if (!c_trans_f(i, k, i_next, k_next)) break;

        // State updates
        i = i_next;
        k = k_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(i, k));
    /*@ assert post_f(i, k); */

    return 0;
}
