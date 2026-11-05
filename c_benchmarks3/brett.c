/*
 * Generated C verification file from: brett.sl
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
  predicate inv_fun(integer p, integer c, integer cl) =
    ((p <= 4) && (c <= (p + cl)));
  @*/

static inline _Bool c_inv_fun(long long p, long long c, long long cl) {
    return ((p <= 4) && (c <= (p + cl)));
}

int main(void) {
    // 1. Variable declarations
    long long p;
    long long c;
    long long cl;

    // 2. Pre-condition initialization
    p = 0;
    c = cl;
    cl = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(p, c, cl);
      @ loop assigns cl, p;
      @*/
    while ((p < 4) && (cl > 0)) {
        cl = (cl - 1);
        p = (p + 1);
    }

    // 4. Post-condition assertion
    assert((((p < 4) && (cl > 0)) || ((c < 4) || (p == 4))));
    /*@ assert (((p < 4) && (cl > 0)) || ((c < 4) || (p == 4))); */

    return 0;
}
