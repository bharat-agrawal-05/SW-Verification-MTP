/*
 * Generated C verification file from: 119.c.sl
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
  predicate inv_f(integer i, integer size, integer sn) =
    (((sn == 0) && (i == 1)) || ((i <= size) && (sn == (i - 1))) || (!((i <= size)) && (sn == size)));
  @*/

static inline _Bool c_inv_f(long long i, long long size, long long sn) {
    return (((sn == 0) && (i == 1)) || ((i <= size) && (sn == (i - 1))) || (!((i <= size)) && (sn == size)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long size;
    long long sn;

    // 2. Pre-condition initialization
    i = 1;
    size = nondet_long();
    sn = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, size, sn);
      @ loop assigns i, sn;
      @*/
    while ((i <= size)) {
        i = (i + 1);
        sn = (sn + 1);
    }

    // 4. Post-condition assertion
    assert((!(((i == i) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == 0)) && !((sn == size))))));
    /*@ assert (!(((i == i) && (size == size) && (sn == sn))) || !((!((i <= size)) && !((sn == 0)) && !((sn == size))))); */

    return 0;
}
