/*
 * Generated C verification file from: gauss_sum-more-rows.auto.sl
 * SMT-LIB Logic: NIA
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
  predicate inv_f(integer n, integer sum, integer i) =
    ((1 <= n) && (n <= 1000) && (sum == (((i / 2) * (i + 1)) + (-(i)))) && (i <= (n + 1)));
  @*/

static inline _Bool c_inv_f(long long n, long long sum, long long i) {
    return ((1 <= n) && (n <= 1000) && (sum == (((i / 2) * (i + 1)) + (-(i)))) && (i <= (n + 1)));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long sum;
    long long i;

    // 2. Pre-condition initialization
    n = nondet_long();
    sum = 0;
    i = 1;
    if (!((1 <= n))) return 0;
    if (!((n <= 1000))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, sum, i);
      @ loop assigns i, sum;
      @*/
    while ((i <= n)) {
        long long _old_i = i;
        i = (_old_i + 1);
        sum = (sum + _old_i);
    }

    // 4. Post-condition assertion
    assert(((i <= n) || ((sum * 2) == (n * (n + 1)))));
    /*@ assert ((i <= n) || ((sum * 2) == (n * (n + 1)))); */

    return 0;
}
