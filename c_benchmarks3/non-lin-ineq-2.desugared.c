/*
 * Generated C verification file from: non-lin-ineq-2.desugared.sl
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
    ((i <= (j * k)) && (i >= 0));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long k) {
    return ((i <= (j * k)) && (i >= 0));
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
    if (!((j > 0))) return 0;
    if (!((k > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, k);
      @ loop assigns i;
      @*/
    while ((i < (j * k))) {
        i = (i + 1);
    }

    // 4. Post-condition assertion
    assert(((i < (j * k)) || (i == (j * k))));
    /*@ assert ((i < (j * k)) || (i == (j * k))); */

    return 0;
}
