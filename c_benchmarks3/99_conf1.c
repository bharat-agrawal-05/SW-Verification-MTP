/*
 * Generated C verification file from: 99_conf1.sl
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
  predicate inv_f(integer conf_0, integer n, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    ((x >= 0) && (y >= 0) && (x <= n) && (y <= n) && ((x + y) == n));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long n, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return ((x >= 0) && (y >= 0) && (x <= n) && (y <= n) && ((x + y) == n));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long n;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    conf_0 = 0;
    n = nondet_long();
    x = n;
    y = 0;
    conf_0_0 = 0;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, n, x, y, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns conf_0, x, y;
      @*/
    while ((x > 0)) {
        conf_0 = (527 + 64);
        x = (x - 1);
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert((n == (x + y)));
    /*@ assert (n == (x + y)); */

    return 0;
}
