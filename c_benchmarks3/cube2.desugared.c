/*
 * Generated C verification file from: cube2.desugared.sl
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
  predicate inv_f(integer n, integer x, integer y, integer z) =
    ((x == (n * (n * n))) && (y == (1 + (3 * n * n) + (3 * n))) && (z == (6 + (6 * n))));
  @*/

static inline _Bool c_inv_f(long long n, long long x, long long y, long long z) {
    return ((x == (n * (n * n))) && (y == (1 + (3 * n * n) + (3 * n))) && (z == (6 + (6 * n))));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;
    long long y;
    long long z;

    // 2. Pre-condition initialization
    n = 0;
    x = 0;
    y = 1;
    z = 6;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, x, y, z);
      @ loop assigns n, x, y, z;
      @*/
    while ((n < 100)) {
        long long _old_y = y;
        long long _old_z = z;
        n = (n + 1);
        x = (x + _old_y);
        y = (_old_y + _old_z);
        z = (_old_z + 6);
    }

    // 4. Post-condition assertion
    assert(((n < 100) || (x == (n * (n * n)))));
    /*@ assert ((n < 100) || (x == (n * (n * n)))); */

    return 0;
}
