/*
 * Generated C verification file from: 30.c.sl
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
  predicate inv_f(integer x) =
    (!((x == x)) || !((!((x > 0)) && !((x == 0)))));
  @*/

static inline _Bool c_inv_f(long long x) {
    return (!((x == x)) || !((!((x > 0)) && !((x == 0)))));
}

int main(void) {
    // 1. Variable declarations
    long long x;

    // 2. Pre-condition initialization
    x = 100;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x);
      @ loop assigns x;
      @*/
    while ((x > 0)) {
        x = (x - 1);
    }

    // 4. Post-condition assertion
    assert((x == 0));
    /*@ assert (x == 0); */

    return 0;
}
