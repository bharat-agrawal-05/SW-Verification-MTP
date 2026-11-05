/*
 * Generated C verification file from: fib_28.sl
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
  predicate inv_fun(integer n, integer x, integer y) =
    ((x == y) || ((x < n) && (y < n) && ((x + y) == (2 * n))));
  @*/

static inline _Bool c_inv_fun(long long n, long long x, long long y) {
    return ((x == y) || ((x < n) && (y < n) && ((x + y) == (2 * n))));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    n = 0;
    x = y;
    y = nondet_long();
    if (!((y >= 0))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(n, x, y);
      @ loop assigns x, y;
      @*/
    while (!((x == n))) {
        x = (x - 1);
        y = (y - 1);
    }

    // 4. Post-condition assertion
    assert((!((x == n)) || (y == n)));
    /*@ assert ((x == n) ==> (y == n)); */

    return 0;
}
