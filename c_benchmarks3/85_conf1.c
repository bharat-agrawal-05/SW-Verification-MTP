/*
 * Generated C verification file from: 85_conf1.sl
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
  predicate inv_f(integer conf_0, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    (((conf_0 == 3) && (x == -15000)) || !(((conf_0 == conf_0) && (x == x) && (y == y))) || !((!((x < 0)) && !((y > 0)))));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return (((conf_0 == 3) && (x == -15000)) || !(((conf_0 == conf_0) && (x == x) && (y == y))) || !((!((x < 0)) && !((y > 0)))));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    conf_0 = 3;
    x = -15000;
    y = nondet_long();
    conf_0_0 = 3;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns conf_0, x, y;
      @*/
    while ((x < 0)) {
        long long _old_y = y;
        conf_0 = (179 + conf_0);
        x = (x + _old_y);
        y = (_old_y + 1);
    }

    // 4. Post-condition assertion
    assert((y > 0));
    /*@ assert (y > 0); */

    return 0;
}
