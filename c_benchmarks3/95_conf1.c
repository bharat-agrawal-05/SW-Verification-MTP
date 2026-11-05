/*
 * Generated C verification file from: 95_conf1.sl
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
  predicate inv_f(integer i, integer j, integer conf_0, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3) =
    (j == (i * y));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long conf_0, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3) {
    return (j == (i * y));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long conf_0;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    conf_0 = 2;
    x = nondet_long();
    y = 1;
    conf_0_0 = 2;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, conf_0, x, y, conf_0_0, conf_0_1, conf_0_2, conf_0_3);
      @ loop assigns i, j, conf_0;
      @*/
    while ((i <= x)) {
        i = (i + 1);
        j = (j + y);
        conf_0 = 493;
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (j == j) && (conf_0 == conf_0) && (x == x) && (y == y))) || !((!((i <= x)) && (y == 1) && !((i == j))))));
    /*@ assert (!(((i == i) && (j == j) && (conf_0 == conf_0) && (x == x) && (y == y))) || !((!((i <= x)) && (y == 1) && !((i == j))))); */

    return 0;
}
