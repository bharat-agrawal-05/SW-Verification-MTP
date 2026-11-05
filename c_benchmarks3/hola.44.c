/*
 * Generated C verification file from: hola.44.sl
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
    (((0 <= i) && (i <= x) && (j == (y * i))) || ((0 <= i) && (x < i) && ((i == j) || !((y == 1)))));
  @*/

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long j) {
    return (((0 <= i) && (i <= x) && (j == (y * i))) || ((0 <= i) && (x < i) && ((i == j) || !((y == 1)))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;
    long long i;
    long long j;

    // 2. Pre-condition initialization
    x = nondet_long();
    y = nondet_long();
    i = 0;
    j = 0;
    if (!(((y == 1) || (y == 2)))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, j);
      @ loop assigns i, j;
      @*/
    while ((i <= x)) {
        i = (i + 1);
        j = (j + y);
    }

    // 4. Post-condition assertion
    assert(((i <= x) || (!((y == 1)) || (i == j))));
    /*@ assert ((i <= x) || (!((y == 1)) || (i == j))); */

    return 0;
}
