/*
 * Generated C verification file from: terminator_03_true-unreach-call_true-termination.sl
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
    (((x <= 99) && (y < 1000001)) || (x >= 100));
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return (((x <= 99) && (y < 1000001)) || (x >= 100));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    if (!((y <= 1000000))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x;
      @*/
    while ((x < 100) && (y > 0)) {
        x = (x + y);
    }

    // 4. Post-condition assertion
    assert((!(((y <= 0) || ((y > 0) && (x >= 100)))) || ((y <= 0) || ((y > 0) && (x >= 100)))));
    /*@ assert (((y <= 0) || ((y > 0) && (x >= 100))) ==> ((y <= 0) || ((y > 0) && (x >= 100)))); */

    return 0;
}
