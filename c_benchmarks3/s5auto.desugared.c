/*
 * Generated C verification file from: s5auto.desugared.sl
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
    (((j < k) && (i == (2 * (k * j))) && (j == (k - 1))) || (i == (2 * (k * j))));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long k) {
    return (((j < k) && (i == (2 * (k * j))) && (j == (k - 1))) || (i == (2 * (k * j))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    k = nondet_long();
    if (!((k > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, k);
      @ loop assigns j, i;
      @*/
    while ((j < k)) {
        j = (j + 1);
        i = (i + (2 * k));
    }

    // 4. Post-condition assertion
    assert(((j < k) || (i == (2 * (k * j)))));
    /*@ assert ((j < k) || (i == (2 * (k * j)))); */

    return 0;
}
