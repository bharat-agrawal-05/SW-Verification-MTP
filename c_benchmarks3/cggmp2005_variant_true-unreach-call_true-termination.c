/*
 * Generated C verification file from: cggmp2005_variant_true-unreach-call_true-termination.sl
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
  predicate inv_fun(integer lo, integer mid, integer hi) =
    ((lo >= 0) && (hi >= 0) && (mid >= 0) && ((lo == hi) || (mid > 0)) && (hi == (lo + (2 * mid))));
  @*/

static inline _Bool c_inv_fun(long long lo, long long mid, long long hi) {
    return ((lo >= 0) && (hi >= 0) && (mid >= 0) && ((lo == hi) || (mid > 0)) && (hi == (lo + (2 * mid))));
}

int main(void) {
    // 1. Variable declarations
    long long lo;
    long long mid;
    long long hi;

    // 2. Pre-condition initialization
    lo = 0;
    mid = nondet_long();
    hi = (2 * mid);
    if (!((mid > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(lo, mid, hi);
      @ loop assigns lo, hi, mid;
      @*/
    while ((mid > 0)) {
        lo = (lo + 1);
        hi = (hi - 1);
        mid = (mid - 1);
    }

    // 4. Post-condition assertion
    assert(((mid > 0) || (lo == hi)));
    /*@ assert ((mid > 0) || (lo == hi)); */

    return 0;
}
