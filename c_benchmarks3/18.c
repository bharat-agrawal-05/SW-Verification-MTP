/*
 * Generated C verification file from: 18.c.sl
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
  predicate pre_f(integer m, integer n, integer x, integer tmp, integer m_0, integer m_1, integer m_2, integer m_3, integer n_0, integer x_0, integer x_1, integer x_2) =
    ((m == m_0) && (x == x_0) && (x_0 == 1) && (m_0 == 1));

  predicate trans_f(integer m, integer n, integer x, integer tmp, integer m_0, integer m_1, integer m_2, integer m_3, integer n_0, integer x_0, integer x_1, integer x_2, integer m_next, integer n_next, integer x_next, integer tmp_next, integer m_0_next, integer m_1_next, integer m_2_next, integer m_3_next, integer n_0_next, integer x_0_next, integer x_1_next, integer x_2_next) =
    (((m_1 == m) && (x_1 == x) && (m_1 == m_next) && (x_1 == x_next) && (n == n_0) && (n_next == n_0) && (m == m_next) && (tmp == tmp_next)) || ((m_1 == m) && (x_1 == x) && (x_1 < n_0) && (m_2 == x_1) && (m_3 == m_2) && (x_2 == (x_1 + 1)) && (m_3 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((m_1 == m) && (x_1 == x) && (x_1 < n_0) && (m_3 == m_1) && (x_2 == (x_1 + 1)) && (m_3 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));

  predicate post_f(integer m, integer n, integer x, integer tmp, integer m_0, integer m_1, integer m_2, integer m_3, integer n_0, integer x_0, integer x_1, integer x_2) =
    (!(((m == m_1) && (n == n_0) && (x == x_1))) || !((!((x_1 < n_0)) && (n_0 > 1) && !((m_1 >= 1)))));

  predicate inv_f(integer m, integer n, integer x, integer tmp, integer m_0, integer m_1, integer m_2, integer m_3, integer n_0, integer x_0, integer x_1, integer x_2) =
    ((n == 1) || ((1 <= x) && (1 <= m)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long m, long long n, long long x, long long tmp, long long m_0, long long m_1, long long m_2, long long m_3, long long n_0, long long x_0, long long x_1, long long x_2) {
    return ((m == m_0) && (x == x_0) && (x_0 == 1) && (m_0 == 1));
}

static inline _Bool c_trans_f(long long m, long long n, long long x, long long tmp, long long m_0, long long m_1, long long m_2, long long m_3, long long n_0, long long x_0, long long x_1, long long x_2, long long m_next, long long n_next, long long x_next, long long tmp_next, long long m_0_next, long long m_1_next, long long m_2_next, long long m_3_next, long long n_0_next, long long x_0_next, long long x_1_next, long long x_2_next) {
    return (((m_1 == m) && (x_1 == x) && (m_1 == m_next) && (x_1 == x_next) && (n == n_0) && (n_next == n_0) && (m == m_next) && (tmp == tmp_next)) || ((m_1 == m) && (x_1 == x) && (x_1 < n_0) && (m_2 == x_1) && (m_3 == m_2) && (x_2 == (x_1 + 1)) && (m_3 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)) || ((m_1 == m) && (x_1 == x) && (x_1 < n_0) && (m_3 == m_1) && (x_2 == (x_1 + 1)) && (m_3 == m_next) && (x_2 == x_next) && (n == n_0) && (n_next == n_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long m, long long n, long long x, long long tmp, long long m_0, long long m_1, long long m_2, long long m_3, long long n_0, long long x_0, long long x_1, long long x_2) {
    return (!(((m == m_1) && (n == n_0) && (x == x_1))) || !((!((x_1 < n_0)) && (n_0 > 1) && !((m_1 >= 1)))));
}

static inline _Bool c_inv_f(long long m, long long n, long long x, long long tmp, long long m_0, long long m_1, long long m_2, long long m_3, long long n_0, long long x_0, long long x_1, long long x_2) {
    return ((n == 1) || ((1 <= x) && (1 <= m)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long m = nondet_long();
    long long n = nondet_long();
    long long x = nondet_long();
    long long tmp = nondet_long();
    long long m_0 = nondet_long();
    long long m_1 = nondet_long();
    long long m_2 = nondet_long();
    long long m_3 = nondet_long();
    long long n_0 = nondet_long();
    long long x_0 = nondet_long();
    long long x_1 = nondet_long();
    long long x_2 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2);
      @ loop assigns m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2;
      @*/
    while (1) {
        long long m_next = nondet_long();
        long long n_next = nondet_long();
        long long x_next = nondet_long();
        long long tmp_next = nondet_long();
        long long m_0_next = nondet_long();
        long long m_1_next = nondet_long();
        long long m_2_next = nondet_long();
        long long m_3_next = nondet_long();
        long long n_0_next = nondet_long();
        long long x_0_next = nondet_long();
        long long x_1_next = nondet_long();
        long long x_2_next = nondet_long();

        if (!c_trans_f(m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2, m_next, n_next, x_next, tmp_next, m_0_next, m_1_next, m_2_next, m_3_next, n_0_next, x_0_next, x_1_next, x_2_next)) break;

        // State updates
        m = m_next;
        n = n_next;
        x = x_next;
        tmp = tmp_next;
        m_0 = m_0_next;
        m_1 = m_1_next;
        m_2 = m_2_next;
        m_3 = m_3_next;
        n_0 = n_0_next;
        x_0 = x_0_next;
        x_1 = x_1_next;
        x_2 = x_2_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2));
    /*@ assert post_f(m, n, x, tmp, m_0, m_1, m_2, m_3, n_0, x_0, x_1, x_2); */

    return 0;
}
