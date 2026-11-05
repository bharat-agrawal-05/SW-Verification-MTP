/*
 * Generated C verification file from: fig2.sl
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
  predicate pre_fun(integer x, integer y, integer z, integer w) =
    ((x == 0) && (y == 0) && (z == 0) && (w == 0));

  predicate trans_fun(integer x, integer y, integer z, integer w, integer x_next, integer y_next, integer z_next, integer w_next) =
    (((x_next == (x + 1)) && (y_next == (y + 2)) && (z_next == z) && (w_next == w)) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 3)) && (z_next == (z + 10)) && (w_next == (w + 10))) || ((x >= z) && (w > y) && (x_next == (0 - x)) && (y_next == (0 - y)) && (z_next == z) && (w_next == w)));

  predicate post_fun(integer x, integer y, integer z, integer w) =
    ((3 * x) >= y);

  predicate inv_fun(integer x, integer y, integer z, integer w) =
    (((3 * x) >= y) && (w == z) && (y >= x));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long z, long long w) {
    return ((x == 0) && (y == 0) && (z == 0) && (w == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long z, long long w, long long x_next, long long y_next, long long z_next, long long w_next) {
    return (((x_next == (x + 1)) && (y_next == (y + 2)) && (z_next == z) && (w_next == w)) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 3)) && (z_next == (z + 10)) && (w_next == (w + 10))) || ((x >= z) && (w > y) && (x_next == (0 - x)) && (y_next == (0 - y)) && (z_next == z) && (w_next == w)));
}

static inline _Bool c_post_fun(long long x, long long y, long long z, long long w) {
    return ((3 * x) >= y);
}

static inline _Bool c_inv_fun(long long x, long long y, long long z, long long w) {
    return (((3 * x) >= y) && (w == z) && (y >= x));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();
    long long w = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, z, w)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, z, w);
      @ loop assigns x, y, z, w;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();
        long long w_next = nondet_long();

        if (!c_trans_fun(x, y, z, w, x_next, y_next, z_next, w_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        z = z_next;
        w = w_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, z, w));
    /*@ assert post_fun(x, y, z, w); */

    return 0;
}
