/*
 * Generated C verification file from: 10_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_4_0) =
    (y >= (-3 + x));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_4_0) {
    return (y >= (-3 + x));
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
    long long tmp;
    long long conf_0_0;
    long long conf_1_0;
    long long conf_1_1;
    long long conf_1_2;
    long long conf_2_0;
    long long conf_2_1;
    long long conf_2_2;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 6;
    conf_1 = 3;
    conf_2 = 4;
    conf_3 = 8;
    conf_4 = 3;
    x = nondet_long();
    y = nondet_long();
    tmp = nondet_long();
    conf_0_0 = 6;
    conf_1_0 = 3;
    conf_1_1 = nondet_long();
    conf_1_2 = nondet_long();
    conf_2_0 = 4;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 8;
    conf_4_0 = 3;
    if (!((x >= 0))) return 0;
    if (!((x <= 2))) return 0;
    if (!((y <= 2))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, y, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_4_0);
      @ loop assigns conf_1, conf_2, x, y;
      @*/
    while (1) {
        conf_1 = (conf_0 - (520 - 69));
        conf_2 = (520 - 69);
        x = (x + 2);
        y = (y + 2);
    }

    // 4. Post-condition assertion
    assert(!((x == 4)));
    /*@ assert !((x == 4)); */

    return 0;
}
