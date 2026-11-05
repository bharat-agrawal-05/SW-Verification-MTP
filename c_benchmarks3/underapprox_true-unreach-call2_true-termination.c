/*
 * Generated C verification file from: underapprox_true-unreach-call2_true-termination.sl
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
  predicate inv_fun(integer x, integer y) =
    ((x <= 6) && (((x == 0) && (y == 1)) || ((x < 6) && ((y == 2) || (y == 4) || (y == 8) || (y == 16) || (y == 32) || (y == 64))) || (x == 6) || !(((y == 1) && !((x == 0))))));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return ((x <= 6) && (((x == 0) && (y == 1)) || ((x < 6) && ((y == 2) || (y == 4) || (y == 8) || (y == 16) || (y == 32) || (y == 64))) || (x == 6) || !(((y == 1) && !((x == 0))))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 0;
    y = 1;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while ((x < 6)) {
        x = (x + 1);
        y = (y * 2);
    }

    // 4. Post-condition assertion
    assert(((x < 6) || (x == 6)));
    /*@ assert ((x < 6) || (x == 6)); */

    return 0;
}
