/*
 * Generated C verification file from: count_up_down_false-unreach-call_true-termination.sl
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
  predicate InvF(integer n, integer x, integer y) =
    \false;
  @*/

static inline _Bool c_InvF(long long n, long long x, long long y) {
    return false;
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    n = nondet_long();
    x = n;
    y = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(n, x, y);
      @ loop assigns x, y;
      @*/
    while ((x > 0)) {
        x = (x - 1);
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert(((x > 0) || (y == n)));
    /*@ assert ((x > 0) || (y == n)); */

    return 0;
}
