/*
 * Generated C verification file from: 28_conf1.sl
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
  predicate inv_f(integer conf_0, integer n, integer x, integer conf_0_0, integer conf_0_1, integer conf_0_2) =
    (((conf_0 == 1) && (x == n)) || ((x >= 0) && (x <= n)));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long n, long long x, long long conf_0_0, long long conf_0_1, long long conf_0_2) {
    return (((conf_0 == 1) && (x == n)) || ((x >= 0) && (x <= n)));
}

int main(void) {
    // 1. Variable declarations
    long long conf_0;
    long long n;
    long long x;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;

    // 2. Pre-condition initialization
    conf_0 = 1;
    n = nondet_long();
    x = n;
    conf_0_0 = 1;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, n, x, conf_0_0, conf_0_1, conf_0_2);
      @ loop assigns x;
      @*/
    while ((x > 0)) {
        x = (x - 1);
    }

    // 4. Post-condition assertion
    assert((!(((conf_0 == conf_0) && (n == n) && (x == x))) || !((!((x > 0)) && !((x == 0)) && !((n < 0))))));
    /*@ assert (!(((conf_0 == conf_0) && (n == n) && (x == x))) || !((!((x > 0)) && !((x == 0)) && !((n < 0))))); */

    return 0;
}
