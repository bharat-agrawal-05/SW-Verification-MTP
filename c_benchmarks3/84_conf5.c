/*
 * Generated C verification file from: 84_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2) =
    (((x >= -50) && (y <= 0)) ==> !((!((x < 0)) && !((y > 0)))));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2) {
    return (!(((x >= -50) && (y <= 0))) || !((!((x < 0)) && !((y > 0)))));
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
    long long conf_2_1;
    long long conf_2_2;
    long long conf_3_0;
    long long conf_4_0;
    long long conf_4_1;
    long long conf_4_2;

    // 2. Pre-condition initialization
    conf_0 = 7;
    conf_1 = 3;
    conf_2 = 9;
    conf_3 = 9;
    conf_4 = 6;
    x = -50;
    y = nondet_long();
    conf_0_0 = 7;
    conf_1_0 = 3;
    conf_2_0 = 9;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 9;
    conf_4_0 = 6;
    conf_4_1 = nondet_long();
    conf_4_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, y, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_4_0, conf_4_1, conf_4_2);
      @ loop assigns x, y;
      @*/
    while ((x < 0)) {
        long long _old_y = y;
        x = (x + _old_y);
        y = (_old_y + 1);
    }

    // 4. Post-condition assertion
    assert((y > 0));
    /*@ assert (y > 0); */

    return 0;
}
