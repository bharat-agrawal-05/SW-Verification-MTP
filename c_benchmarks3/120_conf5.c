/*
 * Generated C verification file from: 120_conf5.sl
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
  predicate inv_f(integer i, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer sn, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_4_0) =
    ((sn >= 0) && (sn <= 8) && ((i + (-(sn))) == 1));
  @*/

static inline _Bool c_inv_f(long long i, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long sn, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_4_0) {
    return ((sn >= 0) && (sn <= 8) && ((i + (-(sn))) == 1));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long sn;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_2_1;
    long long conf_2_2;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    i = 1;
    conf_0 = 6;
    conf_1 = 2;
    conf_2 = 6;
    conf_3 = 2;
    conf_4 = 4;
    sn = 0;
    conf_0_0 = 6;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_1_0 = 2;
    conf_2_0 = 6;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 2;
    conf_4_0 = 4;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, sn, conf_0_0, conf_0_1, conf_0_2, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_4_0);
      @ loop assigns i, conf_0, conf_2, sn;
      @*/
    while ((i <= 8)) {
        i = (i + 1);
        conf_0 = (conf_3 - 206);
        conf_2 = conf_3;
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (sn == sn))) || !((!((i <= 8)) && !((sn == 8)) && !((sn == 0))))));
    /*@ assert (!(((i == i) && (conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (sn == sn))) || !((!((i <= 8)) && !((sn == 8)) && !((sn == 0))))); */

    return 0;
}
