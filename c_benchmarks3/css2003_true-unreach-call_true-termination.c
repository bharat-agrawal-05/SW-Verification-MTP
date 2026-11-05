/*
 * Generated C verification file from: css2003_true-unreach-call_true-termination.sl
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
  // ACSL Logic Invariant Predicate (using mathematical integers)
  predicate InvF(integer i, integer j, integer k) =
    ((i <= 1000000) && (1 <= (i + k)) && ((i + k) <= 2) && (i >= 1));
  @*/

static inline _Bool c_InvF(long long i, long long j, long long k) {
    return ((i <= 1000000) && (1 <= (i + k)) && ((i + k) <= 2) && (i >= 1));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    i = 1;
    j = 1;
    k = nondet_long();
    if (!((0 <= k))) return 0;
    if (!((k <= 1))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, j, k);
      @ loop assigns i, j, k;
      @*/
    while ((i < 1000000)) {
        long long _old_k = k;
        i = (i + 1);
        j = (j + _old_k);
        k = (_old_k - 1);
    }

    // 4. Post-condition assertion
    assert((!((i < 1000000)) || ((1 <= (i + k)) && ((i + k) <= 2) && (i >= 1))));
    /*@ assert (!((i < 1000000)) || ((1 <= (i + k)) && ((i + k) <= 2) && (i >= 1))); */

    return 0;
}
