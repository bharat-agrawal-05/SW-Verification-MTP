/*
 * Generated C verification file from: mannadiv.sl
 * SMT-LIB Logic: NIA
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
  predicate PreF(integer x1, integer x2, integer y1, integer y2, integer y3) =
    ((x1 >= 0) && (x2 > 0) && (y1 == 0) && (y2 == 0) && (y3 == x1));

  predicate TransF(integer x1, integer x2, integer y1, integer y2, integer y3, integer x1_next, integer x2_next, integer y1_next, integer y2_next, integer y3_next) =
    (!((y3 == 0)) && (x1_next == x1) && (x2_next == x2) && (((x2 == (y2 + 1)) && (y1_next == (y1 + 1)) && (y2_next == 0) && (y3_next == (y3 - 1))) || (!((x2 == (y2 + 1))) && (y1_next == y1) && (y2_next == (y2 + 1)) && (y3_next == (y3 - 1)))));

  predicate PostF(integer x1, integer x2, integer y1, integer y2, integer y3) =
    ((y3 == 0) ==> ((y2 == (x1 % x2)) && (y1 == (x1 / x2))));

  predicate InvF(integer x1, integer x2, integer y1, integer y2, integer y3) =
    ((x1 >= 0) && (x2 > 0) && (y1 == ((x1 - y3) / x2)) && (y2 == ((x1 - y3) % x2)) && (y3 >= 0) && (y3 <= x1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return ((x1 >= 0) && (x2 > 0) && (y1 == 0) && (y2 == 0) && (y3 == x1));
}

static inline _Bool c_TransF(long long x1, long long x2, long long y1, long long y2, long long y3, long long x1_next, long long x2_next, long long y1_next, long long y2_next, long long y3_next) {
    return (!((y3 == 0)) && (x1_next == x1) && (x2_next == x2) && (((x2 == (y2 + 1)) && (y1_next == (y1 + 1)) && (y2_next == 0) && (y3_next == (y3 - 1))) || (!((x2 == (y2 + 1))) && (y1_next == y1) && (y2_next == (y2 + 1)) && (y3_next == (y3 - 1)))));
}

static inline _Bool c_PostF(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return (!((y3 == 0)) || ((y2 == (x1 % x2)) && (y1 == (x1 / x2))));
}

static inline _Bool c_InvF(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return ((x1 >= 0) && (x2 > 0) && (y1 == ((x1 - y3) / x2)) && (y2 == ((x1 - y3) % x2)) && (y3 >= 0) && (y3 <= x1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long y1 = nondet_long();
    long long y2 = nondet_long();
    long long y3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(x1, x2, y1, y2, y3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(x1, x2, y1, y2, y3);
      @ loop assigns x1, x2, y1, y2, y3;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long y1_next = nondet_long();
        long long y2_next = nondet_long();
        long long y3_next = nondet_long();

        if (!c_TransF(x1, x2, y1, y2, y3, x1_next, x2_next, y1_next, y2_next, y3_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        y1 = y1_next;
        y2 = y2_next;
        y3 = y3_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(x1, x2, y1, y2, y3));
    /*@ assert PostF(x1, x2, y1, y2, y3); */

    return 0;
}
