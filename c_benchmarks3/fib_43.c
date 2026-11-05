/*
 * Generated C verification file from: fib_43.sl
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
  predicate inv_fun(integer i, integer t, integer x, integer y) =
    ((y >= t) && (i == 0));
  @*/

static inline _Bool c_inv_fun(long long i, long long t, long long x, long long y) {
    return ((y >= t) && (i == 0));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long t;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    i = 0;
    t = y;
    x = nondet_long();
    y = nondet_long();
    if (!(!((x == y)))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, t, x, y);
      @ loop assigns y;
      @*/
    while ((x > 0)) {
        y = (x + y);
    }

    // 4. Post-condition assertion
    assert((y >= t));
    /*@ assert (y >= t); */

    return 0;
}
