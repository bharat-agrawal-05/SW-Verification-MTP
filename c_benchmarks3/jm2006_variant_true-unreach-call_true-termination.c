/*
 * Generated C verification file from: jm2006_variant_true-unreach-call_true-termination.sl
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
  predicate inv_fun(integer i, integer j, integer x, integer y, integer z) =
    (((z == 0) && (x == i) && (y == j)) || (!((z == 0)) && (x == (i - z)) && (y == (j - (2 * z)))));
  @*/

static inline _Bool c_inv_fun(long long i, long long j, long long x, long long y, long long z) {
    return (((z == 0) && (x == i) && (y == j)) || (!((z == 0)) && (x == (i - z)) && (y == (j - (2 * z)))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long x;
    long long y;
    long long z;

    // 2. Pre-condition initialization
    i = nondet_long();
    j = nondet_long();
    x = i;
    y = j;
    z = 0;
    if (!((i >= 0))) return 0;
    if (!((j >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, x, y, z);
      @ loop assigns x, y, z;
      @*/
    while (!((x == 0))) {
        x = (x - 1);
        y = (y - 2);
        z = (z + 1);
    }

    // 4. Post-condition assertion
    assert((!((x == 0)) || (!((i == j)) || (y == (0 - z)))));
    /*@ assert (!((x == 0)) || ((i == j) ==> (y == (0 - z)))); */

    return 0;
}
