/*
 * Generated C verification file from: 67_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0) =
    ((1 == x) || (y >= 0));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0) {
    return ((1 == x) || (y >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long n;
    long long x;
    long long y;
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
    conf_0 = 9;
    conf_1 = 0;
    conf_2 = 0;
    conf_3 = 5;
    conf_4 = 9;
    n = nondet_long();
    x = 1;
    y = nondet_long();
    conf_0_0 = 9;
    conf_1_0 = 0;
    conf_2_0 = 0;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 5;
    conf_3_1 = nondet_long();
    conf_3_2 = nondet_long();
    conf_4_0 = 9;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_3_1, conf_3_2, conf_4_0);
      @ loop assigns conf_2, conf_3, x, y;
      @*/
    while ((x <= n)) {
        long long _old_x = x;
        conf_2 = (conf_4 - (conf_1 + 522));
        conf_3 = (conf_1 + 522);
        x = (_old_x + 1);
        y = (n - _old_x);
    }

    // 4. Post-condition assertion
    assert((!(((conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (n == n) && (x == x) && (y == y))) || !((!((x <= n)) && (n > 0) && !((y >= 0))))));
    /*@ assert (!(((conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (n == n) && (x == x) && (y == y))) || !((!((x <= n)) && (n > 0) && !((y >= 0))))); */

    return 0;
}
