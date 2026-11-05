/*
 * Generated C verification file from: 114.c.sl
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
  predicate inv_f(integer sn, integer x, integer tmp) =
    (((x == 0) && (sn == 0)) || ((sn == x) && (sn > 0)));
  @*/

static inline _Bool c_inv_f(long long sn, long long x, long long tmp) {
    return (((x == 0) && (sn == 0)) || ((sn == x) && (sn > 0)));
}

int main(void) {
    // 1. Variable declarations
    long long sn;
    long long x;
    long long tmp;

    // 2. Pre-condition initialization
    sn = 0;
    x = 0;
    tmp = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(sn, x, tmp);
      @ loop assigns sn, x;
      @*/
    while (1) {
        sn = (sn + 1);
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert((sn == -1));
    /*@ assert (sn == -1); */

    return 0;
}
