/*
 * Generated C verification file from: gr2006_true-unreach-call_true-termination.sl
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
  // ACSL Logic Predicates
  predicate PreF(integer x, integer y) =
    ((x == 0) && (y == 1));

  predicate TransF(integer x, integer y, integer x_next, integer y_next) =
    ((y >= 0) && (x_next == (x + 1)) && (((x_next < 50)) ? ((y_next == (y + 1))) : ((y_next == (y - 1)))));

  predicate PostF(integer x, integer y) =
    ((y >= 0) || (x == 100));

  predicate InvF(integer x, integer y) =
    (((x >= 0) && (x < 50) && (y == (x + 1))) || ((x >= 50) && (x <= 100) && (y == (99 - x))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long x, long long y) {
    return ((x == 0) && (y == 1));
}

static inline _Bool c_TransF(long long x, long long y, long long x_next, long long y_next) {
    return ((y >= 0) && (x_next == (x + 1)) && (((x_next < 50)) ? ((y_next == (y + 1))) : ((y_next == (y - 1)))));
}

static inline _Bool c_PostF(long long x, long long y) {
    return ((y >= 0) || (x == 100));
}

static inline _Bool c_InvF(long long x, long long y) {
    return (((x >= 0) && (x < 50) && (y == (x + 1))) || ((x >= 50) && (x <= 100) && (y == (99 - x))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(x, y);
      @ loop assigns x, y;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_TransF(x, y, x_next, y_next)) break;

        // State updates
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(x, y));
    /*@ assert PostF(x, y); */

    return 0;
}
