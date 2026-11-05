/*
 * Generated C verification file from: issue_8.sl
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
  predicate inv_f(integer x, integer y, integer q, integer r) =
    ((y >= 0) && (r >= 0) && (((y * q) + r) == x));
  @*/

static inline _Bool c_inv_f(long long x, long long y, long long q, long long r) {
    return ((y >= 0) && (r >= 0) && (((y * q) + r) == x));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long q;
    long long r;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    q = 0;
    r = x;
    if (!((y > 0))) return 0;
    if (!((x >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y, q, r);
      @ loop assigns r, q;
      @*/
    while ((r >= y)) {
        r = (r - y);
        q = (q + 1);
    }

    // 4. Post-condition assertion
    assert(((r >= y) || ((x == (r + (q * y))) && (r >= 0))));
    /*@ assert ((r >= y) || ((x == (r + (q * y))) && (r >= 0))); */

    return 0;
}
