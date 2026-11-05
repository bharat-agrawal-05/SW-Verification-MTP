/*
 * Generated C verification file from: 4_conf1.sl
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
  predicate pre_f(integer conf_0, integer x, integer y, integer z, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer x_0, integer x_1, integer x_2, integer x_3, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    ((conf_0 == conf_0_0) && (x == x_1) && (conf_0_0 == 8) && (x_1 == 0));

  predicate trans_f(integer conf_0, integer x, integer y, integer z, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer x_0, integer x_1, integer x_2, integer x_3, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0, integer conf_0_next, integer x_next, integer y_next, integer z_next, integer conf_0_0_next, integer conf_0_1_next, integer conf_0_2_next, integer conf_0_3_next, integer conf_0_4_next, integer x_0_next, integer x_1_next, integer x_2_next, integer x_3_next, integer y_0_next, integer y_1_next, integer y_2_next, integer y_3_next, integer z_0_next) =
    (((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (conf_0_1 == conf_0_next) && (x_2 == x_next) && (y_1 == y_next) && (conf_0 == conf_0_next) && (y == y_next) && (z == z_next)) || ((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (x_2 < 500) && (x_3 == (x_2 + 1)) && (conf_0_2 == conf_0_1) && (z_0 <= y_1) && (y_2 == z_0) && (conf_0_3 == 159) && (conf_0_4 == conf_0_3) && (y_3 == y_2) && (conf_0_4 == conf_0_next) && (x_3 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)) || ((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (x_2 < 500) && (x_3 == (x_2 + 1)) && (conf_0_2 == conf_0_1) && !((z_0 <= y_1)) && (conf_0_4 == conf_0_2) && (y_3 == y_1) && (conf_0_4 == conf_0_next) && (x_3 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)));

  predicate post_f(integer conf_0, integer x, integer y, integer z, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer x_0, integer x_1, integer x_2, integer x_3, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    (!(((conf_0 == conf_0_1) && (x == x_2) && (y == y_1) && (z == z_0))) || !((!((x_2 < 500)) && !((z_0 >= y_1)))));

  predicate inv_f(integer conf_0, integer x, integer y, integer z, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer x_0, integer x_1, integer x_2, integer x_3, integer y_0, integer y_1, integer y_2, integer y_3, integer z_0) =
    ((x == 0) || !((z < y)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long conf_0, long long x, long long y, long long z, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long x_0, long long x_1, long long x_2, long long x_3, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return ((conf_0 == conf_0_0) && (x == x_1) && (conf_0_0 == 8) && (x_1 == 0));
}

static inline _Bool c_trans_f(long long conf_0, long long x, long long y, long long z, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long x_0, long long x_1, long long x_2, long long x_3, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0, long long conf_0_next, long long x_next, long long y_next, long long z_next, long long conf_0_0_next, long long conf_0_1_next, long long conf_0_2_next, long long conf_0_3_next, long long conf_0_4_next, long long x_0_next, long long x_1_next, long long x_2_next, long long x_3_next, long long y_0_next, long long y_1_next, long long y_2_next, long long y_3_next, long long z_0_next) {
    return (((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (conf_0_1 == conf_0_next) && (x_2 == x_next) && (y_1 == y_next) && (conf_0 == conf_0_next) && (y == y_next) && (z == z_next)) || ((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (x_2 < 500) && (x_3 == (x_2 + 1)) && (conf_0_2 == conf_0_1) && (z_0 <= y_1) && (y_2 == z_0) && (conf_0_3 == 159) && (conf_0_4 == conf_0_3) && (y_3 == y_2) && (conf_0_4 == conf_0_next) && (x_3 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)) || ((conf_0_1 == conf_0) && (x_2 == x) && (y_1 == y) && (x_2 < 500) && (x_3 == (x_2 + 1)) && (conf_0_2 == conf_0_1) && !((z_0 <= y_1)) && (conf_0_4 == conf_0_2) && (y_3 == y_1) && (conf_0_4 == conf_0_next) && (x_3 == x_next) && (y_3 == y_next) && (z == z_0) && (z_next == z_0)));
}

static inline _Bool c_post_f(long long conf_0, long long x, long long y, long long z, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long x_0, long long x_1, long long x_2, long long x_3, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return (!(((conf_0 == conf_0_1) && (x == x_2) && (y == y_1) && (z == z_0))) || !((!((x_2 < 500)) && !((z_0 >= y_1)))));
}

static inline _Bool c_inv_f(long long conf_0, long long x, long long y, long long z, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long x_0, long long x_1, long long x_2, long long x_3, long long y_0, long long y_1, long long y_2, long long y_3, long long z_0) {
    return ((x == 0) || !((z < y)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long conf_0 = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_0_1 = nondet_long();
    long long conf_0_2 = nondet_long();
    long long conf_0_3 = nondet_long();
    long long conf_0_4 = nondet_long();
    long long x_0 = nondet_long();
    long long x_1 = nondet_long();
    long long x_2 = nondet_long();
    long long x_3 = nondet_long();
    long long y_0 = nondet_long();
    long long y_1 = nondet_long();
    long long y_2 = nondet_long();
    long long y_3 = nondet_long();
    long long z_0 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0);
      @ loop assigns conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0;
      @*/
    while (1) {
        long long conf_0_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_0_1_next = nondet_long();
        long long conf_0_2_next = nondet_long();
        long long conf_0_3_next = nondet_long();
        long long conf_0_4_next = nondet_long();
        long long x_0_next = nondet_long();
        long long x_1_next = nondet_long();
        long long x_2_next = nondet_long();
        long long x_3_next = nondet_long();
        long long y_0_next = nondet_long();
        long long y_1_next = nondet_long();
        long long y_2_next = nondet_long();
        long long y_3_next = nondet_long();
        long long z_0_next = nondet_long();

        if (!c_trans_f(conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0, conf_0_next, x_next, y_next, z_next, conf_0_0_next, conf_0_1_next, conf_0_2_next, conf_0_3_next, conf_0_4_next, x_0_next, x_1_next, x_2_next, x_3_next, y_0_next, y_1_next, y_2_next, y_3_next, z_0_next)) break;

        // State updates
        conf_0 = conf_0_next;
        x = x_next;
        y = y_next;
        z = z_next;
        conf_0_0 = conf_0_0_next;
        conf_0_1 = conf_0_1_next;
        conf_0_2 = conf_0_2_next;
        conf_0_3 = conf_0_3_next;
        conf_0_4 = conf_0_4_next;
        x_0 = x_0_next;
        x_1 = x_1_next;
        x_2 = x_2_next;
        x_3 = x_3_next;
        y_0 = y_0_next;
        y_1 = y_1_next;
        y_2 = y_2_next;
        y_3 = y_3_next;
        z_0 = z_0_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0));
    /*@ assert post_f(conf_0, x, y, z, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, x_0, x_1, x_2, x_3, y_0, y_1, y_2, y_3, z_0); */

    return 0;
}
