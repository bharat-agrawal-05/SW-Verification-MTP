/*
 * Generated C verification file from: 88_conf1.sl
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
  predicate pre_f(integer conf_0, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_0_5, integer conf_0_6, integer conf_0_7, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4) =
    ((conf_0 == conf_0_0) && (lock == lock_1) && (x == x_0) && (y == y_1) && (conf_0_0 == 9) && (y_1 == (x_0 + 1)) && (lock_1 == 0));

  predicate trans_f(integer conf_0, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_0_5, integer conf_0_6, integer conf_0_7, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4, integer conf_0_next, integer lock_next, integer x_next, integer y_next, integer tmp_next, integer conf_0_0_next, integer conf_0_1_next, integer conf_0_2_next, integer conf_0_3_next, integer conf_0_4_next, integer conf_0_5_next, integer conf_0_6_next, integer conf_0_7_next, integer lock_0_next, integer lock_1_next, integer lock_2_next, integer lock_3_next, integer lock_4_next, integer lock_5_next, integer x_0_next, integer x_1_next, integer x_2_next, integer x_3_next, integer x_4_next, integer y_0_next, integer y_1_next, integer y_2_next, integer y_3_next, integer y_4_next) =
    (((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && (conf_0_1 == conf_0_next) && (lock_2 == lock_next) && (x_1 == x_next) && (y_2 == y_next) && (conf_0 == conf_0_next) && (lock == lock_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && !((x_1 == y_2)) && (lock_3 == 1) && (conf_0_2 == conf_0_1) && (x_2 == y_2) && (conf_0_3 == (conf_0_2 + conf_0_2)) && (conf_0_4 == conf_0_3) && (lock_4 == lock_3) && (x_3 == x_2) && (y_3 == y_2) && (conf_0_4 == conf_0_next) && (lock_4 == lock_next) && (x_3 == x_next) && (y_3 == y_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && !((x_1 == y_2)) && (lock_5 == 0) && (conf_0_5 == (conf_0_1 - conf_0_1)) && (x_4 == y_2) && (conf_0_6 == (310 + 561)) && (y_4 == (y_2 + 1)) && (conf_0_7 == 184) && (conf_0_4 == conf_0_7) && (lock_4 == lock_5) && (x_3 == x_4) && (y_3 == y_4) && (conf_0_4 == conf_0_next) && (lock_4 == lock_next) && (x_3 == x_next) && (y_3 == y_next) && (tmp == tmp_next)));

  predicate post_f(integer conf_0, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_0_5, integer conf_0_6, integer conf_0_7, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4) =
    (!(((conf_0 == conf_0_1) && (lock == lock_2) && (x == x_1) && (y == y_2))) || !((!(!((x_1 == y_2))) && !((lock_2 == 1)))));

  predicate inv_f(integer conf_0, integer lock, integer x, integer y, integer tmp, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer conf_0_5, integer conf_0_6, integer conf_0_7, integer lock_0, integer lock_1, integer lock_2, integer lock_3, integer lock_4, integer lock_5, integer x_0, integer x_1, integer x_2, integer x_3, integer x_4, integer y_0, integer y_1, integer y_2, integer y_3, integer y_4) =
    (!(((conf_0 == conf_0_1) && (lock == lock_2) && (x == x_1) && (y == y_2))) || !((!(!((x_1 == y_2))) && !((lock_2 == 1)))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long conf_0, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_0_5, long long conf_0_6, long long conf_0_7, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4) {
    return ((conf_0 == conf_0_0) && (lock == lock_1) && (x == x_0) && (y == y_1) && (conf_0_0 == 9) && (y_1 == (x_0 + 1)) && (lock_1 == 0));
}

static inline _Bool c_trans_f(long long conf_0, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_0_5, long long conf_0_6, long long conf_0_7, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4, long long conf_0_next, long long lock_next, long long x_next, long long y_next, long long tmp_next, long long conf_0_0_next, long long conf_0_1_next, long long conf_0_2_next, long long conf_0_3_next, long long conf_0_4_next, long long conf_0_5_next, long long conf_0_6_next, long long conf_0_7_next, long long lock_0_next, long long lock_1_next, long long lock_2_next, long long lock_3_next, long long lock_4_next, long long lock_5_next, long long x_0_next, long long x_1_next, long long x_2_next, long long x_3_next, long long x_4_next, long long y_0_next, long long y_1_next, long long y_2_next, long long y_3_next, long long y_4_next) {
    return (((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && (conf_0_1 == conf_0_next) && (lock_2 == lock_next) && (x_1 == x_next) && (y_2 == y_next) && (conf_0 == conf_0_next) && (lock == lock_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && !((x_1 == y_2)) && (lock_3 == 1) && (conf_0_2 == conf_0_1) && (x_2 == y_2) && (conf_0_3 == (conf_0_2 + conf_0_2)) && (conf_0_4 == conf_0_3) && (lock_4 == lock_3) && (x_3 == x_2) && (y_3 == y_2) && (conf_0_4 == conf_0_next) && (lock_4 == lock_next) && (x_3 == x_next) && (y_3 == y_next) && (tmp == tmp_next)) || ((conf_0_1 == conf_0) && (lock_2 == lock) && (x_1 == x) && (y_2 == y) && !((x_1 == y_2)) && (lock_5 == 0) && (conf_0_5 == (conf_0_1 - conf_0_1)) && (x_4 == y_2) && (conf_0_6 == (310 + 561)) && (y_4 == (y_2 + 1)) && (conf_0_7 == 184) && (conf_0_4 == conf_0_7) && (lock_4 == lock_5) && (x_3 == x_4) && (y_3 == y_4) && (conf_0_4 == conf_0_next) && (lock_4 == lock_next) && (x_3 == x_next) && (y_3 == y_next) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long conf_0, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_0_5, long long conf_0_6, long long conf_0_7, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4) {
    return (!(((conf_0 == conf_0_1) && (lock == lock_2) && (x == x_1) && (y == y_2))) || !((!(!((x_1 == y_2))) && !((lock_2 == 1)))));
}

static inline _Bool c_inv_f(long long conf_0, long long lock, long long x, long long y, long long tmp, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long conf_0_5, long long conf_0_6, long long conf_0_7, long long lock_0, long long lock_1, long long lock_2, long long lock_3, long long lock_4, long long lock_5, long long x_0, long long x_1, long long x_2, long long x_3, long long x_4, long long y_0, long long y_1, long long y_2, long long y_3, long long y_4) {
    return (!(((conf_0 == conf_0_1) && (lock == lock_2) && (x == x_1) && (y == y_2))) || !((!(!((x_1 == y_2))) && !((lock_2 == 1)))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long conf_0 = nondet_long();
    long long lock = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long tmp = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_0_1 = nondet_long();
    long long conf_0_2 = nondet_long();
    long long conf_0_3 = nondet_long();
    long long conf_0_4 = nondet_long();
    long long conf_0_5 = nondet_long();
    long long conf_0_6 = nondet_long();
    long long conf_0_7 = nondet_long();
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
    long long y_0 = nondet_long();
    long long y_1 = nondet_long();
    long long y_2 = nondet_long();
    long long y_3 = nondet_long();
    long long y_4 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4);
      @ loop assigns conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4;
      @*/
    while (1) {
        long long conf_0_next = nondet_long();
        long long lock_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long tmp_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_0_1_next = nondet_long();
        long long conf_0_2_next = nondet_long();
        long long conf_0_3_next = nondet_long();
        long long conf_0_4_next = nondet_long();
        long long conf_0_5_next = nondet_long();
        long long conf_0_6_next = nondet_long();
        long long conf_0_7_next = nondet_long();
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
        long long y_0_next = nondet_long();
        long long y_1_next = nondet_long();
        long long y_2_next = nondet_long();
        long long y_3_next = nondet_long();
        long long y_4_next = nondet_long();

        if (!c_trans_f(conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4, conf_0_next, lock_next, x_next, y_next, tmp_next, conf_0_0_next, conf_0_1_next, conf_0_2_next, conf_0_3_next, conf_0_4_next, conf_0_5_next, conf_0_6_next, conf_0_7_next, lock_0_next, lock_1_next, lock_2_next, lock_3_next, lock_4_next, lock_5_next, x_0_next, x_1_next, x_2_next, x_3_next, x_4_next, y_0_next, y_1_next, y_2_next, y_3_next, y_4_next)) break;

        // State updates
        conf_0 = conf_0_next;
        lock = lock_next;
        x = x_next;
        y = y_next;
        tmp = tmp_next;
        conf_0_0 = conf_0_0_next;
        conf_0_1 = conf_0_1_next;
        conf_0_2 = conf_0_2_next;
        conf_0_3 = conf_0_3_next;
        conf_0_4 = conf_0_4_next;
        conf_0_5 = conf_0_5_next;
        conf_0_6 = conf_0_6_next;
        conf_0_7 = conf_0_7_next;
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
        y_0 = y_0_next;
        y_1 = y_1_next;
        y_2 = y_2_next;
        y_3 = y_3_next;
        y_4 = y_4_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4));
    /*@ assert post_f(conf_0, lock, x, y, tmp, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, conf_0_5, conf_0_6, conf_0_7, lock_0, lock_1, lock_2, lock_3, lock_4, lock_5, x_0, x_1, x_2, x_3, x_4, y_0, y_1, y_2, y_3, y_4); */

    return 0;
}
