/*
 * Generated C verification file from: 93_conf5.sl
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
  predicate pre_f(integer i, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_1_4, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_2_4, integer conf_2_5, integer conf_3_0, integer conf_4_0, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4, integer y_5) =
    ((i == i_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (x == x_1) && (y == y_1) && (conf_0_0 == 8) && (conf_1_0 == 8) && (conf_2_0 == 5) && (conf_3_0 == 3) && (conf_4_0 == 3) && (n_0 >= 0) && (i_1 == 0) && (x_1 == 0) && (y_1 == 0));

  predicate trans_f(integer i, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_1_4, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_2_4, integer conf_2_5, integer conf_3_0, integer conf_4_0, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4, integer y_5, integer i_next, integer conf_0_next, integer conf_1_next, integer conf_2_next, integer conf_3_next, integer conf_4_next, integer n_next, integer x_next, integer y_next, integer tmp_next, integer i_0_next, integer i_1_next, integer i_2_next, integer i_3_next, integer conf_0_0_next, integer conf_1_0_next, integer conf_1_1_next, integer conf_1_2_next, integer conf_1_3_next, integer conf_1_4_next, integer conf_2_0_next, integer conf_2_1_next, integer conf_2_2_next, integer conf_2_3_next, integer conf_2_4_next, integer conf_2_5_next, integer conf_3_0_next, integer conf_4_0_next, integer n_0_next, integer x_0_next, integer x_1_next, integer x_2_next, integer x_3_next, integer x_4_next, integer x_5_next, integer y_0_next, integer y_1_next, integer y_2_next, integer y_3_next, integer y_4_next, integer y_5_next) =
    (((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 == i_next) && (conf_1_1 == conf_1_next) && (conf_2_1 == conf_2_next) && (x_2 == x_next) && (y_2 == y_next) && (n == n_0) && (n_next == n_0) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (x == x_next) && (y == y_next) && (tmp == tmp_next)) || ((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 < n_0) && (i_3 == (i_2 + 1)) && (conf_2_2 == (conf_4_0 - conf_2_1)) && (x_3 == (x_2 + 1)) && (conf_1_2 == (conf_3_0 + conf_1_1)) && (y_3 == (y_2 + 2)) && (conf_2_3 == 918) && (conf_1_3 == conf_1_2) && (conf_2_4 == conf_2_3) && (x_4 == x_3) && (y_4 == y_3) && (i_3 == i_next) && (conf_1_3 == conf_1_next) && (conf_2_4 == conf_2_next) && (x_4 == x_next) && (y_4 == y_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 < n_0) && (i_3 == (i_2 + 1)) && (conf_2_2 == (conf_4_0 - conf_2_1)) && (x_5 == (x_2 + 2)) && (conf_1_4 == (607 + 185)) && (y_5 == (y_2 + 1)) && (conf_2_5 == 773) && (conf_1_3 == conf_1_4) && (conf_2_4 == conf_2_5) && (x_4 == x_5) && (y_4 == y_5) && (i_3 == i_next) && (conf_1_3 == conf_1_next) && (conf_2_4 == conf_2_next) && (x_4 == x_next) && (y_4 == y_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));

  predicate post_f(integer i, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_1_4, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_2_4, integer conf_2_5, integer conf_3_0, integer conf_4_0, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4, integer y_5) =
    (!(((i == i_2) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_1) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (x == x_2) && (y == y_2))) || !((!((i_2 < n_0)) && !(((3 * n_0) == (x_2 + y_2))))));

  predicate inv_f(integer i, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer x, integer y, integer tmp, integer i_0, integer i_1, integer i_2, integer i_3, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_1_4, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_2_4, integer conf_2_5, integer conf_3_0, integer conf_4_0, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4, integer y_5) =
    ((0 <= i) && (i <= n) && ((x + y) == (3 * i)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long i, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_1_4, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_2_4, long long conf_2_5, long long conf_3_0, long long conf_4_0, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4, long long y_5) {
    return ((i == i_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (x == x_1) && (y == y_1) && (conf_0_0 == 8) && (conf_1_0 == 8) && (conf_2_0 == 5) && (conf_3_0 == 3) && (conf_4_0 == 3) && (n_0 >= 0) && (i_1 == 0) && (x_1 == 0) && (y_1 == 0));
}

static inline _Bool c_trans_f(long long i, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_1_4, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_2_4, long long conf_2_5, long long conf_3_0, long long conf_4_0, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4, long long y_5, long long i_next, long long conf_0_next, long long conf_1_next, long long conf_2_next, long long conf_3_next, long long conf_4_next, long long n_next, long long x_next, long long y_next, long long tmp_next, long long i_0_next, long long i_1_next, long long i_2_next, long long i_3_next, long long conf_0_0_next, long long conf_1_0_next, long long conf_1_1_next, long long conf_1_2_next, long long conf_1_3_next, long long conf_1_4_next, long long conf_2_0_next, long long conf_2_1_next, long long conf_2_2_next, long long conf_2_3_next, long long conf_2_4_next, long long conf_2_5_next, long long conf_3_0_next, long long conf_4_0_next, long long n_0_next, long long x_0_next, long long x_1_next, long long x_2_next, long long x_3_next, long long x_4_next, long long x_5_next, long long y_0_next, long long y_1_next, long long y_2_next, long long y_3_next, long long y_4_next, long long y_5_next) {
    return (((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 == i_next) && (conf_1_1 == conf_1_next) && (conf_2_1 == conf_2_next) && (x_2 == x_next) && (y_2 == y_next) && (n == n_0) && (n_next == n_0) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (x == x_next) && (y == y_next) && (tmp == tmp_next)) || ((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 < n_0) && (i_3 == (i_2 + 1)) && (conf_2_2 == (conf_4_0 - conf_2_1)) && (x_3 == (x_2 + 1)) && (conf_1_2 == (conf_3_0 + conf_1_1)) && (y_3 == (y_2 + 2)) && (conf_2_3 == 918) && (conf_1_3 == conf_1_2) && (conf_2_4 == conf_2_3) && (x_4 == x_3) && (y_4 == y_3) && (i_3 == i_next) && (conf_1_3 == conf_1_next) && (conf_2_4 == conf_2_next) && (x_4 == x_next) && (y_4 == y_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((i_2 == i) && (conf_1_1 == conf_1) && (conf_2_1 == conf_2) && (x_2 == x) && (y_2 == y) && (i_2 < n_0) && (i_3 == (i_2 + 1)) && (conf_2_2 == (conf_4_0 - conf_2_1)) && (x_5 == (x_2 + 2)) && (conf_1_4 == (607 + 185)) && (y_5 == (y_2 + 1)) && (conf_2_5 == 773) && (conf_1_3 == conf_1_4) && (conf_2_4 == conf_2_5) && (x_4 == x_5) && (y_4 == y_5) && (i_3 == i_next) && (conf_1_3 == conf_1_next) && (conf_2_4 == conf_2_next) && (x_4 == x_next) && (y_4 == y_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long i, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_1_4, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_2_4, long long conf_2_5, long long conf_3_0, long long conf_4_0, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4, long long y_5) {
    return (!(((i == i_2) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_1) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (x == x_2) && (y == y_2))) || !((!((i_2 < n_0)) && !(((3 * n_0) == (x_2 + y_2))))));
}

static inline _Bool c_inv_f(long long i, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long x, long long y, long long tmp, long long i_0, long long i_1, long long i_2, long long i_3, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_1_4, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_2_4, long long conf_2_5, long long conf_3_0, long long conf_4_0, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4, long long y_5) {
    return ((0 <= i) && (i <= n) && ((x + y) == (3 * i)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long conf_0 = nondet_long();
    long long conf_1 = nondet_long();
    long long conf_2 = nondet_long();
    long long conf_3 = nondet_long();
    long long conf_4 = nondet_long();
    long long n = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long tmp = nondet_long();
    long long i_0 = nondet_long();
    long long i_1 = nondet_long();
    long long i_2 = nondet_long();
    long long i_3 = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_1_0 = nondet_long();
    long long conf_1_1 = nondet_long();
    long long conf_1_2 = nondet_long();
    long long conf_1_3 = nondet_long();
    long long conf_1_4 = nondet_long();
    long long conf_2_0 = nondet_long();
    long long conf_2_1 = nondet_long();
    long long conf_2_2 = nondet_long();
    long long conf_2_3 = nondet_long();
    long long conf_2_4 = nondet_long();
    long long conf_2_5 = nondet_long();
    long long conf_3_0 = nondet_long();
    long long conf_4_0 = nondet_long();
    long long n_0 = nondet_long();
    long long x_0 = nondet_long();
    long long x_1 = nondet_long();
    long long x_2 = nondet_long();
    long long x_3 = nondet_long();
    long long x_4 = nondet_long();
    long long x_5 = nondet_long();
    long long y_0 = nondet_long();
    long long y_1 = nondet_long();
    long long y_2 = nondet_long();
    long long y_3 = nondet_long();
    long long y_4 = nondet_long();
    long long y_5 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5);
      @ loop assigns i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long conf_0_next = nondet_long();
        long long conf_1_next = nondet_long();
        long long conf_2_next = nondet_long();
        long long conf_3_next = nondet_long();
        long long conf_4_next = nondet_long();
        long long n_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long tmp_next = nondet_long();
        long long i_0_next = nondet_long();
        long long i_1_next = nondet_long();
        long long i_2_next = nondet_long();
        long long i_3_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_1_0_next = nondet_long();
        long long conf_1_1_next = nondet_long();
        long long conf_1_2_next = nondet_long();
        long long conf_1_3_next = nondet_long();
        long long conf_1_4_next = nondet_long();
        long long conf_2_0_next = nondet_long();
        long long conf_2_1_next = nondet_long();
        long long conf_2_2_next = nondet_long();
        long long conf_2_3_next = nondet_long();
        long long conf_2_4_next = nondet_long();
        long long conf_2_5_next = nondet_long();
        long long conf_3_0_next = nondet_long();
        long long conf_4_0_next = nondet_long();
        long long n_0_next = nondet_long();
        long long x_0_next = nondet_long();
        long long x_1_next = nondet_long();
        long long x_2_next = nondet_long();
        long long x_3_next = nondet_long();
        long long x_4_next = nondet_long();
        long long x_5_next = nondet_long();
        long long y_0_next = nondet_long();
        long long y_1_next = nondet_long();
        long long y_2_next = nondet_long();
        long long y_3_next = nondet_long();
        long long y_4_next = nondet_long();
        long long y_5_next = nondet_long();

        if (!c_trans_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5, i_next, conf_0_next, conf_1_next, conf_2_next, conf_3_next, conf_4_next, n_next, x_next, y_next, tmp_next, i_0_next, i_1_next, i_2_next, i_3_next, conf_0_0_next, conf_1_0_next, conf_1_1_next, conf_1_2_next, conf_1_3_next, conf_1_4_next, conf_2_0_next, conf_2_1_next, conf_2_2_next, conf_2_3_next, conf_2_4_next, conf_2_5_next, conf_3_0_next, conf_4_0_next, n_0_next, x_0_next, x_1_next, x_2_next, x_3_next, x_4_next, x_5_next, y_0_next, y_1_next, y_2_next, y_3_next, y_4_next, y_5_next)) break;

        // State updates
        i = i_next;
        conf_0 = conf_0_next;
        conf_1 = conf_1_next;
        conf_2 = conf_2_next;
        conf_3 = conf_3_next;
        conf_4 = conf_4_next;
        n = n_next;
        x = x_next;
        y = y_next;
        tmp = tmp_next;
        i_0 = i_0_next;
        i_1 = i_1_next;
        i_2 = i_2_next;
        i_3 = i_3_next;
        conf_0_0 = conf_0_0_next;
        conf_1_0 = conf_1_0_next;
        conf_1_1 = conf_1_1_next;
        conf_1_2 = conf_1_2_next;
        conf_1_3 = conf_1_3_next;
        conf_1_4 = conf_1_4_next;
        conf_2_0 = conf_2_0_next;
        conf_2_1 = conf_2_1_next;
        conf_2_2 = conf_2_2_next;
        conf_2_3 = conf_2_3_next;
        conf_2_4 = conf_2_4_next;
        conf_2_5 = conf_2_5_next;
        conf_3_0 = conf_3_0_next;
        conf_4_0 = conf_4_0_next;
        n_0 = n_0_next;
        x_0 = x_0_next;
        x_1 = x_1_next;
        x_2 = x_2_next;
        x_3 = x_3_next;
        x_4 = x_4_next;
        x_5 = x_5_next;
        y_0 = y_0_next;
        y_1 = y_1_next;
        y_2 = y_2_next;
        y_3 = y_3_next;
        y_4 = y_4_next;
        y_5 = y_5_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5));
    /*@ assert post_f(i, conf_0, conf_1, conf_2, conf_3, conf_4, n, x, y, tmp, i_0, i_1, i_2, i_3, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_1_4, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_2_4, conf_2_5, conf_3_0, conf_4_0, n_0, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, y_4, y_5); */

    return 0;
}
