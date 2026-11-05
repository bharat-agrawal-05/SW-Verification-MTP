/*
 * Generated C verification file from: fib_41.sl
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
  predicate inv_fun(integer n, integer k, integer i, integer j) =
    (k >= (((i - j) * 2) * (i - j)));
  @*/

static inline _Bool c_inv_fun(long long n, long long k, long long i, long long j) {
    return (k >= (((i - j) * 2) * (i - j)));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long k;
    long long i;
    long long j;

    // 2. Pre-condition initialization
    n = nondet_long();
    k = nondet_long();
    i = 0;
    j = 0;
    if (!((n >= 0))) return 0;
    if (!(((k == 1) || (k >= 0)))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(n, k, i, j);
      @ loop assigns i, j;
      @*/
    while ((i <= n)) {
        i = (i + 1);
        j = (j + 1);
    }

    // 4. Post-condition assertion
    assert((!((i > n)) || ((k + i + j) > (2 * n))));
    /*@ assert ((i > n) ==> ((k + i + j) > (2 * n))); */

    return 0;
}
