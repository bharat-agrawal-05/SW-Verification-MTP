/*
 * Generated C verification file from: dec_simpl-new.sl
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
  predicate inv_fun(integer x, integer n) =
    \false;
  @*/

static inline _Bool c_inv_fun(long long x, long long n) {
    return false;
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long n;

    // 2. Pre-condition initialization
    x = n;
    n = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, n);
      @ loop assigns x;
      @*/
    while ((x > 1)) {
        x = (x - 1);
    }

    // 4. Post-condition assertion
    assert(!(((x <= 1) && (!((x == 1)) && (n >= 0)))));
    /*@ assert !(((x <= 1) && (!((x == 1)) && (n >= 0)))); */

    return 0;
}
