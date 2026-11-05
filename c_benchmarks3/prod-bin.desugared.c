/*
 * Generated C verification file from: prod-bin.desugared.sl
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
  predicate pre_f(integer a, integer b, integer x, integer y, integer z) =
    ((a >= 0) && (b >= 0) && (x == a) && (y == b) && (z == 0));

  predicate trans_f(integer a, integer b, integer x, integer y, integer z, integer a_next, integer b_next, integer x_next, integer y_next, integer z_next) =
    (!((0 == y)) && (a_next == a) && (b_next == b) && ((!((1 == (y % 2))) && (x_next == (2 * x)) && (y_next == (y / 2)) && (z_next == z)) || ((1 == (y % 2)) && (x_next == x) && (z_next == (z + x)) && (y_next == (y - 1)))));

  predicate post_f(integer a, integer b, integer x, integer y, integer z) =
    (!((y == 0)) || (z == (a * b)));

  predicate inv_f(integer a, integer b, integer x, integer y, integer z) =
    ((a >= 0) && (b >= 0) && (x >= 0) && (y >= 0) && (z >= 0) && (((x * y) + z) == (a * b)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long a, long long b, long long x, long long y, long long z) {
    return ((a >= 0) && (b >= 0) && (x == a) && (y == b) && (z == 0));
}

static inline _Bool c_trans_f(long long a, long long b, long long x, long long y, long long z, long long a_next, long long b_next, long long x_next, long long y_next, long long z_next) {
    return (!((0 == y)) && (a_next == a) && (b_next == b) && ((!((1 == (y % 2))) && (x_next == (2 * x)) && (y_next == (y / 2)) && (z_next == z)) || ((1 == (y % 2)) && (x_next == x) && (z_next == (z + x)) && (y_next == (y - 1)))));
}

static inline _Bool c_post_f(long long a, long long b, long long x, long long y, long long z) {
    return (!((y == 0)) || (z == (a * b)));
}

static inline _Bool c_inv_f(long long a, long long b, long long x, long long y, long long z) {
    return ((a >= 0) && (b >= 0) && (x >= 0) && (y >= 0) && (z >= 0) && (((x * y) + z) == (a * b)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a = nondet_long();
    long long b = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(a, b, x, y, z)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(a, b, x, y, z);
      @ loop assigns a, b, x, y, z;
      @*/
    while (1) {
        long long a_next = nondet_long();
        long long b_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();

        if (!c_trans_f(a, b, x, y, z, a_next, b_next, x_next, y_next, z_next)) break;

        // State updates
        a = a_next;
        b = b_next;
        x = x_next;
        y = y_next;
        z = z_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(a, b, x, y, z));
    /*@ assert post_f(a, b, x, y, z); */

    return 0;
}
