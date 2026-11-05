/*
 * Generated C verification file from: 11_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0) =
    (!((conf_0 == 1)) && !((conf_0 == 2)) && !((conf_1 == 1)) && !((conf_1 == 2)) && !((conf_2 == 1)) && !((conf_2 == 2)) && !((conf_4 == 1)) && !((conf_4 == 2)) && !(((y == 0) && ((conf_3 == 76) || (conf_3 == 78)))) && !(((x == 10) && ((conf_3 == 143) || (conf_3 == 144)))) && (x >= (-(y))) && (x <= (y + 10)));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0) {
    return (!((conf_0 == 1)) && !((conf_0 == 2)) && !((conf_1 == 1)) && !((conf_1 == 2)) && !((conf_2 == 1)) && !((conf_2 == 2)) && !((conf_4 == 1)) && !((conf_4 == 2)) && !(((y == 0) && ((conf_3 == 76) || (conf_3 == 78)))) && !(((x == 10) && ((conf_3 == 143) || (conf_3 == 144)))) && (x >= (-(y))) && (x <= (y + 10)));
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
    long long conf_2_0;
    long long conf_2_1;
    long long conf_2_2;
    long long conf_3_0;
    long long conf_3_1;
    long long conf_3_2;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 3;
    conf_1 = 3;
    conf_2 = 3;
    conf_3 = 9;
    conf_4 = 3;
    x = nondet_long();
    y = nondet_long();
    tmp = nondet_long();
    conf_0_0 = 3;
    conf_1_0 = 3;
    conf_2_0 = 3;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 9;
    conf_3_1 = nondet_long();
    conf_3_2 = nondet_long();
    conf_4_0 = 3;
    if (!((x >= 0))) return 0;
    if (!((x <= 10))) return 0;
    if (!((y <= 10))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, y, tmp, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_3_1, conf_3_2, conf_4_0);
      @ loop assigns conf_2, conf_3, x, y;
      @*/
    while (1) {
        conf_2 = 353;
        conf_3 = 588;
        x = (x + 10);
        y = (y + 10);
    }

    // 4. Post-condition assertion
    assert(!((y == 0)));
    /*@ assert !((y == 0)); */

    return 0;
}
