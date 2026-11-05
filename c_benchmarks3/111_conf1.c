/*
 * Generated C verification file from: 111_conf1.sl
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
  predicate inv_f(integer i, integer conf_0, integer n, integer sn, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    ((!(((i == i) && (conf_0 == conf_0) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == 0)) && !((sn == n))))) && (sn == (-1 + i)));
  @*/

static inline _Bool c_inv_f(long long i, long long conf_0, long long n, long long sn, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return ((!(((i == i) && (conf_0 == conf_0) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == 0)) && !((sn == n))))) && (sn == (-1 + i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long conf_0;
    long long n;
    long long sn;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    i = 1;
    conf_0 = 6;
    n = nondet_long();
    sn = 0;
    conf_0_0 = 6;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, conf_0, n, sn, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns i, conf_0, sn;
      @*/
    while ((i <= n)) {
        i = (i + 1);
        conf_0 = (674 - 455);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (conf_0 == conf_0) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == 0)) && !((sn == n))))));
    /*@ assert (!(((i == i) && (conf_0 == conf_0) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == 0)) && !((sn == n))))); */

    return 0;
}
