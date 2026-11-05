/*
 * Generated C verification file from: tacas_vars.sl
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
  predicate inv_fun(integer i, integer j, integer x, integer y, integer z1, integer z2, integer z3) =
    (((i == x) && (j == y)) || ((x <= i) && (y <= j) && ((x - y) == (i - j))));
  @*/

static inline _Bool c_inv_fun(long long i, long long j, long long x, long long y, long long z1, long long z2, long long z3) {
    return (((i == x) && (j == y)) || ((x <= i) && (y <= j) && ((x - y) == (i - j))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long x;
    long long y;
    long long z1;
    long long z2;
    long long z3;

    // 2. Pre-condition initialization
    i = x;
    j = y;
    x = nondet_long();
    y = nondet_long();
    z1 = nondet_long();
    z2 = nondet_long();
    z3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, x, y, z1, z2, z3);
      @ loop assigns x, y;
      @*/
    while (!((x == 0))) {
        x = (x - 1);
        y = (y - 1);
    }

    // 4. Post-condition assertion
    assert((!((x == 0)) || (!((i == j)) || (y == 0))));
    /*@ assert (!((x == 0)) || (!((i == j)) || (y == 0))); */

    return 0;
}
