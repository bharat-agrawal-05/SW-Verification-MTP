/*
 * Generated C verification file from: ex11_simpl-new.sl
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
  predicate inv_fun(integer c, integer n) =
    (((0 <= c) && (c <= n)) && ((c + 1) <= n));
  @*/

static inline _Bool c_inv_fun(long long c, long long n) {
    return (((0 <= c) && (c <= n)) && ((c + 1) <= n));
}

int main(void) {
    // 1. Variable declarations
    long long c;
    long long n;

    // 2. Pre-condition initialization
    c = 0;
    n = nondet_long();
    if (!((n > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c, n);
      @ loop assigns c;
      @*/
    while ((c > n)) {
        c = (c + 1);
    }

    // 4. Post-condition assertion
    assert((((c == n) || ((c >= 0) && (c <= n))) && (!((c == n)) || (n > -1))));
    /*@ assert (((c == n) || ((c >= 0) && (c <= n))) && (!((c == n)) || (n > -1))); */

    return 0;
}
