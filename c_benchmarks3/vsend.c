/*
 * Generated C verification file from: vsend.sl
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
  predicate inv_fun(integer c, integer i) =
    (((c <= 57) && (c >= 48)) ==> (i >= 0));
  @*/

static inline _Bool c_inv_fun(long long c, long long i) {
    return (!(((c <= 57) && (c >= 48))) || (i >= 0));
}

int main(void) {
    // 1. Variable declarations
    long long c;
    long long i;

    // 2. Pre-condition initialization
    c = nondet_long();
    i = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c, i);
      @ loop assigns i;
      @*/
    while ((c > 48) && (c < 57)) {
        i = ((i + i) + (c - 48));
    }

    // 4. Post-condition assertion
    assert(((c > 57) || ((c < 48) || (i >= 0))));
    /*@ assert ((c > 57) || ((c < 48) || (i >= 0))); */

    return 0;
}
