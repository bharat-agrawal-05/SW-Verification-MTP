/*
 * Generated C verification file from: countud.sl
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
  predicate inv_fun(integer x, integer y, integer n) =
    ((y >= 0) && (y <= n) && ((x + y) == n));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long n) {
    return ((y >= 0) && (y <= n) && ((x + y) == n));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long n;

    // 2. Pre-condition initialization
    x = n;
    y = 0;
    n = nondet_long();
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, n);
      @ loop assigns y, x;
      @*/
    while ((x > 0)) {
        y = (y + 1);
        x = (x - 1);
    }

    // 4. Post-condition assertion
    assert(((x > 0) || (y == n)));
    /*@ assert ((x > 0) || (y == n)); */

    return 0;
}
