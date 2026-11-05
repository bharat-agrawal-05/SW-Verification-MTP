/*
 * Generated C verification file from: s11.desugared.sl
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
  predicate inv_f(integer i, integer j, integer k, integer l) =
    ((i == (l + (k * j))) && (j <= 1000));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long k, long long l) {
    return ((i == (l + (k * j))) && (j <= 1000));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;
    long long l;

    // 2. Pre-condition initialization
    i = l;
    j = 0;
    k = nondet_long();
    l = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, k, l);
      @ loop assigns i, j;
      @*/
    while ((j < 1000)) {
        i = (i + k);
        j = (j + 1);
    }

    // 4. Post-condition assertion
    assert(((j < 1000) || (i == (l + (k * j)))));
    /*@ assert ((j < 1000) || (i == (l + (k * j)))); */

    return 0;
}
