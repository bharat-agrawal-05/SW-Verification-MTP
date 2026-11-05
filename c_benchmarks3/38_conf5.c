/*
 * Generated C verification file from: 38_conf5.sl
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
  predicate pre_f(integer c, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer n_0) =
    ((c == c_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (conf_0_0 == 7) && (conf_1_0 == 1) && (conf_2_0 == 4) && (conf_3_0 == 5) && (conf_4_0 == 8) && (c_1 == 0) && (n_0 > 0));

  predicate trans_f(integer c, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer n_0, integer c_next, integer conf_0_next, integer conf_1_next, integer conf_2_next, integer conf_3_next, integer conf_4_next, integer n_next, integer tmp_next, integer c_0_next, integer c_1_next, integer c_2_next, integer c_3_next, integer c_4_next, integer c_5_next, integer conf_0_0_next, integer conf_1_0_next, integer conf_2_0_next, integer conf_2_1_next, integer conf_2_2_next, integer conf_2_3_next, integer conf_3_0_next, integer conf_4_0_next, integer conf_4_1_next, integer conf_4_2_next, integer conf_4_3_next, integer n_0_next) =
    (((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && (c_2 == c_next) && (conf_2_1 == conf_2_next) && (conf_4_1 == conf_4_next) && (c == c_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (n == n_next) && (tmp == tmp_next)) || ((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && (c_2 == n_0) && (c_3 == 1) && (conf_2_2 == conf_3_0) && (c_4 == c_3) && (conf_2_3 == conf_2_2) && (conf_4_2 == conf_4_1) && (c_4 == c_next) && (conf_2_3 == conf_2_next) && (conf_4_2 == conf_4_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && !((c_2 == n_0)) && (c_5 == (c_2 + 1)) && (conf_4_3 == (947 - 94)) && (c_4 == c_5) && (conf_2_3 == conf_2_1) && (conf_4_2 == conf_4_3) && (c_4 == c_next) && (conf_2_3 == conf_2_next) && (conf_4_2 == conf_4_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));

  predicate post_f(integer c, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer n_0) =
    (!(((c == c_2) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_1) && (conf_3 == conf_3_0) && (conf_4 == conf_4_1) && (n == n_0))) || !(((c_2 == n_0) && !((c_2 >= 0)))));

  predicate inv_f(integer c, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer n, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5, integer conf_0_0, integer conf_1_0, integer conf_2_0, integer conf_2_1, integer conf_2_2, integer conf_2_3, integer conf_3_0, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer n_0) =
    ((c >= 0) && (n >= 0) && (conf_0 >= 7) && (conf_1 >= 1) && (conf_2 >= 4) && (conf_3 >= 5) && (conf_4 >= 8));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long c, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long n_0) {
    return ((c == c_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (n == n_0) && (conf_0_0 == 7) && (conf_1_0 == 1) && (conf_2_0 == 4) && (conf_3_0 == 5) && (conf_4_0 == 8) && (c_1 == 0) && (n_0 > 0));
}

static inline _Bool c_trans_f(long long c, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long n_0, long long c_next, long long conf_0_next, long long conf_1_next, long long conf_2_next, long long conf_3_next, long long conf_4_next, long long n_next, long long tmp_next, long long c_0_next, long long c_1_next, long long c_2_next, long long c_3_next, long long c_4_next, long long c_5_next, long long conf_0_0_next, long long conf_1_0_next, long long conf_2_0_next, long long conf_2_1_next, long long conf_2_2_next, long long conf_2_3_next, long long conf_3_0_next, long long conf_4_0_next, long long conf_4_1_next, long long conf_4_2_next, long long conf_4_3_next, long long n_0_next) {
    return (((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && (c_2 == c_next) && (conf_2_1 == conf_2_next) && (conf_4_1 == conf_4_next) && (c == c_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (n == n_next) && (tmp == tmp_next)) || ((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && (c_2 == n_0) && (c_3 == 1) && (conf_2_2 == conf_3_0) && (c_4 == c_3) && (conf_2_3 == conf_2_2) && (conf_4_2 == conf_4_1) && (c_4 == c_next) && (conf_2_3 == conf_2_next) && (conf_4_2 == conf_4_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((c_2 == c) && (conf_2_1 == conf_2) && (conf_4_1 == conf_4) && !((c_2 == n_0)) && (c_5 == (c_2 + 1)) && (conf_4_3 == (947 - 94)) && (c_4 == c_5) && (conf_2_3 == conf_2_1) && (conf_4_2 == conf_4_3) && (c_4 == c_next) && (conf_2_3 == conf_2_next) && (conf_4_2 == conf_4_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long c, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long n_0) {
    return (!(((c == c_2) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_1) && (conf_3 == conf_3_0) && (conf_4 == conf_4_1) && (n == n_0))) || !(((c_2 == n_0) && !((c_2 >= 0)))));
}

static inline _Bool c_inv_f(long long c, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long n, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5, long long conf_0_0, long long conf_1_0, long long conf_2_0, long long conf_2_1, long long conf_2_2, long long conf_2_3, long long conf_3_0, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long n_0) {
    return ((c >= 0) && (n >= 0) && (conf_0 >= 7) && (conf_1 >= 1) && (conf_2 >= 4) && (conf_3 >= 5) && (conf_4 >= 8));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long conf_0 = nondet_long();
    long long conf_1 = nondet_long();
    long long conf_2 = nondet_long();
    long long conf_3 = nondet_long();
    long long conf_4 = nondet_long();
    long long n = nondet_long();
    long long tmp = nondet_long();
    long long c_0 = nondet_long();
    long long c_1 = nondet_long();
    long long c_2 = nondet_long();
    long long c_3 = nondet_long();
    long long c_4 = nondet_long();
    long long c_5 = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_1_0 = nondet_long();
    long long conf_2_0 = nondet_long();
    long long conf_2_1 = nondet_long();
    long long conf_2_2 = nondet_long();
    long long conf_2_3 = nondet_long();
    long long conf_3_0 = nondet_long();
    long long conf_4_0 = nondet_long();
    long long conf_4_1 = nondet_long();
    long long conf_4_2 = nondet_long();
    long long conf_4_3 = nondet_long();
    long long n_0 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0);
      @ loop assigns c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long conf_0_next = nondet_long();
        long long conf_1_next = nondet_long();
        long long conf_2_next = nondet_long();
        long long conf_3_next = nondet_long();
        long long conf_4_next = nondet_long();
        long long n_next = nondet_long();
        long long tmp_next = nondet_long();
        long long c_0_next = nondet_long();
        long long c_1_next = nondet_long();
        long long c_2_next = nondet_long();
        long long c_3_next = nondet_long();
        long long c_4_next = nondet_long();
        long long c_5_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_1_0_next = nondet_long();
        long long conf_2_0_next = nondet_long();
        long long conf_2_1_next = nondet_long();
        long long conf_2_2_next = nondet_long();
        long long conf_2_3_next = nondet_long();
        long long conf_3_0_next = nondet_long();
        long long conf_4_0_next = nondet_long();
        long long conf_4_1_next = nondet_long();
        long long conf_4_2_next = nondet_long();
        long long conf_4_3_next = nondet_long();
        long long n_0_next = nondet_long();

        if (!c_trans_f(c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0, c_next, conf_0_next, conf_1_next, conf_2_next, conf_3_next, conf_4_next, n_next, tmp_next, c_0_next, c_1_next, c_2_next, c_3_next, c_4_next, c_5_next, conf_0_0_next, conf_1_0_next, conf_2_0_next, conf_2_1_next, conf_2_2_next, conf_2_3_next, conf_3_0_next, conf_4_0_next, conf_4_1_next, conf_4_2_next, conf_4_3_next, n_0_next)) break;

        // State updates
        c = c_next;
        conf_0 = conf_0_next;
        conf_1 = conf_1_next;
        conf_2 = conf_2_next;
        conf_3 = conf_3_next;
        conf_4 = conf_4_next;
        n = n_next;
        tmp = tmp_next;
        c_0 = c_0_next;
        c_1 = c_1_next;
        c_2 = c_2_next;
        c_3 = c_3_next;
        c_4 = c_4_next;
        c_5 = c_5_next;
        conf_0_0 = conf_0_0_next;
        conf_1_0 = conf_1_0_next;
        conf_2_0 = conf_2_0_next;
        conf_2_1 = conf_2_1_next;
        conf_2_2 = conf_2_2_next;
        conf_2_3 = conf_2_3_next;
        conf_3_0 = conf_3_0_next;
        conf_4_0 = conf_4_0_next;
        conf_4_1 = conf_4_1_next;
        conf_4_2 = conf_4_2_next;
        conf_4_3 = conf_4_3_next;
        n_0 = n_0_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0));
    /*@ assert post_f(c, conf_0, conf_1, conf_2, conf_3, conf_4, n, tmp, c_0, c_1, c_2, c_3, c_4, c_5, conf_0_0, conf_1_0, conf_2_0, conf_2_1, conf_2_2, conf_2_3, conf_3_0, conf_4_0, conf_4_1, conf_4_2, conf_4_3, n_0); */

    return 0;
}
