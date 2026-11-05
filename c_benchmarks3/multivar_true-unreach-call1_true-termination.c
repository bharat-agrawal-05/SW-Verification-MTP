/*
 * Generated C verification file from: multivar_true-unreach-call1_true-termination.sl
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
    (x == y);
  @*/

static inline _Bool c_inv_fun(long long x, long long y) {
    return (x == y);
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = x;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while ((x < 1024)) {
        x = (x + 1);
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert(((x < 1024) || (x == y)));
    /*@ assert ((x < 1024) || (x == y)); */

    return 0;
}
