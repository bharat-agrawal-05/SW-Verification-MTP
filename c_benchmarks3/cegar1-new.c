/*
 * Generated C verification file from: cegar1-new.sl
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
    ((x >= 0) && (y >= 0) && (x <= (10 + y)) && (y <= (10 + x)) && !(((x == 20) && (y == 0))));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return ((x >= 0) && (y >= 0) && (x <= (10 + y)) && (y <= (10 + x)) && !(((x == 20) && (y == 0))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    if (!((x >= 0))) return 0;
    if (!((x <= 10))) return 0;
    if (!((y <= 10))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while (1) {
        x = (x + 10);
        y = (y + 10);
    }

    // 4. Post-condition assertion
    assert(!(((x == 20) && (y == 0))));
    /*@ assert !(((x == 20) && (y == 0))); */

    return 0;
}
