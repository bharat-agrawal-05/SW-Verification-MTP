/*
 * Generated C verification file from: jm2006_true-unreach-call_true-termination.sl
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
  predicate inv_fun(integer i, integer j, integer x, integer y) =
    (((i <= j) && (x <= y) && ((i + y) == (j + x))) || ((i >= j) && (x >= y) && ((i + y) == (j + x))));
  @*/

static inline _Bool c_inv_fun(long long i, long long j, long long x, long long y) {
    return (((i <= j) && (x <= y) && ((i + y) == (j + x))) || ((i >= j) && (x >= y) && ((i + y) == (j + x))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    i = nondet_long();
    j = nondet_long();
    x = i;
    y = j;
    if (!((i >= 0))) return 0;
    if (!((j >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, x, y);
      @ loop assigns x, y;
      @*/
    while (!((x == 0))) {
        x = (x - 1);
        y = (y - 1);
    }

    // 4. Post-condition assertion
    assert((!((x == 0)) || (!((i == j)) || (y == 0))));
    /*@ assert (!((x == 0)) || ((i == j) ==> (y == 0))); */

    return 0;
}
