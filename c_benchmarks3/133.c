/*
 * Generated C verification file from: 133.c.sl
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
  predicate inv_f(integer n, integer x) =
    (!(((n == n) && (x == x))) || !((!((x < n)) && !((x == n)))));
  @*/

static inline _Bool c_inv_f(long long n, long long x) {
    return (!(((n == n) && (x == x))) || !((!((x < n)) && !((x == n)))));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;

    // 2. Pre-condition initialization
    n = nondet_long();
    x = 0;
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, x);
      @ loop assigns x;
      @*/
    while ((x < n)) {
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((x == n));
    /*@ assert (x == n); */

    return 0;
}
