/*
 * Generated C verification file from: ex14_simp.sl
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
    (x >= 1);
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long n) {
    return (x >= 1);
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long n;

    // 2. Pre-condition initialization
    x = 1;
    y = nondet_long();
    n = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, n);
      @ loop assigns y, x;
      @*/
    while ((x <= n)) {
        long long _old_x = x;
        y = (n - _old_x);
        x = (_old_x + 1);
    }

    // 4. Post-condition assertion
    assert(!((((x <= n) && (y == (n - x))) && ((y >= n) || (0 > y)))));
    /*@ assert !((((x <= n) && (y == (n - x))) && ((y >= n) || (0 > y)))); */

    return 0;
}
