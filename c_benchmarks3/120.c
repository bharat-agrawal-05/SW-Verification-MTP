/*
 * Generated C verification file from: 120.c.sl
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
  predicate inv_f(integer i, integer sn) =
    (((sn == 0) && (i == 1)) || ((sn >= 1) && (sn <= 8) && (i >= 2) && (sn == (i - 1))));
  @*/

static inline _Bool c_inv_f(long long i, long long sn) {
    return (((sn == 0) && (i == 1)) || ((sn >= 1) && (sn <= 8) && (i >= 2) && (sn == (i - 1))));
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
      @ loop invariant inv_f(i, sn);
      @ loop assigns i, sn;
      @*/
    while ((i <= 8)) {
        i = (i + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (sn == sn))) || !((!((i <= 8)) && !((sn == 8)) && !((sn == 0))))));
    /*@ assert (!(((i == i) && (sn == sn))) || !((!((i <= 8)) && !((sn == 8)) && !((sn == 0))))); */

    return 0;
}
