/*
 * Generated C verification file from: 4.c.sl
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
  predicate pre_f(integer x, integer y, integer z, integer x_0, integer x_1, integer x_2, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    ((x == x_0) && (x_0 == 0));

  predicate trans_f(integer x, integer y, integer z, integer x_0, integer x_1, integer x_2, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0, integer x_next, integer y_next, integer z_next, integer x_0_next, integer x_1_next, integer x_2_next, integer y_0_next, integer y_1_next, integer y_2_next, integer y_3_next, integer z_0_next) =
    (((x_1 == x) && (y_1 == y) && (x_1 == x_next) && (y_1 == y_next) && (y == y_next) && (z == z_next)) || ((x_1 == x) && (y_1 == y) && (x_1 < 500) && (x_2 == (x_1 + 1)) && (z_0 <= y_1) && (y_2 == z_0) && (y_3 == y_2) && (x_2 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)) || ((x_1 == x) && (y_1 == y) && (x_1 < 500) && (x_2 == (x_1 + 1)) && !((z_0 <= y_1)) && (y_3 == y_1) && (x_2 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)));

  predicate post_f(integer x, integer y, integer z, integer x_0, integer x_1, integer x_2, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    (!(((x == x_1) && (y == y_1) && (z == z_0))) || !((!((x_1 < 500)) && !((z_0 >= y_1)))));

  predicate inv_f(integer x, integer y, integer z, integer x_0, integer x_1, integer x_2, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    (((x == x_1) && (y == y_1) && !((x_1 < 500))) ==> (z >= y_1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long x, long long y, long long z, long long x_0, long long x_1, long long x_2, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return ((x == x_0) && (x_0 == 0));
}

static inline _Bool c_trans_f(long long x, long long y, long long z, long long x_0, long long x_1, long long x_2, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0, long long x_next, long long y_next, long long z_next, long long x_0_next, long long x_1_next, long long x_2_next, long long y_0_next, long long y_1_next, long long y_2_next, long long y_3_next, long long z_0_next) {
    return (((x_1 == x) && (y_1 == y) && (x_1 == x_next) && (y_1 == y_next) && (y == y_next) && (z == z_next)) || ((x_1 == x) && (y_1 == y) && (x_1 < 500) && (x_2 == (x_1 + 1)) && (z_0 <= y_1) && (y_2 == z_0) && (y_3 == y_2) && (x_2 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)) || ((x_1 == x) && (y_1 == y) && (x_1 < 500) && (x_2 == (x_1 + 1)) && !((z_0 <= y_1)) && (y_3 == y_1) && (x_2 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)));
}

static inline _Bool c_post_f(long long x, long long y, long long z, long long x_0, long long x_1, long long x_2, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return (!(((x == x_1) && (y == y_1) && (z == z_0))) || !((!((x_1 < 500)) && !((z_0 >= y_1)))));
}

static inline _Bool c_inv_f(long long x, long long y, long long z, long long x_0, long long x_1, long long x_2, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return (!(((x == x_1) && (y == y_1) && !((x_1 < 500)))) || (z >= y_1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();
    long long x_0 = nondet_long();
    long long x_1 = nondet_long();
    long long x_2 = nondet_long();
    long long y_0 = nondet_long();
    long long y_1 = nondet_long();
    long long y_2 = nondet_long();
    long long y_3 = nondet_long();
    long long z_0 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0);
      @ loop assigns x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();
        long long x_0_next = nondet_long();
        long long x_1_next = nondet_long();
        long long x_2_next = nondet_long();
        long long y_0_next = nondet_long();
        long long y_1_next = nondet_long();
        long long y_2_next = nondet_long();
        long long y_3_next = nondet_long();
        long long z_0_next = nondet_long();

        if (!c_trans_f(x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0, x_next, y_next, z_next, x_0_next, x_1_next, x_2_next, y_0_next, y_1_next, y_2_next, y_3_next, z_0_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        z = z_next;
        x_0 = x_0_next;
        x_1 = x_1_next;
        x_2 = x_2_next;
        y_0 = y_0_next;
        y_1 = y_1_next;
        y_2 = y_2_next;
        y_3 = y_3_next;
        z_0 = z_0_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0));
    /*@ assert post_f(x, y, z, x_0, x_1, x_2, y_0, y_1, y_2, y_3, z_0); */

    return 0;
}
