/*
 * Generated C verification file from: fib_23_x.sl
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
  predicate inv_fun(integer i, integer sum, integer n) =
    ((sum <= (i * (i + 1))) && (i >= 0) && (sum >= 0));
  @*/

static inline _Bool c_inv_fun(long long i, long long sum, long long n) {
    return ((sum <= (i * (i + 1))) && (i >= 0) && (sum >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long sum;
    long long n;

    // 2. Pre-condition initialization
    i = 0;
    sum = 0;
    n = nondet_long();
    if (!((n >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, sum, n);
      @ loop assigns i, sum;
      @*/
    while ((i < n)) {
        long long _old_i = i;
        i = (_old_i + 1);
        sum = (sum + _old_i);
    }

    // 4. Post-condition assertion
    assert((!((i >= n)) || (sum >= 0)));
    /*@ assert ((i >= n) ==> (sum >= 0)); */

    return 0;
}
