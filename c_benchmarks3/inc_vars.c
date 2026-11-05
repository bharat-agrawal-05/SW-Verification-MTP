/*
 * Generated C verification file from: inc_vars.sl
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
  predicate inv_fun(integer x, integer n, integer v1, integer v2, integer v3) =
    ((n < 0) || ((x >= 0) && (x <= n) && (((v1 + (x * v2) + (x * x) + v3) == 0) || !(((v1 + (x * v2) + (x * x) + v3) == 0)))));
  @*/

static inline _Bool c_inv_fun(long long x, long long n, long long v1, long long v2, long long v3) {
    return ((n < 0) || ((x >= 0) && (x <= n) && (((v1 + (x * v2) + (x * x) + v3) == 0) || !(((v1 + (x * v2) + (x * x) + v3) == 0)))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long n;
    long long v1;
    long long v2;
    long long v3;

    // 2. Pre-condition initialization
    x = 0;
    n = nondet_long();
    v1 = nondet_long();
    v2 = nondet_long();
    v3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, n, v1, v2, v3);
      @ loop assigns x;
      @*/
    while ((x < n)) {
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((!((x >= n)) || ((x == n) || (n < 0))));
    /*@ assert (!((x >= n)) || ((x == n) || (n < 0))); */

    return 0;
}
