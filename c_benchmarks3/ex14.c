/*
 * Generated C verification file from: ex14.sl
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
    (x >= 1);
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return (x >= 1);
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
      @ loop invariant inv_fun(x, y);
      @ loop assigns y, x;
      @*/
    while ((x <= 10)) {
        long long _old_x = x;
        y = (10 - _old_x);
        x = (_old_x + 1);
    }

    // 4. Post-condition assertion
    assert(!((((x <= 10) && (y == (10 - x))) && ((y >= 10) || (0 > y)))));
    /*@ assert !((((x <= 10) && (y == (10 - x))) && ((y >= 10) || (0 > y)))); */

    return 0;
}
