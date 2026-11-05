/*
 * Generated C verification file from: sum3.sl
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
  predicate inv_fun(integer x, integer sn) =
    (((0 <= sn) && (sn <= x) && ((sn + x) == (2 * x))) || ((0 <= sn) && (x < sn) && (sn == (x - 1))));
  @*/

static inline _Bool c_inv_fun(long long x, long long sn) {
    return (((0 <= sn) && (sn <= x) && ((sn + x) == (2 * x))) || ((0 <= sn) && (x < sn) && (sn == (x - 1))));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long sn;

    // 2. Pre-condition initialization
    x = 0;
    sn = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, sn);
      @ loop assigns x, sn;
      @*/
    while (1) {
        x = (x + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert(((sn == x) || (sn == -1)));
    /*@ assert ((sn == x) || (sn == -1)); */

    return 0;
}
