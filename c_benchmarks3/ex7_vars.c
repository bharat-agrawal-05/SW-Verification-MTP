/*
 * Generated C verification file from: ex7_vars.sl
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
  predicate inv_fun(integer x, integer y, integer i, integer z1, integer z2, integer z3) =
    ((0 <= y) && (y <= x) && (0 <= i) && (i <= y));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long z1, long long z2, long long z3) {
    return ((0 <= y) && (y <= x) && (0 <= i) && (i <= y));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long i;
    long long z1;
    long long z2;
    long long z3;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    i = 0;
    z1 = nondet_long();
    z2 = nondet_long();
    z3 = nondet_long();
    if (!((x >= 0))) return 0;
    if (!((y >= 0))) return 0;
    if (!((x >= y))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, z1, z2, z3);
      @ loop assigns i;
      @*/
    while ((i < y)) {
        i = (i + 1);
    }

    // 4. Post-condition assertion
    assert(!(((i < y) && ((i >= x) || (0 > i)))));
    /*@ assert !(((i < y) && ((i >= x) || (0 > i)))); */

    return 0;
}
