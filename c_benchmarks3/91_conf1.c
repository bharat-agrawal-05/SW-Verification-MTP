/*
 * Generated C verification file from: 91_conf1.sl
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
  predicate inv_f(integer conf_0, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2) =
    ((x <= 8) && (x >= 0) && (y >= 0));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2) {
    return ((x <= 8) && (x >= 0) && (y >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;

    // 2. Pre-condition initialization
    conf_0 = 8;
    x = 0;
    y = 0;
    conf_0_0 = 8;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, conf_0_0, conf_0_1, conf_0_2);
      @ loop assigns y;
      @*/
    while ((y >= 0)) {
        y = (y + x);
    }

    // 4. Post-condition assertion
    assert((y >= 0));
    /*@ assert (y >= 0); */

    return 0;
}
