/*
 * Generated C verification file from: vardep.sl
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
  predicate inv_fun(integer x, integer y, integer z) =
    ((x >= 0) && (y >= 0) && (z >= 0) && ((x == 0) || (y > x) || ((y - x) == 2) || (z > x) || ((z - x) == 3)));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long z) {
    return ((x >= 0) && (y >= 0) && (z >= 0) && ((x == 0) || (y > x) || ((y - x) == 2) || (z > x) || ((z - x) == 3)));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long z;

    // 2. Pre-condition initialization
    x = 0;
    y = 0;
    z = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, z);
      @ loop assigns x, y, z;
      @*/
    while (1) {
        x = (x + 1);
        y = (y + 2);
        z = (z + 3);
    }

    // 4. Post-condition assertion
    assert(((x >= 0) && (y >= 0) && (z >= 0)));
    /*@ assert ((x >= 0) && (y >= 0) && (z >= 0)); */

    return 0;
}
