/*
 * Generated C verification file from: fib_15.sl
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
  predicate inv_fun(integer n, integer j, integer k) =
    ((j >= 0) && (k >= 0) && (j <= n) && (k >= (-(n))) && ((j + k) >= n));
  @*/

static inline _Bool c_inv_fun(long long n, long long j, long long k) {
    return ((j >= 0) && (k >= 0) && (j <= n) && (k >= (-(n))) && ((j + k) >= n));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    n = nondet_long();
    j = 0;
    k = nondet_long();
    if (!((n > 0))) return 0;
    if (!((k > n))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(n, j, k);
      @ loop assigns j, k;
      @*/
    while ((j < n)) {
        j = (j + 1);
        k = (k - 1);
    }

    // 4. Post-condition assertion
    assert((!(!((j < n))) || (k >= 0)));
    /*@ assert (!((j < n)) ==> (k >= 0)); */

    return 0;
}
