/*
 * Generated C verification file from: 114_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer sn, integer x, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_4_0) =
    (sn == x);
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long sn, long long x, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_4_0) {
    return (sn == x);
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long sn;
    long long x;
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
    conf_0 = 4;
    conf_1 = 5;
    conf_2 = 8;
    conf_3 = 1;
    conf_4 = 3;
    sn = 0;
    x = 0;
    tmp = nondet_long();
    conf_0_0 = 4;
    conf_1_0 = 5;
    conf_1_1 = nondet_long();
    conf_1_2 = nondet_long();
    conf_2_0 = 8;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 1;
    conf_4_0 = 3;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, sn, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_4_0);
      @ loop assigns conf_1, conf_2, sn, x;
      @*/
    while (1) {
        conf_1 = 352;
        conf_2 = (352 - conf_2);
        sn = (sn + 1);
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((sn == -1));
    /*@ assert (sn == -1); */

    return 0;
}
