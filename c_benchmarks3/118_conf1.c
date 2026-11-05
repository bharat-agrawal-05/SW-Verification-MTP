/*
 * Generated C verification file from: 118_conf1.sl
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
  predicate inv_f(integer i, integer conf_0, integer size, integer sn, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    ((!(((i == i) && (conf_0 == conf_0) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == size)) && !((sn == 0))))) && (sn == (-1 + i)));
  @*/

static inline _Bool c_inv_f(long long i, long long conf_0, long long size, long long sn, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return ((!(((i == i) && (conf_0 == conf_0) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == size)) && !((sn == 0))))) && (sn == (-1 + i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long conf_0;
    long long size;
    long long sn;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    i = 1;
    conf_0 = 9;
    size = nondet_long();
    sn = 0;
    conf_0_0 = 9;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, conf_0, size, sn, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns i, conf_0, sn;
      @*/
    while ((i <= size)) {
        i = (i + 1);
        conf_0 = 709;
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (conf_0 == conf_0) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == size)) && !((sn == 0))))));
    /*@ assert (!(((i == i) && (conf_0 == conf_0) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == size)) && !((sn == 0))))); */

    return 0;
}
