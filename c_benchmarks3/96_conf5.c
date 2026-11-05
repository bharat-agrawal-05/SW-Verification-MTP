/*
 * Generated C verification file from: 96_conf5.sl
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
  predicate inv_f(integer i, integer j, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x, integer y, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_1_0, integer conf_2_0, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2) =
    ((i == j) && (1 == y));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x, long long y, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_1_0, long long conf_2_0, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2) {
    return ((i == j) && (1 == y));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long conf_0;
    long long conf_1;
    long long conf_2;
    long long conf_3;
    long long conf_4;
    long long x;
    long long y;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_4_0;
    long long conf_4_1;
    long long conf_4_2;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    conf_0 = 4;
    conf_1 = 1;
    conf_2 = 3;
    conf_3 = 7;
    conf_4 = 1;
    x = nondet_long();
    y = 1;
    conf_0_0 = 4;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_1_0 = 1;
    conf_2_0 = 3;
    conf_3_0 = 7;
    conf_4_0 = 1;
    conf_4_1 = nondet_long();
    conf_4_2 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, conf_0, conf_1, conf_2, conf_3, conf_4, x, y, conf_0_0, conf_0_1, conf_0_2, conf_1_0, conf_2_0, conf_3_0, conf_4_0, conf_4_1, conf_4_2);
      @ loop assigns i, j, conf_4;
      @*/
    while ((i <= x)) {
        i = (i + 1);
        j = (j + y);
        conf_4 = (conf_3 + 671);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (j == j) && (conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (x == x) && (y == y))) || !((!((i <= x)) && !((i == j)) && !(!((y == 1)))))));
    /*@ assert (!(((i == i) && (j == j) && (conf_0 == conf_0) && (conf_1 == conf_1) && (conf_2 == conf_2) && (conf_3 == conf_3) && (conf_4 == conf_4) && (x == x) && (y == y))) || !((!((i <= x)) && !((i == j)) && !(!((y == 1)))))); */

    return 0;
}
