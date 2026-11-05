/*
 * Generated C verification file from: 63_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_1_0, integer conf_2_0, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2) =
    (((conf_0 == conf_0) && (conf_4 == conf_4) && (x == x) && (y == y) && !((x <= 10)) && !((y >= 0))) ==> ((conf_0 == 9) && (conf_1 == 4) && (conf_2 == 5) && (conf_3 == 0) && (conf_4 == 4) && (x == 1)));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_1_0, long long conf_2_0, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2) {
    return (!(((conf_0 == conf_0) && (conf_4 == conf_4) && (x == x) && (y == y) && !((x <= 10)) && !((y >= 0)))) || ((conf_0 == 9) && (conf_1 == 4) && (conf_2 == 5) && (conf_3 == 0) && (conf_4 == 4) && (x == 1)));
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
    long long conf_0_1;
    long long conf_0_2;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_4_0;
    long long conf_4_1;
    long long conf_4_2;

    // 2. Pre-condition initialization
    conf_0 = 9;
    conf_1 = 4;
    conf_2 = 5;
    conf_3 = 0;
    conf_4 = 4;
    x = 1;
    y = nondet_long();
    conf_0_0 = 9;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_1_0 = 4;
    conf_2_0 = 5;
    conf_3_0 = 0;
    conf_4_0 = 4;
    conf_4_1 = nondet_long();
    conf_4_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, x, y, conf_0_0, conf_0_1, conf_0_2, conf_1_0, conf_2_0, conf_3_0, conf_4_0, conf_4_1, conf_4_2);
      @ loop assigns conf_0, conf_4, x, y;
      @*/
    while ((x <= 10)) {
        long long _old_x = x;
        conf_0 = 178;
        conf_4 = (conf_3 - 687);
        x = (_old_x + 1);
        y = (10 - _old_x);
    }

    // 4. Post-condition assertion
    assert((y >= 0));
    /*@ assert (y >= 0); */

    return 0;
}
