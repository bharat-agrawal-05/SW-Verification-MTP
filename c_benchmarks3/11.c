/*
 * Generated C verification file from: 11.c.sl
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
  predicate inv_f(integer x, integer y, integer tmp) =
    ((x >= (-(y))) && (x <= (y + 10)));
  @*/

static inline _Bool c_inv_f(long long x, long long y, long long tmp) {
    return ((x >= (-(y))) && (x <= (y + 10)));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long tmp;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    tmp = nondet_long();
    if (!((x >= 0))) return 0;
    if (!((x <= 10))) return 0;
    if (!((y <= 10))) return 0;
    if (!((y >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y, tmp);
      @ loop assigns x, y;
      @*/
    while (1) {
        x = (x + 10);
        y = (y + 10);
    }

    // 4. Post-condition assertion
    assert(!((y == 0)));
    /*@ assert !((y == 0)); */

    return 0;
}
