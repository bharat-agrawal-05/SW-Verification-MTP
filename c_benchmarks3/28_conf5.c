/*
 * Generated C verification file from: 28_conf5.sl
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
  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_1_0, integer conf_2_0, integer conf_3_0, integer conf_4_0) =
    (((conf_0 == 5) && (conf_1 == 7) && (conf_2 == 4) && (conf_3 == 0) && (conf_4 == 1) && (x == n)) || ((x >= 0) && (x <= n)));
  @*/

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_1_0, long long conf_2_0, long long conf_3_0, long long conf_4_0) {
    return (((conf_0 == 5) && (conf_1 == 7) && (conf_2 == 4) && (conf_3 == 0) && (conf_4 == 1) && (x == n)) || ((x >= 0) && (x <= n)));
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
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    conf_0 = 5;
    conf_1 = 7;
    conf_2 = 4;
    conf_3 = 0;
    conf_4 = 1;
    n = nondet_long();
    x = n;
    conf_0_0 = 5;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_1_0 = 7;
    conf_2_0 = 4;
    conf_3_0 = 0;
    conf_4_0 = 1;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, n, x, conf_0_0, conf_0_1, conf_0_2, conf_1_0, conf_2_0, conf_3_0, conf_4_0);
      @ loop assigns conf_0, x;
      @*/
    while ((x > 0)) {
        conf_0 = (conf_1 + 376);
        x = (x - 1);
    }

    // 4. Post-condition assertion
    assert((!(((conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (n == n) && (x == x))) || !((!((x > 0)) && !((x == 0)) && !((n < 0))))));
    /*@ assert (!(((conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (n == n) && (x == x))) || !((!((x > 0)) && !((x == 0)) && !((n < 0))))); */

    return 0;
}
