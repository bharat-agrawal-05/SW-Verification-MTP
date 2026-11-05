/*
 * Generated C verification file from: ex23.sl
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
  predicate inv_fun(integer y, integer z, integer c) =
    (((y >= 0) && (y <= 127)) && ((z >= 0) && (z <= 4608)) && (((36 * y) + c) >= z));
  @*/

static inline _Bool c_inv_fun(long long y, long long z, long long c) {
    return (((y >= 0) && (y <= 127)) && ((z >= 0) && (z <= 4608)) && (((36 * y) + c) >= z));
}

int main(void) {
    // 1. Variable declarations
    long long y;
    long long z;
    long long c;

    // 2. Pre-condition initialization
    y = nondet_long();
    z = (36 * y);
    c = 0;
    if (!((y >= 0))) return 0;
    if (!((127 >= y))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(y, z, c);
      @ loop assigns z, c;
      @*/
    while ((c < 36)) {
        z = (z + 1);
        c = (c + 1);
    }

    // 4. Post-condition assertion
    assert(!(((c < 36) && ((z < 0) || (z >= 4608)))));
    /*@ assert !(((c < 36) && ((z < 0) || (z >= 4608)))); */

    return 0;
}
