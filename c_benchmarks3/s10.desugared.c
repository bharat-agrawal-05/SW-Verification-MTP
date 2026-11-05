/*
 * Generated C verification file from: s10.desugared.sl
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
    ((0 <= j) && (i == (10 + (k * j))) && (j <= 1000));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long k) {
    return ((0 <= j) && (i == (10 + (k * j))) && (j <= 1000));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    i = 10;
    j = 0;
    k = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, k);
      @ loop assigns i, j;
      @*/
    while ((j < 1000)) {
        i = (i + k);
        j = (j + 1);
    }

    // 4. Post-condition assertion
    assert(((j < 1000) || (i == (10 + (k * j)))));
    /*@ assert ((j < 1000) || (i == (10 + (k * j)))); */

    return 0;
}
