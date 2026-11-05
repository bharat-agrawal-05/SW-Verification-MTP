/*
 * Generated C verification file from: ex7.sl
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
  predicate inv_fun(integer x, integer y, integer i) =
    ((i >= 0) && (i <= y) && (x >= y) && (x >= 0) && (y >= 0));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long i) {
    return ((i >= 0) && (i <= y) && (x >= y) && (x >= 0) && (y >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long i;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    i = 0;
    if (!((x >= 0))) return 0;
    if (!((y >= 0))) return 0;
    if (!((x >= y))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i);
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
