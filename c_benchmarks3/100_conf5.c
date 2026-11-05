/*
 * Generated C verification file from: 100_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_3_0, integer conf_4_0) =
    ((n >= 0) && (y <= n) && ((x + y) == n));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_3_0, long long conf_4_0) {
    return ((n >= 0) && (y <= n) && ((x + y) == n));
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
    long long conf_1_1;
    long long conf_1_2;
    long long conf_2_0;
    long long conf_2_1;
    long long conf_2_2;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 4;
    conf_1 = 1;
    conf_2 = 8;
    conf_3 = 1;
    conf_4 = 3;
    n = nondet_long();
    x = n;
    y = 0;
    conf_0_0 = 4;
    conf_1_0 = 1;
    conf_1_1 = nondet_long();
    conf_1_2 = nondet_long();
    conf_2_0 = 8;
    conf_2_1 = nondet_long();
    conf_2_2 = nondet_long();
    conf_3_0 = 1;
    conf_4_0 = 3;
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_2_0, conf_2_1, conf_2_2, conf_3_0, conf_4_0);
      @ loop assigns conf_1, conf_2, x, y;
      @*/
    while ((x > 0)) {
        conf_1 = 778;
        conf_2 = (833 + 421);
        x = (x - 1);
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert((y == n));
    /*@ assert (y == n); */

    return 0;
}
