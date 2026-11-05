/*
 * Generated C verification file from: 107_conf1.sl
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
  predicate pre_f(integer a, integer j, integer conf_0, integer k, integer m, integer a_0, integer j_0, integer j_1, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer k_0, integer k_1, integer k_2, integer k_3, integer m_0, integer m_1, integer m_2, integer m_3) =
    ((j == j_1) && (conf_0 == conf_0_0) && (k == k_1) && (conf_0_0 == 4) && (j_1 == 0) && (k_1 == 0));

  predicate trans_f(integer a, integer j, integer conf_0, integer k, integer m, integer a_0, integer j_0, integer j_1, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer k_0, integer k_1, integer k_2, integer k_3, integer m_0, integer m_1, integer m_2, integer m_3, integer a_next, integer j_next, integer conf_0_next, integer k_next, integer m_next, integer a_0_next, integer j_0_next, integer j_1_next, integer conf_0_0_next, integer conf_0_1_next, integer conf_0_2_next, integer conf_0_3_next, integer conf_0_4_next, integer k_0_next, integer k_1_next, integer k_2_next, integer k_3_next, integer m_0_next, integer m_1_next, integer m_2_next, integer m_3_next) =
    (((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (conf_0_1 == conf_0_next) && (k_2 == k_next) && (m_1 == m_next) && (a == a_next) && (j == j_next) && (conf_0 == conf_0_next) && (m == m_next)) || ((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (k_2 < 1) && (m_1 < a_0) && (m_2 == a_0) && (conf_0_2 == conf_0_1) && (conf_0_3 == conf_0_2) && (m_3 == m_2) && (k_3 == (k_2 + 1)) && (conf_0_4 == 453) && (conf_0_4 == conf_0_next) && (k_3 == k_next) && (m_3 == m_next) && (a == a_0) && (a_next == a_0) && (j == j_1) && (j_next == j_1)) || ((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (k_2 < 1) && !((m_1 < a_0)) && (conf_0_3 == conf_0_1) && (m_3 == m_1) && (k_3 == (k_2 + 1)) && (conf_0_4 == 453) && (conf_0_4 == conf_0_next) && (k_3 == k_next) && (m_3 == m_next) && (a == a_0) && (a_next == a_0) && (j == j_1) && (j_next == j_1)));

  predicate post_f(integer a, integer j, integer conf_0, integer k, integer m, integer a_0, integer j_0, integer j_1, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer k_0, integer k_1, integer k_2, integer k_3, integer m_0, integer m_1, integer m_2, integer m_3) =
    (!(((a == a_0) && (j == j_1) && (conf_0 == conf_0_1) && (k == k_2) && (m == m_1))) || !((!((k_2 < 1)) && !((a_0 <= m_1)))));

  predicate inv_f(integer a, integer j, integer conf_0, integer k, integer m, integer a_0, integer j_0, integer j_1, integer conf_0_0, integer conf_0_1, integer conf_0_2, integer conf_0_3, integer conf_0_4, integer k_0, integer k_1, integer k_2, integer k_3, integer m_0, integer m_1, integer m_2, integer m_3) =
    ((k < 1) || ((k == 1) && (a <= m)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long a, long long j, long long conf_0, long long k, long long m, long long a_0, long long j_0, long long j_1, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long k_0, long long k_1, long long k_2, long long k_3, long long m_0, long long m_1, long long m_2, long long m_3) {
    return ((j == j_1) && (conf_0 == conf_0_0) && (k == k_1) && (conf_0_0 == 4) && (j_1 == 0) && (k_1 == 0));
}

static inline _Bool c_trans_f(long long a, long long j, long long conf_0, long long k, long long m, long long a_0, long long j_0, long long j_1, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long k_0, long long k_1, long long k_2, long long k_3, long long m_0, long long m_1, long long m_2, long long m_3, long long a_next, long long j_next, long long conf_0_next, long long k_next, long long m_next, long long a_0_next, long long j_0_next, long long j_1_next, long long conf_0_0_next, long long conf_0_1_next, long long conf_0_2_next, long long conf_0_3_next, long long conf_0_4_next, long long k_0_next, long long k_1_next, long long k_2_next, long long k_3_next, long long m_0_next, long long m_1_next, long long m_2_next, long long m_3_next) {
    return (((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (conf_0_1 == conf_0_next) && (k_2 == k_next) && (m_1 == m_next) && (a == a_next) && (j == j_next) && (conf_0 == conf_0_next) && (m == m_next)) || ((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (k_2 < 1) && (m_1 < a_0) && (m_2 == a_0) && (conf_0_2 == conf_0_1) && (conf_0_3 == conf_0_2) && (m_3 == m_2) && (k_3 == (k_2 + 1)) && (conf_0_4 == 453) && (conf_0_4 == conf_0_next) && (k_3 == k_next) && (m_3 == m_next) && (a == a_0) && (a_next == a_0) && (j == j_1) && (j_next == j_1)) || ((conf_0_1 == conf_0) && (k_2 == k) && (m_1 == m) && (k_2 < 1) && !((m_1 < a_0)) && (conf_0_3 == conf_0_1) && (m_3 == m_1) && (k_3 == (k_2 + 1)) && (conf_0_4 == 453) && (conf_0_4 == conf_0_next) && (k_3 == k_next) && (m_3 == m_next) && (a == a_0) && (a_next == a_0) && (j == j_1) && (j_next == j_1)));
}

static inline _Bool c_post_f(long long a, long long j, long long conf_0, long long k, long long m, long long a_0, long long j_0, long long j_1, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long k_0, long long k_1, long long k_2, long long k_3, long long m_0, long long m_1, long long m_2, long long m_3) {
    return (!(((a == a_0) && (j == j_1) && (conf_0 == conf_0_1) && (k == k_2) && (m == m_1))) || !((!((k_2 < 1)) && !((a_0 <= m_1)))));
}

static inline _Bool c_inv_f(long long a, long long j, long long conf_0, long long k, long long m, long long a_0, long long j_0, long long j_1, long long conf_0_0, long long conf_0_1, long long conf_0_2, long long conf_0_3, long long conf_0_4, long long k_0, long long k_1, long long k_2, long long k_3, long long m_0, long long m_1, long long m_2, long long m_3) {
    return ((k < 1) || ((k == 1) && (a <= m)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a = nondet_long();
    long long j = nondet_long();
    long long conf_0 = nondet_long();
    long long k = nondet_long();
    long long m = nondet_long();
    long long a_0 = nondet_long();
    long long j_0 = nondet_long();
    long long j_1 = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_0_1 = nondet_long();
    long long conf_0_2 = nondet_long();
    long long conf_0_3 = nondet_long();
    long long conf_0_4 = nondet_long();
    long long k_0 = nondet_long();
    long long k_1 = nondet_long();
    long long k_2 = nondet_long();
    long long k_3 = nondet_long();
    long long m_0 = nondet_long();
    long long m_1 = nondet_long();
    long long m_2 = nondet_long();
    long long m_3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3);
      @ loop assigns a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3;
      @*/
    while (1) {
        long long a_next = nondet_long();
        long long j_next = nondet_long();
        long long conf_0_next = nondet_long();
        long long k_next = nondet_long();
        long long m_next = nondet_long();
        long long a_0_next = nondet_long();
        long long j_0_next = nondet_long();
        long long j_1_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_0_1_next = nondet_long();
        long long conf_0_2_next = nondet_long();
        long long conf_0_3_next = nondet_long();
        long long conf_0_4_next = nondet_long();
        long long k_0_next = nondet_long();
        long long k_1_next = nondet_long();
        long long k_2_next = nondet_long();
        long long k_3_next = nondet_long();
        long long m_0_next = nondet_long();
        long long m_1_next = nondet_long();
        long long m_2_next = nondet_long();
        long long m_3_next = nondet_long();

        if (!c_trans_f(a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3, a_next, j_next, conf_0_next, k_next, m_next, a_0_next, j_0_next, j_1_next, conf_0_0_next, conf_0_1_next, conf_0_2_next, conf_0_3_next, conf_0_4_next, k_0_next, k_1_next, k_2_next, k_3_next, m_0_next, m_1_next, m_2_next, m_3_next)) break;

        // State updates
        a = a_next;
        j = j_next;
        conf_0 = conf_0_next;
        k = k_next;
        m = m_next;
        a_0 = a_0_next;
        j_0 = j_0_next;
        j_1 = j_1_next;
        conf_0_0 = conf_0_0_next;
        conf_0_1 = conf_0_1_next;
        conf_0_2 = conf_0_2_next;
        conf_0_3 = conf_0_3_next;
        conf_0_4 = conf_0_4_next;
        k_0 = k_0_next;
        k_1 = k_1_next;
        k_2 = k_2_next;
        k_3 = k_3_next;
        m_0 = m_0_next;
        m_1 = m_1_next;
        m_2 = m_2_next;
        m_3 = m_3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3));
    /*@ assert post_f(a, j, conf_0, k, m, a_0, j_0, j_1, conf_0_0, conf_0_1, conf_0_2, conf_0_3, conf_0_4, k_0, k_1, k_2, k_3, m_0, m_1, m_2, m_3); */

    return 0;
}
