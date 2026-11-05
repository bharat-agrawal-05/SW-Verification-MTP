/*
 * Generated C verification file from: 103.c.sl
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
  predicate inv_f(integer x) =
    ((0 <= x) && (x <= 100));
  @*/

static inline _Bool c_inv_f(long long x) {
    return ((0 <= x) && (x <= 100));
}

int main(void) {
    // 1. Variable declarations
    long long x;

    // 2. Pre-condition initialization
    x = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x);
      @ loop assigns x;
      @*/
    while ((x < 100)) {
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((x == 100));
    /*@ assert (x == 100); */

    return 0;
}
