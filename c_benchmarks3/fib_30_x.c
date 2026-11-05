/*
 * Generated C verification file from: fib_30_x.sl
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
  predicate inv_fun(integer i, integer c, integer n) =
    ((i >= 0) && (c >= 0) && (i <= n) && (c <= ((i * n) + ((i - 1) * i * 2))));
  @*/

static inline _Bool c_inv_fun(long long i, long long c, long long n) {
    return ((i >= 0) && (c >= 0) && (i <= n) && (c <= ((i * n) + ((i - 1) * i * 2))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long c;
    long long n;

    // 2. Pre-condition initialization
    i = 0;
    c = 0;
    n = nondet_long();
    if (!((n > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, c, n);
      @ loop assigns i, c;
      @*/
    while ((i < n)) {
        long long _old_i = i;
        i = (_old_i + 1);
        c = (c + _old_i);
    }

    // 4. Post-condition assertion
    assert((!((i >= n)) || (c >= 0)));
    /*@ assert ((i >= n) ==> (c >= 0)); */

    return 0;
}
