/*
 * Generated C verification file from: 115_conf1.sl
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
  predicate inv_f(integer conf_0, integer sn, integer x, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    (sn == x);
  @*/

static inline _Bool c_inv_f(long long conf_0, long long sn, long long x, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return (sn == x);
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long sn;
    long long x;
    long long tmp;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    conf_0 = 7;
    sn = 0;
    x = 0;
    tmp = nondet_long();
    conf_0_0 = 7;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, sn, x, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns conf_0, sn, x;
      @*/
    while (1) {
        conf_0 = (conf_0 + conf_0);
        sn = (sn + 1);
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((sn == x));
    /*@ assert (sn == x); */

    return 0;
}
