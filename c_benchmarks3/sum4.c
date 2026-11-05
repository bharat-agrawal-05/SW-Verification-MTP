/*
 * Generated C verification file from: sum4.sl
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
  predicate inv_fun(integer i, integer sn) =
    ((1 <= i) && (i <= 9) && (0 <= sn) && (sn <= 8) && (sn == (i - 1)));
  @*/

static inline _Bool c_inv_fun(long long i, long long sn) {
    return ((1 <= i) && (i <= 9) && (0 <= sn) && (sn <= 8) && (sn == (i - 1)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long sn;

    // 2. Pre-condition initialization
    i = 1;
    sn = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, sn);
      @ loop assigns i, sn;
      @*/
    while ((i <= 8)) {
        i = (i + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert(((i <= 8) || ((sn == 8) || (sn == 0))));
    /*@ assert ((i <= 8) || ((sn == 8) || (sn == 0))); */

    return 0;
}
