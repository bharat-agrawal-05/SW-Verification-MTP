/*
 * Generated C verification file from: non-lin-ineq-1.desugared.sl
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
  predicate inv_f(integer i, integer j, integer k) =
    ((j < 1000) || ((i * j) <= k));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long k) {
    return ((j < 1000) || ((i * j) <= k));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    i = 0;
    j = nondet_long();
    k = nondet_long();
    if (!(((0 * j) <= k))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, k);
      @ loop assigns i, k;
      @*/
    while ((j < 1000)) {
        i = (i + 1);
        k = (k + j);
    }

    // 4. Post-condition assertion
    assert(((j < 1000) || ((i * j) <= k)));
    /*@ assert ((j < 1000) || ((i * j) <= k)); */

    return 0;
}
