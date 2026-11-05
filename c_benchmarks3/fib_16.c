/*
 * Generated C verification file from: fib_16.sl
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
  predicate inv_fun(integer x, integer y, integer i, integer j) =
    (!((i == j)) || ((y <= x) && ((x - y) <= (i - j))));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long j) {
    return (!((i == j)) || ((y <= x) && ((x - y) <= (i - j))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long i;
    long long j;

    // 2. Pre-condition initialization
    x = i;
    y = j;
    i = nondet_long();
    j = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, j);
      @ loop assigns x, y;
      @*/
    while (!((x == 0))) {
        x = (x - 1);
        y = (y - 1);
    }

    // 4. Post-condition assertion
    assert((!((x == 0)) || (!((i == j)) || (y == 0))));
    /*@ assert ((x == 0) ==> (!((i == j)) || (y == 0))); */

    return 0;
}
