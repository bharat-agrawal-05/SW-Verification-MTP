/*
 * Generated C verification file from: 103_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_2_0, integer conf_3_0, integer conf_4_0) =
    ((conf_0 <= 486) && (conf_1 <= 702) && (conf_2 <= 708) && (conf_3 <= 711) && (conf_4 <= 540) && (x <= 100));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_2_0, long long conf_3_0, long long conf_4_0) {
    return ((conf_0 <= 486) && (conf_1 <= 702) && (conf_2 <= 708) && (conf_3 <= 711) && (conf_4 <= 540) && (x <= 100));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long x;
    long long conf_0_0;
    long long conf_1_0;
    long long conf_1_1;
    long long conf_1_2;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 0;
    conf_1 = 3;
    conf_2 = 6;
    conf_3 = 9;
    conf_4 = 1;
    x = 0;
    conf_0_0 = 0;
    conf_1_0 = 3;
    conf_1_1 = nondet_long();
    conf_1_2 = nondet_long();
    conf_2_0 = 6;
    conf_3_0 = 9;
    conf_4_0 = 1;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_2_0, conf_3_0, conf_4_0);
      @ loop assigns conf_1, x;
      @*/
    while ((x < 100)) {
        conf_1 = (486 + 216);
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((x == 100));
    /*@ assert (x == 100); */

    return 0;
}
