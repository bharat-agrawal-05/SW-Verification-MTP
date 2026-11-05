/*
 * Generated C verification file from: sum4_simp.sl
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
  predicate inv_fun(integer i, integer sn, integer size) =
    (((i == (sn + 1)) && (sn == 0)) || (!((i <= size)) && (sn == size)) || ((sn > 0) && (sn < size) && (i == (sn + 1))));
  @*/

static inline _Bool c_inv_fun(long long i, long long sn, long long size) {
    return (((i == (sn + 1)) && (sn == 0)) || (!((i <= size)) && (sn == size)) || ((sn > 0) && (sn < size) && (i == (sn + 1))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long sn;
    long long size;

    // 2. Pre-condition initialization
    i = 1;
    sn = 0;
    size = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, sn, size);
      @ loop assigns i, sn;
      @*/
    while ((i <= size)) {
        i = (i + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert(((i <= size) || ((sn == size) || (sn == 0))));
    /*@ assert ((i <= size) || ((sn == size) || (sn == 0))); */

    return 0;
}
