/*
 * Generated C verification file from: 79_conf1.sl
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
  predicate pre_f(integer i, integer conf_0, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer i_4, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer x_0, integer y_0) =
    ((i == i_1) && (conf_0 == conf_0_0) && (x == x_0) && (y == y_0) && (conf_0_0 == 2) && (i_1 == 0) && (x_0 >= 0) && (y_0 >= 0) && (x_0 >= y_0));

  predicate trans_f(integer i, integer conf_0, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer i_4, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer x_0, integer y_0, integer i_next, integer conf_0_next, integer x_next, integer y_next, integer tmp_next, integer i_0_next, integer i_1_next, integer i_2_next, integer i_3_next, integer i_4_next, integer conf_0_0_next, integer conf_0_1_next, integer conf_0_2_next, integer conf_0_3_next, integer x_0_next, integer y_0_next) =
    (((i_2 == i) && (conf_0_1 == conf_0) && (i_2 == i_next) && (conf_0_1 == conf_0_next) && (i == i_next) && (conf_0 == conf_0_next) && (x == x_next) && (y == y_next) && (tmp == tmp_next)) || ((i_2 == i) && (conf_0_1 == conf_0) && (i_2 < y_0) && (i_3 == (i_2 + 1)) && (conf_0_2 == (161 - conf_0_1)) && (i_4 == i_3) && (conf_0_3 == conf_0_2) && (i_4 == i_next) && (conf_0_3 == conf_0_next) && (x == x_0) && (x_next == x_0) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)) || ((i_2 == i) && (conf_0_1 == conf_0) && !((i_2 < y_0)) && (i_4 == i_2) && (conf_0_3 == conf_0_1) && (i_4 == i_next) && (conf_0_3 == conf_0_next) && (x == x_0) && (x_next == x_0) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)));

  predicate post_f(integer i, integer conf_0, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer i_4, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer x_0, integer y_0) =
    (!(((i == i_2) && (conf_0 == conf_0_1) && (x == x_0) && (y == y_0))) || !(((i_2 >= x_0) && (0 > i_2) && !((i_2 >= y_0)))));

  predicate inv_f(integer i, integer conf_0, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer i_4, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer x_0, integer y_0) =
    ((x >= 0) && (y >= 0) && (x >= y) && (i <= y) && (i <= x));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long i, long long conf_0, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long i_4, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long x_0, long long y_0) {
    return ((i == i_1) && (conf_0 == conf_0_0) && (x == x_0) && (y == y_0) && (conf_0_0 == 2) && (i_1 == 0) && (x_0 >= 0) && (y_0 >= 0) && (x_0 >= y_0));
}

static inline _Bool c_trans_f(long long i, long long conf_0, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long i_4, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long x_0, long long y_0, long long i_next, long long conf_0_next, long long x_next, long long y_next, long long tmp_next, long long i_0_next, long long i_1_next, long long i_2_next, long long i_3_next, long long i_4_next, long long conf_0_0_next, long long conf_0_1_next, long long conf_0_2_next, long long conf_0_3_next, long long x_0_next, long long y_0_next) {
    return (((i_2 == i) && (conf_0_1 == conf_0) && (i_2 == i_next) && (conf_0_1 == conf_0_next) && (i == i_next) && (conf_0 == conf_0_next) && (x == x_next) && (y == y_next) && (tmp == tmp_next)) || ((i_2 == i) && (conf_0_1 == conf_0) && (i_2 < y_0) && (i_3 == (i_2 + 1)) && (conf_0_2 == (161 - conf_0_1)) && (i_4 == i_3) && (conf_0_3 == conf_0_2) && (i_4 == i_next) && (conf_0_3 == conf_0_next) && (x == x_0) && (x_next == x_0) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)) || ((i_2 == i) && (conf_0_1 == conf_0) && !((i_2 < y_0)) && (i_4 == i_2) && (conf_0_3 == conf_0_1) && (i_4 == i_next) && (conf_0_3 == conf_0_next) && (x == x_0) && (x_next == x_0) && (y == y_0) && (y_next == y_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long i, long long conf_0, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long i_4, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long x_0, long long y_0) {
    return (!(((i == i_2) && (conf_0 == conf_0_1) && (x == x_0) && (y == y_0))) || !(((i_2 >= x_0) && (0 > i_2) && !((i_2 >= y_0)))));
}

static inline _Bool c_inv_f(long long i, long long conf_0, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long i_4, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long x_0, long long y_0) {
    return ((x >= 0) && (y >= 0) && (x >= y) && (i <= y) && (i <= x));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long conf_0 = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long tmp = nondet_long();
    long long i_0 = nondet_long();
    long long i_1 = nondet_long();
    long long i_2 = nondet_long();
    long long i_3 = nondet_long();
    long long i_4 = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_0_1 = nondet_long();
    long long conf_0_2 = nondet_long();
    long long conf_0_3 = nondet_long();
    long long x_0 = nondet_long();
    long long y_0 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0);
      @ loop assigns i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long conf_0_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long tmp_next = nondet_long();
        long long i_0_next = nondet_long();
        long long i_1_next = nondet_long();
        long long i_2_next = nondet_long();
        long long i_3_next = nondet_long();
        long long i_4_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_0_1_next = nondet_long();
        long long conf_0_2_next = nondet_long();
        long long conf_0_3_next = nondet_long();
        long long x_0_next = nondet_long();
        long long y_0_next = nondet_long();

        if (!c_trans_f(i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0, i_next, conf_0_next, x_next, y_next, tmp_next, i_0_next, i_1_next, i_2_next, i_3_next, i_4_next, conf_0_0_next, conf_0_1_next, conf_0_2_next, conf_0_3_next, x_0_next, y_0_next)) break;

        // State updates
        i = i_next;
        conf_0 = conf_0_next;
        x = x_next;
        y = y_next;
        tmp = tmp_next;
        i_0 = i_0_next;
        i_1 = i_1_next;
        i_2 = i_2_next;
        i_3 = i_3_next;
        i_4 = i_4_next;
        conf_0_0 = conf_0_0_next;
        conf_0_1 = conf_0_1_next;
        conf_0_2 = conf_0_2_next;
        conf_0_3 = conf_0_3_next;
        x_0 = x_0_next;
        y_0 = y_0_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0));
    /*@ assert post_f(i, conf_0, x, y, tmp, i_0, i_1, i_2, i_3, i_4, conf_0_0, conf_0_1, conf_0_2, conf_0_3, x_0, y_0); */

    return 0;
}
