/*
 * Generated C verification file from: hola.41.sl
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
  predicate inv_fun(integer i, integer j, integer k, integer n) =
    (((i <= n) || ((i + (j + k)) > (2 * n))) && (i >= 0) && (j >= 0) && (k >= 0) && (n >= 0));
  @*/

static inline _Bool c_inv_fun(long long i, long long j, long long k, long long n) {
    return (((i <= n) || ((i + (j + k)) > (2 * n))) && (i >= 0) && (j >= 0) && (k >= 0) && (n >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;
    long long n;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    k = nondet_long();
    n = nondet_long();
    if (!(((k == 1) || (k >= 0)))) return 0;
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, k, n);
      @ loop assigns i, j;
      @*/
    while ((i <= n)) {
        long long _old_i = i;
        i = (_old_i + 1);
        j = (j + _old_i);
    }

    // 4. Post-condition assertion
    assert(((i <= n) || ((i + (j + k)) > (2 * n))));
    /*@ assert ((i <= n) || ((i + (j + k)) > (2 * n))); */

    return 0;
}
