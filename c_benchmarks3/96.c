/*
 * Generated C verification file from: 96.c.sl
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
    ((i == j) && (1 == y));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long x, long long y) {
    return ((i == j) && (1 == y));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    x = nondet_long();
    y = 1;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, j, x, y);
      @ loop assigns i, j;
      @*/
    while ((i <= x)) {
        i = (i + 1);
        j = (j + y);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!((i <= x)) && !((i == j)) && !(!((y == 1)))))));
    /*@ assert (!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!((i <= x)) && !((i == j)) && !(!((y == 1)))))); */

    return 0;
}
