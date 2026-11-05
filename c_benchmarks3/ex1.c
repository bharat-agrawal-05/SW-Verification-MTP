/*
 * Generated C verification file from: ex1.sl
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
  predicate pre_fun(integer x, integer y, integer xa, integer ya) =
    ((xa == 0) && (ya == 0));

  predicate trans_fun(integer x, integer y, integer xa, integer ya, integer x_next, integer y_next, integer xa_next, integer ya_next) =
    ((x_next == (1 + (xa + (2 * ya)))) && ((y_next == ((ya - (2 * xa)) + x_next)) || (y_next == ((ya - (2 * xa)) - x_next))) && (xa_next == (x_next - (2 * y_next))) && (ya_next == ((2 * x_next) + y_next)));

  predicate post_fun(integer x, integer y, integer xa, integer ya) =
    ((xa + (2 * ya)) >= 0);

  predicate inv_fun(integer x, integer y, integer xa, integer ya) =
    (((xa + (2 * ya)) >= 0) && ((xa == 0) || !(((xa == ((ya - xa) % 3)) && (ya == ((xa - ya) % 3))))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long xa, long long ya) {
    return ((xa == 0) && (ya == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long xa, long long ya, long long x_next, long long y_next, long long xa_next, long long ya_next) {
    return ((x_next == (1 + (xa + (2 * ya)))) && ((y_next == ((ya - (2 * xa)) + x_next)) || (y_next == ((ya - (2 * xa)) - x_next))) && (xa_next == (x_next - (2 * y_next))) && (ya_next == ((2 * x_next) + y_next)));
}

static inline _Bool c_post_fun(long long x, long long y, long long xa, long long ya) {
    return ((xa + (2 * ya)) >= 0);
}

static inline _Bool c_inv_fun(long long x, long long y, long long xa, long long ya) {
    return (((xa + (2 * ya)) >= 0) && ((xa == 0) || !(((xa == ((ya - xa) % 3)) && (ya == ((xa - ya) % 3))))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long xa = nondet_long();
    long long ya = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, xa, ya)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, xa, ya);
      @ loop assigns x, y, xa, ya;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long xa_next = nondet_long();
        long long ya_next = nondet_long();

        if (!c_trans_fun(x, y, xa, ya, x_next, y_next, xa_next, ya_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        xa = xa_next;
        ya = ya_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, xa, ya));
    /*@ assert post_fun(x, y, xa, ya); */

    return 0;
}
