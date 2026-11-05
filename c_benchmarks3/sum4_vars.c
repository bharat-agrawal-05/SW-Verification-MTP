/*
 * Generated C verification file from: sum4_vars.sl
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
  predicate inv_fun(integer i, integer sn, integer size, integer v1, integer v2, integer v3) =
    (((i <= size) || (sn == 0) || (sn == size)) && (sn == (-1 + i)));
  @*/

static inline _Bool c_inv_fun(long long i, long long sn, long long size, long long v1, long long v2, long long v3) {
    return (((i <= size) || (sn == 0) || (sn == size)) && (sn == (-1 + i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long sn;
    long long size;
    long long v1;
    long long v2;
    long long v3;

    // 2. Pre-condition initialization
    i = 1;
    sn = 0;
    size = nondet_long();
    v1 = nondet_long();
    v2 = nondet_long();
    v3 = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, sn, size, v1, v2, v3);
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
