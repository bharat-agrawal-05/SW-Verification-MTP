/*
 * Generated C verification file from: fib_10.sl
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
  predicate pre_fun(integer x, integer y, integer w, integer z) =
    ((w == 1) && (z == 0) && (x == 0) && (y == 0));

  predicate trans_fun(integer x, integer y, integer w, integer z, integer x_next, integer y_next, integer w_next, integer z_next) =
    (((w == 1) && (z == 0) && (x_next == (x + 1)) && (w_next == 0) && (y_next == (y + 1)) && (z_next == 1)) || (!((w == 1)) && (z == 0) && (x_next == x) && (w_next == w) && (y_next == (y + 1)) && (z_next == 1)) || ((w == 1) && !((z == 0)) && (x_next == (x + 1)) && (w_next == 0) && (y_next == y) && (z_next == z)) || (!((w == 1)) && !((z == 0)) && (x_next == x) && (w_next == w) && (y_next == y) && (z_next == z)));

  predicate post_fun(integer x, integer y, integer w, integer z) =
    (x == y);

  predicate inv_fun(integer x, integer y, integer w, integer z) =
    (((w == 1) && (z == 0) && (y == x)) || (!((z == 0)) && (x == y) && (w == 0)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long w, long long z) {
    return ((w == 1) && (z == 0) && (x == 0) && (y == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long w, long long z, long long x_next, long long y_next, long long w_next, long long z_next) {
    return (((w == 1) && (z == 0) && (x_next == (x + 1)) && (w_next == 0) && (y_next == (y + 1)) && (z_next == 1)) || (!((w == 1)) && (z == 0) && (x_next == x) && (w_next == w) && (y_next == (y + 1)) && (z_next == 1)) || ((w == 1) && !((z == 0)) && (x_next == (x + 1)) && (w_next == 0) && (y_next == y) && (z_next == z)) || (!((w == 1)) && !((z == 0)) && (x_next == x) && (w_next == w) && (y_next == y) && (z_next == z)));
}

static inline _Bool c_post_fun(long long x, long long y, long long w, long long z) {
    return (x == y);
}

static inline _Bool c_inv_fun(long long x, long long y, long long w, long long z) {
    return (((w == 1) && (z == 0) && (y == x)) || (!((z == 0)) && (x == y) && (w == 0)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long w = nondet_long();
    long long z = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, w, z)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, w, z);
      @ loop assigns x, y, w, z;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long w_next = nondet_long();
        long long z_next = nondet_long();

        if (!c_trans_fun(x, y, w, z, x_next, y_next, w_next, z_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        w = w_next;
        z = z_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, w, z));
    /*@ assert post_fun(x, y, w, z); */

    return 0;
}
