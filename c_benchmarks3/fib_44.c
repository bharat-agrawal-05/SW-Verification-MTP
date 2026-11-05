/*
 * Generated C verification file from: fib_44.sl
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
  predicate inv_fun(integer i, integer j, integer n, integer k) =
    (((i <= k) && (j == (n * i)) && (k == (n - 1))) || (j == (n * i)));
  @*/

static inline _Bool c_inv_fun(long long i, long long j, long long n, long long k) {
    return (((i <= k) && (j == (n * i)) && (k == (n - 1))) || (j == (n * i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long n;
    long long k;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    n = nondet_long();
    k = nondet_long();
    if (!(((n == 1) || (n == 2)))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, n, k);
      @ loop assigns i, j;
      @*/
    while ((i <= k)) {
        i = (i + 1);
        j = (j + n);
    }

    // 4. Post-condition assertion
    assert((!((i > k)) || (!((n == 1)) || (i == j))));
    /*@ assert ((i > k) ==> (!((n == 1)) || (i == j))); */

    return 0;
}
