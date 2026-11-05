/*
 * Generated C verification file from: 99.c.sl
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
  predicate inv_f(integer n, integer x, integer y) =
    ((x + y) == n);
  @*/

static inline _Bool c_inv_f(long long n, long long x, long long y) {
    return ((x + y) == n);
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    n = nondet_long();
    x = n;
    y = 0;
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, x, y);
      @ loop assigns x, y;
      @*/
    while ((x > 0)) {
        x = (x - 1);
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert((n == (x + y)));
    /*@ assert (n == (x + y)); */

    return 0;
}
