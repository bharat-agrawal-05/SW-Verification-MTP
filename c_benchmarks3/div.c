/*
 * Generated C verification file from: div.sl
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
  predicate pre_f(integer x1, integer x2, integer y1, integer y2, integer y3) =
    ((x1 >= 0) && (x2 > 0) && (y1 == 0) && (y2 == 0) && (y3 == x1));

  predicate trans_f(integer x1, integer x2, integer y1, integer y2, integer y3, integer x1_next, integer x2_next, integer y1_next, integer y2_next, integer y3_next) =
    (!((y3 == 0)) && (x1_next == x1) && (x2_next == x2) && (((x2 == (y2 + 1)) && (y1_next == (y1 + 1)) && (0 == y2_next) && (y3_next == (y3 - 1))) || (!((x2 == (y2 + 1))) && (y1_next == y1) && (y2_next == (y2 + 1)) && (y3_next == (y3 - 1)))));

  predicate post_f(integer x1, integer x2, integer y1, integer y2, integer y3) =
    (!((y3 == 0)) || ((y2 == (x1 % x2)) && (y1 == (x1 / x2))));

  predicate inv_f(integer x1, integer x2, integer y1, integer y2, integer y3) =
    ((y1 >= 0) && (y2 >= 0) && (y3 >= 0) && (y3 <= x1) && (y2 <= (x2 - 1)) && (((y1 * x2) + y2) == (x1 - y3)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return ((x1 >= 0) && (x2 > 0) && (y1 == 0) && (y2 == 0) && (y3 == x1));
}

static inline _Bool c_trans_f(long long x1, long long x2, long long y1, long long y2, long long y3, long long x1_next, long long x2_next, long long y1_next, long long y2_next, long long y3_next) {
    return (!((y3 == 0)) && (x1_next == x1) && (x2_next == x2) && (((x2 == (y2 + 1)) && (y1_next == (y1 + 1)) && (0 == y2_next) && (y3_next == (y3 - 1))) || (!((x2 == (y2 + 1))) && (y1_next == y1) && (y2_next == (y2 + 1)) && (y3_next == (y3 - 1)))));
}

static inline _Bool c_post_f(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return (!((y3 == 0)) || ((y2 == (x1 % x2)) && (y1 == (x1 / x2))));
}

static inline _Bool c_inv_f(long long x1, long long x2, long long y1, long long y2, long long y3) {
    return ((y1 >= 0) && (y2 >= 0) && (y3 >= 0) && (y3 <= x1) && (y2 <= (x2 - 1)) && (((y1 * x2) + y2) == (x1 - y3)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long y1 = nondet_long();
    long long y2 = nondet_long();
    long long y3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(x1, x2, y1, y2, y3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x1, x2, y1, y2, y3);
      @ loop assigns x1, x2, y1, y2, y3;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long y1_next = nondet_long();
        long long y2_next = nondet_long();
        long long y3_next = nondet_long();

        if (!c_trans_f(x1, x2, y1, y2, y3, x1_next, x2_next, y1_next, y2_next, y3_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        y1 = y1_next;
        y2 = y2_next;
        y3 = y3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(x1, x2, y1, y2, y3));
    /*@ assert post_f(x1, x2, y1, y2, y3); */

    return 0;
}
