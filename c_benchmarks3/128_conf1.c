/*
 * Generated C verification file from: 128_conf1.sl
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
    ((conf_0 >= 5) && (x >= 1));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2) {
    return ((conf_0 >= 5) && (x >= 1));
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
    conf_0 = 5;
    x = 1;
    y = nondet_long();
    conf_0_0 = 5;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, conf_0_0, conf_0_1, conf_0_2);
      @ loop assigns conf_0, x;
      @*/
    while ((x < y)) {
        conf_0 = (conf_0 + 535);
        x = (x + x);
    }

    // 4. Post-condition assertion
    assert((x >= 1));
    /*@ assert (x >= 1); */

    return 0;
}
