/*
 * Generated C verification file from: 110.c.sl
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
  predicate inv_f(integer i, integer n, integer sn) =
    ((!(((i == i) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == n)) && !((sn == 0))))) && (sn == (-1 + i)));
  @*/

static inline _Bool c_inv_f(long long i, long long n, long long sn) {
    return ((!(((i == i) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == n)) && !((sn == 0))))) && (sn == (-1 + i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long n;
    long long sn;

    // 2. Pre-condition initialization
    i = 1;
    n = nondet_long();
    sn = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, n, sn);
      @ loop assigns i, sn;
      @*/
    while ((i <= n)) {
        i = (i + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == n)) && !((sn == 0))))));
    /*@ assert (!(((i == i) && (n == n) && (sn == sn))) || !((!((i <= n)) && !((sn == n)) && !((sn == 0))))); */

    return 0;
}
