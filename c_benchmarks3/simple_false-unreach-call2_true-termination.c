/*
 * Generated C verification file from: simple_false-unreach-call2_true-termination.sl
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
  predicate InvF(integer x) =
    \false;
  @*/

static inline _Bool c_InvF(long long x) {
    return false;
}

int main(void) {
    // 1. Variable declarations
    long long x;

    // 2. Pre-condition initialization
    x = nondet_long();
    if (!((x >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(x);
      @ loop assigns x;
      @*/
    while ((x < 268435455)) {
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert(((x < 268435455) || (x > 268435455)));
    /*@ assert ((x < 268435455) || (x > 268435455)); */

    return 0;
}
