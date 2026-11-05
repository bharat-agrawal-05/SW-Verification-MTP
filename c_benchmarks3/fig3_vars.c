/*
 * Generated C verification file from: fig3_vars.sl
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
  predicate inv_fun(integer x, integer y, integer lock, integer v1, integer v2, integer v3) =
    (((lock == 0) && ((x + 1) == y)) || (lock == 1));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long lock, long long v1, long long v2, long long v3) {
    return (((lock == 0) && ((x + 1) == y)) || (lock == 1));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long lock;
    long long v1;
    long long v2;
    long long v3;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    lock = nondet_long();
    v1 = nondet_long();
    v2 = nondet_long();
    v3 = nondet_long();
    if (!((((x == y) && (lock == 1)) || (((x + 1) == y) && (lock == 0))))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, lock, v1, v2, v3);
      @ loop assigns lock, x, y;
      @*/
    while (!((x == y))) {
        long long _old_y = y;
        lock = 0;
        x = _old_y;
        y = (_old_y + 1);
    }

    // 4. Post-condition assertion
    assert(!(((x == y) && !((lock == 1)))));
    /*@ assert !(((x == y) && !((lock == 1)))); */

    return 0;
}
