/*
 * Generated C verification file from: ex11_vars-new.sl
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
  predicate inv_fun(integer c, integer n, integer v1, integer v2, integer v3) =
    ((c >= 0) && (c <= n) && (c <= (n - 1)));
  @*/

static inline _Bool c_inv_fun(long long c, long long n, long long v1, long long v2, long long v3) {
    return ((c >= 0) && (c <= n) && (c <= (n - 1)));
}

int main(void) {
    // 1. Variable declarations
    long long c;
    long long n;
    long long v1;
    long long v2;
    long long v3;

    // 2. Pre-condition initialization
    c = 0;
    n = nondet_long();
    v1 = nondet_long();
    v2 = nondet_long();
    v3 = nondet_long();
    if (!((n > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c, n, v1, v2, v3);
      @ loop assigns c;
      @*/
    while ((c > n)) {
        c = (c + 1);
    }

    // 4. Post-condition assertion
    assert(!(((!((c == n)) && ((c < 0) || (c > n))) || ((c == n) && (n > -1)))));
    /*@ assert !(((!((c == n)) && ((c < 0) || (c > n))) || ((c == n) && (n > -1)))); */

    return 0;
}
