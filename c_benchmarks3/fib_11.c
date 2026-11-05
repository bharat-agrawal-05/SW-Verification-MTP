/*
 * Generated C verification file from: fib_11.sl
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
  predicate inv_fun(integer x, integer i, integer j) =
    ((i >= 0) && (j >= 0) && (i <= x) && (j == (2 * i)));
  @*/

static inline _Bool c_inv_fun(long long x, long long i, long long j) {
    return ((i >= 0) && (j >= 0) && (i <= x) && (j == (2 * i)));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long i;
    long long j;

    // 2. Pre-condition initialization
    x = nondet_long();
    i = 0;
    j = 0;
    if (!((x > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, i, j);
      @ loop assigns j, i;
      @*/
    while ((i < x)) {
        j = (j + 2);
        i = (i + 1);
    }

    // 4. Post-condition assertion
    assert((!(!((i < x))) || (j == (2 * x))));
    /*@ assert (!((i < x)) ==> (j == (2 * x))); */

    return 0;
}
