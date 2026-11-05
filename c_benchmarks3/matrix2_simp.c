/*
 * Generated C verification file from: matrix2_simp.sl
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
  predicate pre_fun(integer m, integer a, integer j, integer k, integer r, integer c) =
    (((a <= m) || (j == 0)) && ((j < r) && (k == 0)));

  predicate trans_fun(integer m, integer a, integer j, integer k, integer r, integer c, integer m_next, integer a_next, integer j_next, integer k_next, integer r_next, integer c_next) =
    ((((j_next == j) && ((r_next == r) && (c_next == c))) && ((k < c) && ((m < a_next) && ((m_next == a_next) && (k_next == (k + 1)))))) || ((j_next == j) && ((r_next == r) && ((c_next == c) && ((k < c) && ((m > a_next) && (k_next == (k + 1))))))));

  predicate post_fun(integer m, integer a, integer j, integer k, integer r, integer c) =
    ((k < c) || ((a <= m) || (j == -1)));

  predicate inv_fun(integer m, integer a, integer j, integer k, integer r, integer c) =
    \false;

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long m, long long a, long long j, long long k, long long r, long long c) {
    return (((a <= m) || (j == 0)) && ((j < r) && (k == 0)));
}

static inline _Bool c_trans_fun(long long m, long long a, long long j, long long k, long long r, long long c, long long m_next, long long a_next, long long j_next, long long k_next, long long r_next, long long c_next) {
    return ((((j_next == j) && ((r_next == r) && (c_next == c))) && ((k < c) && ((m < a_next) && ((m_next == a_next) && (k_next == (k + 1)))))) || ((j_next == j) && ((r_next == r) && ((c_next == c) && ((k < c) && ((m > a_next) && (k_next == (k + 1))))))));
}

static inline _Bool c_post_fun(long long m, long long a, long long j, long long k, long long r, long long c) {
    return ((k < c) || ((a <= m) || (j == -1)));
}

static inline _Bool c_inv_fun(long long m, long long a, long long j, long long k, long long r, long long c) {
    return false;
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long m = nondet_long();
    long long a = nondet_long();
    long long j = nondet_long();
    long long k = nondet_long();
    long long r = nondet_long();
    long long c = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(m, a, j, k, r, c)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(m, a, j, k, r, c);
      @ loop assigns m, a, j, k, r, c;
      @*/
    while (1) {
        long long m_next = nondet_long();
        long long a_next = nondet_long();
        long long j_next = nondet_long();
        long long k_next = nondet_long();
        long long r_next = nondet_long();
        long long c_next = nondet_long();

        if (!c_trans_fun(m, a, j, k, r, c, m_next, a_next, j_next, k_next, r_next, c_next)) break;

        // State updates
        m = m_next;
        a = a_next;
        j = j_next;
        k = k_next;
        r = r_next;
        c = c_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(m, a, j, k, r, c));
    /*@ assert post_fun(m, a, j, k, r, c); */

    return 0;
}
