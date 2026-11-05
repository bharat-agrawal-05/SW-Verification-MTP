/*
 * Generated C verification file from: 71.c.sl
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
  predicate pre_f(integer c, integer y, integer z, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer y_0, integer z_0, integer z_1, integer z_2, integer z_3, integer z_4) =
    ((c == c_1) && (y == y_0) && (z == z_1) && (c_1 == 0) && (y_0 >= 0) && (y_0 >= 127) && (z_1 == (36 * y_0)));

  predicate trans_f(integer c, integer y, integer z, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer y_0, integer z_0, integer z_1, integer z_2, integer z_3, integer z_4, integer c_next, integer y_next, integer z_next, integer tmp_next, integer c_0_next, integer c_1_next, integer c_2_next, integer c_3_next, integer c_4_next, integer y_0_next, integer z_0_next, integer z_1_next, integer z_2_next, integer z_3_next, integer z_4_next) =
    (((c_2 == c) && (z_2 == z) && (c_2 == c_next) && (z_2 == z_next) && (c == c_next) && (y == y_next) && (z == z_next) && (tmp == tmp_next)) || ((c_2 == c) && (z_2 == z) && (c_2 < 36) && (z_3 == (z_2 + 1)) && (c_3 == (c_2 + 1)) && (c_4 == c_3) && (z_4 == z_3) && (c_4 == c_next) && (z_4 == z_next) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)) || ((c_2 == c) && (z_2 == z) && !((c_2 < 36)) && (c_4 == c_2) && (z_4 == z_2) && (c_4 == c_next) && (z_4 == z_next) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)));

  predicate post_f(integer c, integer y, integer z, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer y_0, integer z_0, integer z_1, integer z_2, integer z_3, integer z_4) =
    (!(((c == c_2) && (y == y_0) && (z == z_2))) || !(((c_2 < 36) && !((z_2 >= 0)))));

  predicate inv_f(integer c, integer y, integer z, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer y_0, integer z_0, integer z_1, integer z_2, integer z_3, integer z_4) =
    (z >= 127);

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long c, long long y, long long z, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long y_0, long long z_0, long long z_1, long long z_2, long long z_3, long long z_4) {
    return ((c == c_1) && (y == y_0) && (z == z_1) && (c_1 == 0) && (y_0 >= 0) && (y_0 >= 127) && (z_1 == (36 * y_0)));
}

static inline _Bool c_trans_f(long long c, long long y, long long z, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long y_0, long long z_0, long long z_1, long long z_2, long long z_3, long long z_4, long long c_next, long long y_next, long long z_next, long long tmp_next, long long c_0_next, long long c_1_next, long long c_2_next, long long c_3_next, long long c_4_next, long long y_0_next, long long z_0_next, long long z_1_next, long long z_2_next, long long z_3_next, long long z_4_next) {
    return (((c_2 == c) && (z_2 == z) && (c_2 == c_next) && (z_2 == z_next) && (c == c_next) && (y == y_next) && (z == z_next) && (tmp == tmp_next)) || ((c_2 == c) && (z_2 == z) && (c_2 < 36) && (z_3 == (z_2 + 1)) && (c_3 == (c_2 + 1)) && (c_4 == c_3) && (z_4 == z_3) && (c_4 == c_next) && (z_4 == z_next) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)) || ((c_2 == c) && (z_2 == z) && !((c_2 < 36)) && (c_4 == c_2) && (z_4 == z_2) && (c_4 == c_next) && (z_4 == z_next) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long c, long long y, long long z, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long y_0, long long z_0, long long z_1, long long z_2, long long z_3, long long z_4) {
    return (!(((c == c_2) && (y == y_0) && (z == z_2))) || !(((c_2 < 36) && !((z_2 >= 0)))));
}

static inline _Bool c_inv_f(long long c, long long y, long long z, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long y_0, long long z_0, long long z_1, long long z_2, long long z_3, long long z_4) {
    return (z >= 127);
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();
    long long tmp = nondet_long();
    long long c_0 = nondet_long();
    long long c_1 = nondet_long();
    long long c_2 = nondet_long();
    long long c_3 = nondet_long();
    long long c_4 = nondet_long();
    long long y_0 = nondet_long();
    long long z_0 = nondet_long();
    long long z_1 = nondet_long();
    long long z_2 = nondet_long();
    long long z_3 = nondet_long();
    long long z_4 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4);
      @ loop assigns c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();
        long long tmp_next = nondet_long();
        long long c_0_next = nondet_long();
        long long c_1_next = nondet_long();
        long long c_2_next = nondet_long();
        long long c_3_next = nondet_long();
        long long c_4_next = nondet_long();
        long long y_0_next = nondet_long();
        long long z_0_next = nondet_long();
        long long z_1_next = nondet_long();
        long long z_2_next = nondet_long();
        long long z_3_next = nondet_long();
        long long z_4_next = nondet_long();

        if (!c_trans_f(c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4, c_next, y_next, z_next, tmp_next, c_0_next, c_1_next, c_2_next, c_3_next, c_4_next, y_0_next, z_0_next, z_1_next, z_2_next, z_3_next, z_4_next)) break;

        // State updates
        c = c_next;
        y = y_next;
        z = z_next;
        tmp = tmp_next;
        c_0 = c_0_next;
        c_1 = c_1_next;
        c_2 = c_2_next;
        c_3 = c_3_next;
        c_4 = c_4_next;
        y_0 = y_0_next;
        z_0 = z_0_next;
        z_1 = z_1_next;
        z_2 = z_2_next;
        z_3 = z_3_next;
        z_4 = z_4_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4));
    /*@ assert post_f(c, y, z, tmp, c_0, c_1, c_2, c_3, c_4, y_0, z_0, z_1, z_2, z_3, z_4); */

    return 0;
}
