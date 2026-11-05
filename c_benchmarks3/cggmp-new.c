/*
 * Generated C verification file from: cggmp-new.sl
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
  predicate inv_fun(integer i, integer j) =
    (!((!((i <= j)) && !((j == 13)))) && ((-2 * j) == (-41 + i)));
  @*/

static inline _Bool c_inv_fun(long long i, long long j) {
    return (!((!((i <= j)) && !((j == 13)))) && ((-2 * j) == (-41 + i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;

    // 2. Pre-condition initialization
    i = 1;
    j = 20;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j);
      @ loop assigns i, j;
      @*/
    while ((j >= i)) {
        i = (i + 2);
        j = (j - 1);
    }

    // 4. Post-condition assertion
    assert(!(((j < i) && !((j == 13)))));
    /*@ assert !(((j < i) && !((j == 13)))); */

    return 0;
}
