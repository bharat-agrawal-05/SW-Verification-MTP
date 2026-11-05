/*
 * Generated C verification file from: anfp.sl
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
    (((y < 1000)) ? ((x == (1 + (y * (y - 1) * 0.5)))) : (((y + 1) <= x)));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return (((y < 1000)) ? ((x == (1 + (y * (y - 1) * 0.5)))) : (((y + 1) <= x)));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 1;
    y = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while ((y < 1000)) {
        long long _old_y = y;
        x = (x + _old_y);
        y = (_old_y + 1);
    }

    // 4. Post-condition assertion
    assert(!(((y >= 1000) && (x < y))));
    /*@ assert !(((y >= 1000) && (x < y))); */

    return 0;
}
