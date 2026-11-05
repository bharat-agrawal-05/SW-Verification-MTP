/*
 * Generated C verification file from: sum03_true-unreach-call_false-termination.sl
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
  predicate InvF(integer sn, integer loop1, integer n1, integer x) =
    ((sn >= 0) && (x >= 0) && (loop1 >= 0) && (n1 >= 0) && (((loop1 == 0) && (n1 == 0) && (x == 0) && (sn == 0)) || (sn == (x * 2))));
  @*/

static inline _Bool c_InvF(long long sn, long long loop1, long long n1, long long x) {
    return ((sn >= 0) && (x >= 0) && (loop1 >= 0) && (n1 >= 0) && (((loop1 == 0) && (n1 == 0) && (x == 0) && (sn == 0)) || (sn == (x * 2))));
}

int main(void) {
    // 1. Variable declarations
    long long sn;
    long long loop1;
    long long n1;
    long long x;

    // 2. Pre-condition initialization
    sn = 0;
    loop1 = nondet_long();
    n1 = nondet_long();
    x = 0;
    if (!((loop1 >= 0))) return 0;
    if (!((n1 >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(sn, loop1, n1, x);
      @ loop assigns sn, x;
      @*/
    while (1) {
        sn = (sn + 2);
        x = (x + 1);
    }

    // 4. Post-condition assertion
    assert(((sn == (x * 2)) || (sn == 0)));
    /*@ assert ((sn == (x * 2)) || (sn == 0)); */

    return 0;
}
