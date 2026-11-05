/*
 * Generated C verification file from: treax1.sl
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
    (1 <= x);
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return (1 <= x);
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
      @ loop assigns x;
      @*/
    while ((x < y)) {
        x = (x + x);
    }

    // 4. Post-condition assertion
    assert((!((x >= y)) || (x >= 1)));
    /*@ assert (!((x >= y)) || (x >= 1)); */

    return 0;
}
