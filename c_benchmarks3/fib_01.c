/*
 * Generated C verification file from: fib_01.sl
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
    ((x >= 1) && (y >= 1) && (y == x));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return ((x >= 1) && (y >= 1) && (y == x));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 1;
    y = 1;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while (1) {
        long long _old_x = x;
        long long _old_y = y;
        x = (_old_x + _old_y);
        y = (_old_x + _old_y);
    }

    // 4. Post-condition assertion
    assert((y >= 1));
    /*@ assert (y >= 1); */

    return 0;
}
