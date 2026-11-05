/*
 * Generated C verification file from: 65.c.sl
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
  predicate inv_f(integer x, integer y) =
    ((y >= 0) || (x <= 1));
  @*/

static inline _Bool c_inv_f(long long x, long long y) {
    return ((y >= 0) || (x <= 1));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 1;
    y = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y);
      @ loop assigns x, y;
      @*/
    while ((x <= 100)) {
        long long _old_x = x;
        x = (_old_x + 1);
        y = (100 - _old_x);
    }

    // 4. Post-condition assertion
    assert((y >= 0));
    /*@ assert (y >= 0); */

    return 0;
}
