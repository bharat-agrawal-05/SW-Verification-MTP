/*
 * Generated C verification file from: 124.c.sl
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
  predicate inv_f(integer i, integer j, integer x, integer y) =
    ((j + x) == (i + y));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long x, long long y) {
    return ((j + x) == (i + y));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    i = x;
    j = y;
    x = nondet_long();
    y = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, x, y);
      @ loop assigns x, y;
      @*/
    while (!((x == 0))) {
        x = (x - 1);
        y = (y - 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!(!((x == 0))) && (i == j) && !((y == 0))))));
    /*@ assert (!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!(!((x == 0))) && (i == j) && !((y == 0))))); */

    return 0;
}
