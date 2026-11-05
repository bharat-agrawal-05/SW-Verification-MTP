/*
 * Generated C verification file from: 97.c.sl
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
    (((i == 0) && (j == 0) && (x == 2) && (y == 0)) || ((0 <= i) && (0 <= j) && (0 <= y) && (!((y == 1)) || (i == j))));
  @*/

static inline _Bool c_inv_f(long long i, long long j, long long x, long long y) {
    return (((i == 0) && (j == 0) && (x == 2) && (y == 0)) || ((0 <= i) && (0 <= j) && (0 <= y) && (!((y == 1)) || (i == j))));
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
    y = 2;

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
    assert((!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!((i <= x)) && (y == 1) && !((i == j))))));
    /*@ assert (!(((i == i) && (j == j) && (x == x) && (y == y))) || !((!((i <= x)) && (y == 1) && !((i == j))))); */

    return 0;
}
