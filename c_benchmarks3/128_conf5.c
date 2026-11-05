/*
 * Generated C verification file from: 128_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0) =
    (x >= 1);
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0) {
    return (x >= 1);
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_3_1;
    long long conf_3_2;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 8;
    conf_1 = 7;
    conf_2 = 7;
    conf_3 = 7;
    conf_4 = 5;
    x = 1;
    y = nondet_long();
    conf_0_0 = 8;
    conf_1_0 = 7;
    conf_2_0 = 7;
    conf_3_0 = 7;
    conf_3_1 = nondet_long();
    conf_3_2 = nondet_long();
    conf_4_0 = 5;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, y, conf_0_0, conf_1_0, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0);
      @ loop assigns x;
      @*/
    while ((x < y)) {
        x = (x + x);
    }

    // 4. Post-condition assertion
    assert((x >= 1));
    /*@ assert (x >= 1); */

    return 0;
}
