/*
 * Generated C verification file from: count_by_1_variant_true-unreach-call_true-termination.sl
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
  predicate InvF(integer i) =
    ((0 <= i) && (i <= 1000000));
  @*/

static inline _Bool c_InvF(long long i) {
    return ((0 <= i) && (i <= 1000000));
}

int main(void) {
    // 1. Variable declarations
    long long i;

    // 2. Pre-condition initialization
    i = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i);
      @ loop assigns i;
      @*/
    while (!((i == 1000000))) {
        i = (i + 1);
    }

    // 4. Post-condition assertion
    assert((!((i == 1000000)) || (i <= 1000000)));
    /*@ assert (!((i == 1000000)) || (i <= 1000000)); */

    return 0;
}
