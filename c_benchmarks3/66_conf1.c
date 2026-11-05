/*
 * Generated C verification file from: 66_conf1.sl
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
    (((conf_0 == conf_0) && (x == x) && (conf_0 == 1) && (x == 1)) || ((conf_0 == conf_0) && (x == x) && (y == y) && (x <= 100) && (y == (100 - x)) && (conf_0 == 575) && (x == (x + 1)) && (conf_0 == (conf_0 + conf_0)) && (conf_0 == conf_0) && (y == y)) || !(((conf_0 == conf_0) && (x == x) && (y == y))) || !((!((x <= 100)) && !((y < 100)))));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return (((conf_0 == conf_0) && (x == x) && (conf_0 == 1) && (x == 1)) || ((conf_0 == conf_0) && (x == x) && (y == y) && (x <= 100) && (y == (100 - x)) && (conf_0 == 575) && (x == (x + 1)) && (conf_0 == (conf_0 + conf_0)) && (conf_0 == conf_0) && (y == y)) || !(((conf_0 == conf_0) && (x == x) && (y == y))) || !((!((x <= 100)) && !((y < 100)))));
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
    conf_0 = 1;
    x = 1;
    y = nondet_long();
    conf_0_0 = 1;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns conf_0, x, y;
      @*/
    while ((x <= 100)) {
        long long _old_x = x;
        conf_0 = (575 + 575);
        x = (_old_x + 1);
        y = (100 - _old_x);
    }

    // 4. Post-condition assertion
    assert((y < 100));
    /*@ assert (y < 100); */

    return 0;
}
