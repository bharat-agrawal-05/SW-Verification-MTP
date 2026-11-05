/*
 * Generated C verification file from: anfp-new.sl
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
    ((0 <= y) && (1 <= x) && ((y - x) <= 0));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return ((0 <= y) && (1 <= x) && ((y - x) <= 0));
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
    while ((y < 100000)) {
        long long _old_y = y;
        x = (x + _old_y);
        y = (_old_y + 1);
    }

    // 4. Post-condition assertion
    assert(!(((y >= 100000) && (x < y))));
    /*@ assert !(((y >= 100000) && (x < y))); */

    return 0;
}
