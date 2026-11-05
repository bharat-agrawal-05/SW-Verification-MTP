/*
 * Generated C verification file from: const_false-unreach-call1.sl
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
  predicate InvF(integer x, integer y) =
    (((x == 1) && (y < 1024)) || (x == 0));
  @*/

static inline _Bool c_InvF(long long x, long long y) {
    return (((x == 1) && (y < 1024)) || (x == 0));
}

int main(void) {
    // 1. Variable declarations
    long long x;
    long long y;

    // 2. Pre-condition initialization
    x = 1;
    y = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(x, y);
      @ loop assigns x, y;
      @*/
    while ((y < 1024)) {
        x = 0;
        y = (y + 1);
    }

    // 4. Post-condition assertion
    assert(((y < 1024) || !((x == 1))));
    /*@ assert ((y < 1024) || !((x == 1))); */

    return 0;
}
