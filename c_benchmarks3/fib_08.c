/*
 * Generated C verification file from: fib_08.sl
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
  predicate pre_fun(integer x, integer y) =
    ((x == 0) && (y == 0));

  predicate trans_fun(integer x, integer y, integer x_next, integer y_next) =
    (((x_next == (x + 1)) && (y_next == (y + 100))) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 1))) || ((x < 0) && (x_next == x) && (y_next == (y - 1))) || ((x_next == x) && (y_next == y)));

  predicate post_fun(integer x, integer y) =
    ((x < 4) || (y > 2));

  predicate inv_fun(integer x, integer y) =
    (((0 <= x) && (0 <= y) && (x < 4) && (y > (x - 98))) || ((x >= 4) && (0 <= y) && (x < (y + 2))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y) {
    return ((x == 0) && (y == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long x_next, long long y_next) {
    return (((x_next == (x + 1)) && (y_next == (y + 100))) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 1))) || ((x < 0) && (x_next == x) && (y_next == (y - 1))) || ((x_next == x) && (y_next == y)));
}

static inline _Bool c_post_fun(long long x, long long y) {
    return ((x < 4) || (y > 2));
}

static inline _Bool c_inv_fun(long long x, long long y) {
    return (((0 <= x) && (0 <= y) && (x < 4) && (y > (x - 98))) || ((x >= 4) && (0 <= y) && (x < (y + 2))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y);
      @ loop assigns x, y;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_trans_fun(x, y, x_next, y_next)) break;

        // State updates
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y));
    /*@ assert post_fun(x, y); */

    return 0;
}
