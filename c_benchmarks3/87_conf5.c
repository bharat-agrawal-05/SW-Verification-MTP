/*
 * Generated C verification file from: 87_conf5.sl
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
  predicate pre_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3) =
    ((conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (lock == lock_1) && (x == x_1) && (y == y_0) && (conf_0_0 == 8) && (conf_1_0 == 3) && (conf_2_0 == 2) && (conf_3_0 == 7) && (conf_4_0 == 5) && (x_1 == y_0) && (lock_1 == 1));

  predicate trans_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3, integer conf_0_next, integer conf_1_next, integer conf_2_next, integer conf_3_next, integer conf_4_next, integer lock_next, integer x_next, integer y_next, integer tmp_next, integer conf_0_0_next, integer conf_0_1_next, integer conf_0_2_next, integer conf_0_3_next, integer conf_0_4_next, integer conf_1_0_next, integer conf_1_1_next, integer conf_1_2_next, integer conf_1_3_next, integer conf_2_0_next, integer conf_3_0_next, integer conf_3_1_next, integer conf_3_2_next, integer conf_3_3_next, integer conf_4_0_next, integer conf_4_1_next, integer conf_4_2_next, integer conf_4_3_next, integer lock_0_next, integer lock_1_next, integer lock_2_next, integer lock_3_next, integer lock_4_next, integer lock_5_next, integer x_0_next, integer x_1_next, integer x_2_next, integer x_3_next, integer x_4_next, integer x_5_next, integer y_0_next, integer y_1_next, integer y_2_next, integer y_3_next) =
    (((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && (conf_0_1 == conf_0_next) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (conf_4_1 == conf_4_next) && (lock_2 == lock_next) && (x_2 == x_next) && (y_1 == y_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (lock == lock_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && !((x_2 == y_1)) && (lock_3 == 1) && (conf_3_2 == (445 + 35)) && (x_3 == y_1) && (conf_1_2 == (conf_4_1 - 303)) && (conf_0_2 == conf_0_1) && (conf_1_3 == conf_1_2) && (conf_3_3 == conf_3_2) && (conf_4_2 == conf_4_1) && (lock_4 == lock_3) && (x_4 == x_3) && (y_2 == y_1) && (conf_0_2 == conf_0_next) && (conf_1_3 == conf_1_next) && (conf_3_3 == conf_3_next) && (conf_4_2 == conf_4_next) && (lock_4 == lock_next) && (x_4 == x_next) && (y_2 == y_next) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && !((x_2 == y_1)) && (lock_5 == 0) && (conf_0_3 == (conf_3_1 - 403)) && (x_5 == y_1) && (conf_0_4 == 73) && (y_3 == (y_1 + 1)) && (conf_4_3 == (587 + conf_3_1)) && (conf_0_2 == conf_0_4) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_2 == conf_4_3) && (lock_4 == lock_5) && (x_4 == x_5) && (y_2 == y_3) && (conf_0_2 == conf_0_next) && (conf_1_3 == conf_1_next) && (conf_3_3 == conf_3_next) && (conf_4_2 == conf_4_next) && (lock_4 == lock_next) && (x_4 == x_next) && (y_2 == y_next) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (tmp == tmp_next)));

  predicate post_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3) =
    (!(((conf_0 == conf_0_1) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (lock == lock_2) && (x == x_2) && (y == y_1))) || !((!(!((x_2 == y_1))) && !((lock_2 == 1)))));

  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer x_5, integer y_0, integer y_1, integer y_2, integer y_3) =
    ((1 == lock) && (x == y));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3) {
    return ((conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (lock == lock_1) && (x == x_1) && (y == y_0) && (conf_0_0 == 8) && (conf_1_0 == 3) && (conf_2_0 == 2) && (conf_3_0 == 7) && (conf_4_0 == 5) && (x_1 == y_0) && (lock_1 == 1));
}

static inline _Bool c_trans_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3, long long conf_0_next, long long conf_1_next, long long conf_2_next, long long conf_3_next, long long conf_4_next, long long lock_next, long long x_next, long long y_next, long long tmp_next, long long conf_0_0_next, long long conf_0_1_next, long long conf_0_2_next, long long conf_0_3_next, long long conf_0_4_next, long long conf_1_0_next, long long conf_1_1_next, long long conf_1_2_next, long long conf_1_3_next, long long conf_2_0_next, long long conf_3_0_next, long long conf_3_1_next, long long conf_3_2_next, long long conf_3_3_next, long long conf_4_0_next, long long conf_4_1_next, long long conf_4_2_next, long long conf_4_3_next, long long lock_0_next, long long lock_1_next, long long lock_2_next, long long lock_3_next, long long lock_4_next, long long lock_5_next, long long x_0_next, long long x_1_next, long long x_2_next, long long x_3_next, long long x_4_next, long long x_5_next, long long y_0_next, long long y_1_next, long long y_2_next, long long y_3_next) {
    return (((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && (conf_0_1 == conf_0_next) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (conf_4_1 == conf_4_next) && (lock_2 == lock_next) && (x_2 == x_next) && (y_1 == y_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (lock == lock_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && !((x_2 == y_1)) && (lock_3 == 1) && (conf_3_2 == (445 + 35)) && (x_3 == y_1) && (conf_1_2 == (conf_4_1 - 303)) && (conf_0_2 == conf_0_1) && (conf_1_3 == conf_1_2) && (conf_3_3 == conf_3_2) && (conf_4_2 == conf_4_1) && (lock_4 == lock_3) && (x_4 == x_3) && (y_2 == y_1) && (conf_0_2 == conf_0_next) && (conf_1_3 == conf_1_next) && (conf_3_3 == conf_3_next) && (conf_4_2 == conf_4_next) && (lock_4 == lock_next) && (x_4 == x_next) && (y_2 == y_next) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (lock_2 == lock) && (x_2 == x) && (y_1 == y) && !((x_2 == y_1)) && (lock_5 == 0) && (conf_0_3 == (conf_3_1 - 403)) && (x_5 == y_1) && (conf_0_4 == 73) && (y_3 == (y_1 + 1)) && (conf_4_3 == (587 + conf_3_1)) && (conf_0_2 == conf_0_4) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_2 == conf_4_3) && (lock_4 == lock_5) && (x_4 == x_5) && (y_2 == y_3) && (conf_0_2 == conf_0_next) && (conf_1_3 == conf_1_next) && (conf_3_3 == conf_3_next) && (conf_4_2 == conf_4_next) && (lock_4 == lock_next) && (x_4 == x_next) && (y_2 == y_next) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3) {
    return (!(((conf_0 == conf_0_1) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (lock == lock_2) && (x == x_2) && (y == y_1))) || !((!(!((x_2 == y_1))) && !((lock_2 == 1)))));
}

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long x_5, long long y_0, long long y_1, long long y_2, long long y_3) {
    return ((1 == lock) && (x == y));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long conf_0 = nondet_long();
    long long conf_1 = nondet_long();
    long long conf_2 = nondet_long();
    long long conf_3 = nondet_long();
    long long conf_4 = nondet_long();
    long long lock = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long tmp = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_0_1 = nondet_long();
    long long conf_0_2 = nondet_long();
    long long conf_0_3 = nondet_long();
    long long conf_0_4 = nondet_long();
    long long conf_1_0 = nondet_long();
    long long conf_1_1 = nondet_long();
    long long conf_1_2 = nondet_long();
    long long conf_1_3 = nondet_long();
    long long conf_2_0 = nondet_long();
    long long conf_3_0 = nondet_long();
    long long conf_3_1 = nondet_long();
    long long conf_3_2 = nondet_long();
    long long conf_3_3 = nondet_long();
    long long conf_4_0 = nondet_long();
    long long conf_4_1 = nondet_long();
    long long conf_4_2 = nondet_long();
    long long conf_4_3 = nondet_long();
    long long lock_0 = nondet_long();
    long long lock_1 = nondet_long();
    long long lock_2 = nondet_long();
    long long lock_3 = nondet_long();
    long long lock_4 = nondet_long();
    long long lock_5 = nondet_long();
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

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3);
      @ loop assigns conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3;
      @*/
    while (1) {
        long long conf_0_next = nondet_long();
        long long conf_1_next = nondet_long();
        long long conf_2_next = nondet_long();
        long long conf_3_next = nondet_long();
        long long conf_4_next = nondet_long();
        long long lock_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long tmp_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_0_1_next = nondet_long();
        long long conf_0_2_next = nondet_long();
        long long conf_0_3_next = nondet_long();
        long long conf_0_4_next = nondet_long();
        long long conf_1_0_next = nondet_long();
        long long conf_1_1_next = nondet_long();
        long long conf_1_2_next = nondet_long();
        long long conf_1_3_next = nondet_long();
        long long conf_2_0_next = nondet_long();
        long long conf_3_0_next = nondet_long();
        long long conf_3_1_next = nondet_long();
        long long conf_3_2_next = nondet_long();
        long long conf_3_3_next = nondet_long();
        long long conf_4_0_next = nondet_long();
        long long conf_4_1_next = nondet_long();
        long long conf_4_2_next = nondet_long();
        long long conf_4_3_next = nondet_long();
        long long lock_0_next = nondet_long();
        long long lock_1_next = nondet_long();
        long long lock_2_next = nondet_long();
        long long lock_3_next = nondet_long();
        long long lock_4_next = nondet_long();
        long long lock_5_next = nondet_long();
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

        if (!c_trans_f(conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3, conf_0_next, conf_1_next, conf_2_next, conf_3_next, conf_4_next, lock_next, x_next, y_next, tmp_next, conf_0_0_next, conf_0_1_next, conf_0_2_next, conf_0_3_next, conf_0_4_next, conf_1_0_next, conf_1_1_next, conf_1_2_next, conf_1_3_next, conf_2_0_next, conf_3_0_next, conf_3_1_next, conf_3_2_next, conf_3_3_next, conf_4_0_next, conf_4_1_next, conf_4_2_next, conf_4_3_next, lock_0_next, lock_1_next, lock_2_next, lock_3_next, lock_4_next, lock_5_next, x_0_next, x_1_next, x_2_next, x_3_next, x_4_next, x_5_next, y_0_next, y_1_next, y_2_next, y_3_next)) break;

        // State updates
        conf_0 = conf_0_next;
        conf_1 = conf_1_next;
        conf_2 = conf_2_next;
        conf_3 = conf_3_next;
        conf_4 = conf_4_next;
        lock = lock_next;
        x = x_next;
        y = y_next;
        tmp = tmp_next;
        conf_0_0 = conf_0_0_next;
        conf_0_1 = conf_0_1_next;
        conf_0_2 = conf_0_2_next;
        conf_0_3 = conf_0_3_next;
        conf_0_4 = conf_0_4_next;
        conf_1_0 = conf_1_0_next;
        conf_1_1 = conf_1_1_next;
        conf_1_2 = conf_1_2_next;
        conf_1_3 = conf_1_3_next;
        conf_2_0 = conf_2_0_next;
        conf_3_0 = conf_3_0_next;
        conf_3_1 = conf_3_1_next;
        conf_3_2 = conf_3_2_next;
        conf_3_3 = conf_3_3_next;
        conf_4_0 = conf_4_0_next;
        conf_4_1 = conf_4_1_next;
        conf_4_2 = conf_4_2_next;
        conf_4_3 = conf_4_3_next;
        lock_0 = lock_0_next;
        lock_1 = lock_1_next;
        lock_2 = lock_2_next;
        lock_3 = lock_3_next;
        lock_4 = lock_4_next;
        lock_5 = lock_5_next;
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
    }

    // 4. Post-condition assertion
    assert(c_post_f(conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3));
    /*@ assert post_f(conf_0, conf_1, conf_2, conf_3, conf_4, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, x_5, y_0, y_1, y_2, y_3); */

    return 0;
}
