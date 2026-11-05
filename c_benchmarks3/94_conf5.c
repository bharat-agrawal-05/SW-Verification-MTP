/*
 * Generated C verification file from: 94_conf5.sl
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
  predicate inv_f(integer i, integer j, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer k, integer n, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_1_0, integer conf_2_0, integer conf_3_0, integer conf_4_0) =
    ((conf_0 <= 1230) && (conf_1 <= 2) && (conf_2 <= 0) && (conf_3 <= 6) && (conf_4 <= 9) && (i >= 0) && (j >= 0) && (k >= 0) && (n >= 0) && ((i <= n) || !(((i + (j + k)) <= (2 * n)))));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long k, long long n, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_1_0, long long conf_2_0, long long conf_3_0, long long conf_4_0) {
    return ((conf_0 <= 1230) && (conf_1 <= 2) && (conf_2 <= 0) && (conf_3 <= 6) && (conf_4 <= 9) && (i >= 0) && (j >= 0) && (k >= 0) && (n >= 0) && ((i <= n) || !(((i + (j + k)) <= (2 * n)))));
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
    long long k;
    long long n;
    long long conf_0_0;
    long long conf_0_1;
    long long conf_0_2;
    long long conf_0_3;
    long long conf_1_0;
    long long conf_2_0;
    long long conf_3_0;
    long long conf_4_0;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    conf_0 = 3;
    conf_1 = 2;
    conf_2 = 0;
    conf_3 = 6;
    conf_4 = 9;
    k = nondet_long();
    n = nondet_long();
    conf_0_0 = 3;
    conf_0_1 = nondet_long();
    conf_0_2 = nondet_long();
    conf_0_3 = nondet_long();
    conf_1_0 = 2;
    conf_2_0 = 0;
    conf_3_0 = 6;
    conf_4_0 = 9;
    if (!((k >= 0))) return 0;
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, conf_0, conf_1, conf_2, conf_3, conf_4, k, n, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_1_0, conf_2_0, conf_3_0, conf_4_0);
      @ loop assigns i, j, conf_0;
      @*/
    while ((i <= n)) {
        long long _old_i = i;
        i = (_old_i + 1);
        j = (j + (_old_i + 1));
        conf_0 = 797;
    }

    // 4. Post-condition assertion
    assert(((i + (j + k)) > (2 * n)));
    /*@ assert ((i + (j + k)) > (2 * n)); */

    return 0;
}
