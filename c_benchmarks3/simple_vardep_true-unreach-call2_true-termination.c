/*
 * Generated C verification file from: simple_vardep_true-unreach-call2_true-termination.sl
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
  predicate InvF(integer i, integer j, integer k) =
    ((i >= 0) && (j >= 0) && (k >= 0) && (k == (3 * i)) && (j == (2 * i)));
  @*/

static inline _Bool c_InvF(long long i, long long j, long long k) {
    return ((i >= 0) && (j >= 0) && (k >= 0) && (k == (3 * i)) && (j == (2 * i)));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long j;
    long long k;

    // 2. Pre-condition initialization
    i = 0;
    j = 0;
    k = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, j, k);
      @ loop assigns i, j, k;
      @*/
    while ((k < 268435455)) {
        i = (i + 1);
        j = (j + 2);
        k = (k + 3);
    }

    // 4. Post-condition assertion
    assert(((k < 268435455) || ((k == (3 * i)) && (j == (2 * i)))));
    /*@ assert ((k < 268435455) || ((k == (3 * i)) && (j == (2 * i)))); */

    return 0;
}
