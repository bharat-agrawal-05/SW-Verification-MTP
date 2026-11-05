/*
 * Generated C verification file from: poly2.sl
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
  predicate pre_fun(integer c, integer x, integer y, integer x0, integer y0) =
    ((c == 0) && (x == x0) && (y == y0));

  predicate trans_fun(integer c, integer x, integer y, integer x0, integer y0, integer c_next, integer x_next, integer y_next, integer x0_next, integer y0_next) =
    ((x0_next == x0) && (y0_next == y0) && (((x < y) && (c_next == c) && (x_next == x) && (y_next == y)) || ((x >= y) && (c_next == (c + 1)) && (x_next <= (x - 1)) && (y_next == y)) || ((x >= y) && (c_next == (c + 1)) && (y_next >= (y + 1)) && (x_next == x))));

  predicate post_fun(integer c, integer x, integer y, integer x0, integer y0) =
    ((x >= y) ==> (((x0 >= y0)) ? ((c <= (x0 - y0))) : ((c == 0))));

  predicate inv_fun(integer c, integer x, integer y, integer x0, integer y0) =
    ((!((x >= y)) || (x0 >= y0)) && ((x0 + (-1 * c) + (-1 * x) + y) >= y0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long c, long long x, long long y, long long x0, long long y0) {
    return ((c == 0) && (x == x0) && (y == y0));
}

static inline _Bool c_trans_fun(long long c, long long x, long long y, long long x0, long long y0, long long c_next, long long x_next, long long y_next, long long x0_next, long long y0_next) {
    return ((x0_next == x0) && (y0_next == y0) && (((x < y) && (c_next == c) && (x_next == x) && (y_next == y)) || ((x >= y) && (c_next == (c + 1)) && (x_next <= (x - 1)) && (y_next == y)) || ((x >= y) && (c_next == (c + 1)) && (y_next >= (y + 1)) && (x_next == x))));
}

static inline _Bool c_post_fun(long long c, long long x, long long y, long long x0, long long y0) {
    return (!((x >= y)) || (((x0 >= y0)) ? ((c <= (x0 - y0))) : ((c == 0))));
}

static inline _Bool c_inv_fun(long long c, long long x, long long y, long long x0, long long y0) {
    return ((!((x >= y)) || (x0 >= y0)) && ((x0 + (-1 * c) + (-1 * x) + y) >= y0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long x0 = nondet_long();
    long long y0 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(c, x, y, x0, y0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c, x, y, x0, y0);
      @ loop assigns c, x, y, x0, y0;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long x0_next = nondet_long();
        long long y0_next = nondet_long();

        if (!c_trans_fun(c, x, y, x0, y0, c_next, x_next, y_next, x0_next, y0_next)) break;

        // State updates
        c = c_next;
        x = x_next;
        y = y_next;
        x0 = x0_next;
        y0 = y0_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(c, x, y, x0, y0));
    /*@ assert post_fun(c, x, y, x0, y0); */

    return 0;
}
