/*
 * Generated C verification file from: ex11.sl
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
  predicate inv_fun(integer c) =
    !(((c < 0) || (c > 4)));
  @*/

static inline _Bool c_inv_fun(long long c) {
    return !(((c < 0) || (c > 4)));
}

int main(void) {
    // 1. Variable declarations
    long long c;

    // 2. Pre-condition initialization
    c = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c);
      @ loop assigns c;
      @*/
    while (!((c == 4))) {
        c = (c + 1);
    }

    // 4. Post-condition assertion
    assert(!((!((c == 4)) && ((c < 0) || (c > 4)))));
    /*@ assert !((!((c == 4)) && ((c < 0) || (c > 4)))); */

    return 0;
}
