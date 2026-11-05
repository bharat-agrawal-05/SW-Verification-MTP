/*
 * Generated C verification file from: fig9_vars.sl
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
  predicate inv_fun(integer x, integer y, integer z1, integer z2, integer z3) =
    ((0 <= y) && ((x + y + (z1 + z2 + z3)) <= ((2 * x) + y + (z1 + z2 + z3))));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long z1, long long z2, long long z3) {
    return ((0 <= y) && ((x + y + (z1 + z2 + z3)) <= ((2 * x) + y + (z1 + z2 + z3))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long z1;
    long long z2;
    long long z3;

    // 2. Pre-condition initialization
    x = 0;
    y = 0;
    z1 = nondet_long();
    z2 = nondet_long();
    z3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, z1, z2, z3);
      @ loop assigns y;
      @*/
    while ((0 <= y)) {
        y = (x + y);
    }

    // 4. Post-condition assertion
    assert((y >= 0));
    /*@ assert (y >= 0); */

    return 0;
}
