/*
 * Generated C verification file from: 17_conf5.sl
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
  predicate pre_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer m, integer n, integer x, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0, integer m_0, integer m_1, integer m_2, integer m_3, integer m_4, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3) =
    ((conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (m == m_1) && (x == x_1) && (conf_0_0 == 6) && (conf_1_0 == 3) && (conf_2_0 == 3) && (conf_3_0 == 6) && (conf_4_0 == 0) && (x_1 == 1) && (m_1 == 1));

  predicate trans_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer m, integer n, integer x, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0, integer m_0, integer m_1, integer m_2, integer m_3, integer m_4, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3, integer conf_0_next, integer conf_1_next, integer conf_2_next, integer conf_3_next, integer conf_4_next, integer m_next, integer n_next, integer x_next, integer tmp_next, integer conf_0_0_next, integer conf_1_0_next, integer conf_1_1_next, integer conf_1_2_next, integer conf_1_3_next, integer conf_2_0_next, integer conf_3_0_next, integer conf_3_1_next, integer conf_3_2_next, integer conf_4_0_next, integer m_0_next, integer m_1_next, integer m_2_next, integer m_3_next, integer m_4_next, integer n_0_next, integer x_0_next, integer x_1_next, integer x_2_next, integer x_3_next) =
    (((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (m_2 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (m == m_next) && (tmp == tmp_next)) || ((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (x_2 < n_0) && (m_3 == x_2) && (conf_1_2 == 419) && (conf_1_3 == conf_1_2) && (m_4 == m_3) && (x_3 == (x_2 + 1)) && (conf_3_2 == (conf_2_0 + conf_2_0)) && (conf_1_3 == conf_1_next) && (conf_3_2 == conf_3_next) && (m_4 == m_next) && (x_3 == x_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (x_2 < n_0) && (conf_1_3 == conf_1_1) && (m_4 == m_2) && (x_3 == (x_2 + 1)) && (conf_3_2 == (conf_2_0 + conf_2_0)) && (conf_1_3 == conf_1_next) && (conf_3_2 == conf_3_next) && (m_4 == m_next) && (x_3 == x_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));

  predicate post_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer m, integer n, integer x, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0, integer m_0, integer m_1, integer m_2, integer m_3, integer m_4, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3) =
    (!(((conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_0) && (m == m_2) && (n == n_0) && (x == x_2))) || !((!((x_2 < n_0)) && (n_0 > 1) && !((m_2 < n_0)))));

  predicate inv_f(integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer m, integer n, integer x, integer tmp, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_4_0, integer m_0, integer m_1, integer m_2, integer m_3, integer m_4, integer n_0, integer x_0, integer x_1, integer x_2, integer x_3) =
    ((m < n) || (n <= 1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long m, long long n, long long x, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0, long long m_0, long long m_1, long long m_2, long long m_3, long long m_4, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3) {
    return ((conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (m == m_1) && (x == x_1) && (conf_0_0 == 6) && (conf_1_0 == 3) && (conf_2_0 == 3) && (conf_3_0 == 6) && (conf_4_0 == 0) && (x_1 == 1) && (m_1 == 1));
}

static inline _Bool c_trans_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long m, long long n, long long x, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0, long long m_0, long long m_1, long long m_2, long long m_3, long long m_4, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3, long long conf_0_next, long long conf_1_next, long long conf_2_next, long long conf_3_next, long long conf_4_next, long long m_next, long long n_next, long long x_next, long long tmp_next, long long conf_0_0_next, long long conf_1_0_next, long long conf_1_1_next, long long conf_1_2_next, long long conf_1_3_next, long long conf_2_0_next, long long conf_3_0_next, long long conf_3_1_next, long long conf_3_2_next, long long conf_4_0_next, long long m_0_next, long long m_1_next, long long m_2_next, long long m_3_next, long long m_4_next, long long n_0_next, long long x_0_next, long long x_1_next, long long x_2_next, long long x_3_next) {
    return (((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (m_2 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (m == m_next) && (tmp == tmp_next)) || ((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (x_2 < n_0) && (m_3 == x_2) && (conf_1_2 == 419) && (conf_1_3 == conf_1_2) && (m_4 == m_3) && (x_3 == (x_2 + 1)) && (conf_3_2 == (conf_2_0 + conf_2_0)) && (conf_1_3 == conf_1_next) && (conf_3_2 == conf_3_next) && (m_4 == m_next) && (x_3 == x_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (m_2 == m) && (x_2 == x) && (x_2 < n_0) && (conf_1_3 == conf_1_1) && (m_4 == m_2) && (x_3 == (x_2 + 1)) && (conf_3_2 == (conf_2_0 + conf_2_0)) && (conf_1_3 == conf_1_next) && (conf_3_2 == conf_3_next) && (m_4 == m_next) && (x_3 == x_next) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long m, long long n, long long x, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0, long long m_0, long long m_1, long long m_2, long long m_3, long long m_4, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3) {
    return (!(((conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_0) && (m == m_2) && (n == n_0) && (x == x_2))) || !((!((x_2 < n_0)) && (n_0 > 1) && !((m_2 < n_0)))));
}

static inline _Bool c_inv_f(long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long m, long long n, long long x, long long tmp, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_4_0, long long m_0, long long m_1, long long m_2, long long m_3, long long m_4, long long n_0, long long x_0, long long x_1, long long x_2, long long x_3) {
    return ((m < n) || (n <= 1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long conf_0 = nondet_long();
    long long conf_1 = nondet_long();
    long long conf_2 = nondet_long();
    long long conf_3 = nondet_long();
    long long conf_4 = nondet_long();
    long long m = nondet_long();
    long long n = nondet_long();
    long long x = nondet_long();
    long long tmp = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_1_0 = nondet_long();
    long long conf_1_1 = nondet_long();
    long long conf_1_2 = nondet_long();
    long long conf_1_3 = nondet_long();
    long long conf_2_0 = nondet_long();
    long long conf_3_0 = nondet_long();
    long long conf_3_1 = nondet_long();
    long long conf_3_2 = nondet_long();
    long long conf_4_0 = nondet_long();
    long long m_0 = nondet_long();
    long long m_1 = nondet_long();
    long long m_2 = nondet_long();
    long long m_3 = nondet_long();
    long long m_4 = nondet_long();
    long long n_0 = nondet_long();
    long long x_0 = nondet_long();
    long long x_1 = nondet_long();
    long long x_2 = nondet_long();
    long long x_3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3);
      @ loop assigns conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3;
      @*/
    while (1) {
        long long conf_0_next = nondet_long();
        long long conf_1_next = nondet_long();
        long long conf_2_next = nondet_long();
        long long conf_3_next = nondet_long();
        long long conf_4_next = nondet_long();
        long long m_next = nondet_long();
        long long n_next = nondet_long();
        long long x_next = nondet_long();
        long long tmp_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_1_0_next = nondet_long();
        long long conf_1_1_next = nondet_long();
        long long conf_1_2_next = nondet_long();
        long long conf_1_3_next = nondet_long();
        long long conf_2_0_next = nondet_long();
        long long conf_3_0_next = nondet_long();
        long long conf_3_1_next = nondet_long();
        long long conf_3_2_next = nondet_long();
        long long conf_4_0_next = nondet_long();
        long long m_0_next = nondet_long();
        long long m_1_next = nondet_long();
        long long m_2_next = nondet_long();
        long long m_3_next = nondet_long();
        long long m_4_next = nondet_long();
        long long n_0_next = nondet_long();
        long long x_0_next = nondet_long();
        long long x_1_next = nondet_long();
        long long x_2_next = nondet_long();
        long long x_3_next = nondet_long();

        if (!c_trans_f(conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3, conf_0_next, conf_1_next, conf_2_next, conf_3_next, conf_4_next, m_next, n_next, x_next, tmp_next, conf_0_0_next, conf_1_0_next, conf_1_1_next, conf_1_2_next, conf_1_3_next, conf_2_0_next, conf_3_0_next, conf_3_1_next, conf_3_2_next, conf_4_0_next, m_0_next, m_1_next, m_2_next, m_3_next, m_4_next, n_0_next, x_0_next, x_1_next, x_2_next, x_3_next)) break;

        // State updates
        conf_0 = conf_0_next;
        conf_1 = conf_1_next;
        conf_2 = conf_2_next;
        conf_3 = conf_3_next;
        conf_4 = conf_4_next;
        m = m_next;
        n = n_next;
        x = x_next;
        tmp = tmp_next;
        conf_0_0 = conf_0_0_next;
        conf_1_0 = conf_1_0_next;
        conf_1_1 = conf_1_1_next;
        conf_1_2 = conf_1_2_next;
        conf_1_3 = conf_1_3_next;
        conf_2_0 = conf_2_0_next;
        conf_3_0 = conf_3_0_next;
        conf_3_1 = conf_3_1_next;
        conf_3_2 = conf_3_2_next;
        conf_4_0 = conf_4_0_next;
        m_0 = m_0_next;
        m_1 = m_1_next;
        m_2 = m_2_next;
        m_3 = m_3_next;
        m_4 = m_4_next;
        n_0 = n_0_next;
        x_0 = x_0_next;
        x_1 = x_1_next;
        x_2 = x_2_next;
        x_3 = x_3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3));
    /*@ assert post_f(conf_0, conf_1, conf_2, conf_3, conf_4, m, n, x, tmp, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_4_0, m_0, m_1, m_2, m_3, m_4, n_0, x_0, x_1, x_2, x_3); */

    return 0;
}
