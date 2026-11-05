/*
 * Generated C verification file from: 13_conf1.sl
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
  predicate inv_f(integer conf_0, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    ((!(((x == 4) && (y == 0))) || !(((conf_0 == conf_0) && (x == x) && (y == y)))) && (y >= 0));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return ((!(((x == 4) && (y == 0))) || !(((conf_0 == conf_0) && (x == x) && (y == y)))) && (y >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long x;
    long long y;
    long long tmp;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    conf_0 = 2;
    x = nondet_long();
    y = nondet_long();
    tmp = nondet_long();
    conf_0_0 = 2;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();
    if (!((x >= 0))) return 0;
    if (!((x <= 2))) return 0;
    if (!((y <= 2))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns conf_0, x, y;
      @*/
    while (1) {
        conf_0 = (conf_0 + conf_0);
        x = (x + 2);
        y = (y + 2);
    }

    // 4. Post-condition assertion
    assert(!((y == 0)));
    /*@ assert !((y == 0)); */

    return 0;
}
