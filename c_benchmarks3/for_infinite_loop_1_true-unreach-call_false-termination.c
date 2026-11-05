/*
 * Generated C verification file from: for_infinite_loop_1_true-unreach-call_false-termination.sl
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
  predicate InvF(integer i, integer x, integer y, integer n) =
    ((x == 0) && (n > 0));
  @*/

static inline _Bool c_InvF(long long i, long long x, long long y, long long n) {
    return ((x == 0) && (n > 0));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long x;
    long long y;
    long long n;

    // 2. Pre-condition initialization
    i = 0;
    x = 0;
    y = 0;
    n = nondet_long();
    if (!((n > 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, x, y, n);
      @ loop assigns i;
      @*/
    while (1) {
        i = (i + 1);
    }

    // 4. Post-condition assertion
    assert((x == 0));
    /*@ assert (x == 0); */

    return 0;
}
