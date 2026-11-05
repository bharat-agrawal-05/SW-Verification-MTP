/*
 * Generated C verification file from: hola.20.sl
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
  predicate pre_fun(integer i, integer j, integer k, integer m, integer n, integer x, integer y) =
    ((k == (x + y)) && ((m == 0) && (j == 0)));

  predicate trans_fun(integer i, integer j, integer k, integer m, integer n, integer x, integer y, integer i_next, integer j_next, integer k_next, integer m_next, integer n_next, integer x_next, integer y_next) =
    ((j < n) && ((i_next == i) && ((k_next == k) && ((n_next == n) && ((j_next == (j + 1)) && (((m_next == m) || (m_next == j)) && (((j == i) && ((x_next == (x + 1)) && (y_next == (y - 1)))) || (!((j == i)) && ((x_next == (x - 1)) && (y_next == (y + 1)))))))))));

  predicate post_fun(integer i, integer j, integer k, integer m, integer n, integer x, integer y) =
    ((k == (x + y)) && (!((n > 0)) || ((0 <= m) && (m < n))));

  predicate inv_fun(integer i, integer j, integer k, integer m, integer n, integer x, integer y) =
    (((n <= 0) || ((0 <= m) && !((n <= m)))) && (k == (x + y)) && (j >= 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long i, long long j, long long k, long long m, long long n, long long x, long long y) {
    return ((k == (x + y)) && ((m == 0) && (j == 0)));
}

static inline _Bool c_trans_fun(long long i, long long j, long long k, long long m, long long n, long long x, long long y, long long i_next, long long j_next, long long k_next, long long m_next, long long n_next, long long x_next, long long y_next) {
    return ((j < n) && ((i_next == i) && ((k_next == k) && ((n_next == n) && ((j_next == (j + 1)) && (((m_next == m) || (m_next == j)) && (((j == i) && ((x_next == (x + 1)) && (y_next == (y - 1)))) || (!((j == i)) && ((x_next == (x - 1)) && (y_next == (y + 1)))))))))));
}

static inline _Bool c_post_fun(long long i, long long j, long long k, long long m, long long n, long long x, long long y) {
    return ((k == (x + y)) && (!((n > 0)) || ((0 <= m) && (m < n))));
}

static inline _Bool c_inv_fun(long long i, long long j, long long k, long long m, long long n, long long x, long long y) {
    return (((n <= 0) || ((0 <= m) && !((n <= m)))) && (k == (x + y)) && (j >= 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long j = nondet_long();
    long long k = nondet_long();
    long long m = nondet_long();
    long long n = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(i, j, k, m, n, x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, k, m, n, x, y);
      @ loop assigns i, j, k, m, n, x, y;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long k_next = nondet_long();
        long long m_next = nondet_long();
        long long n_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_trans_fun(i, j, k, m, n, x, y, i_next, j_next, k_next, m_next, n_next, x_next, y_next)) break;

        // State updates
        i = i_next;
        j = j_next;
        k = k_next;
        m = m_next;
        n = n_next;
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(i, j, k, m, n, x, y));
    /*@ assert post_fun(i, j, k, m, n, x, y); */

    return 0;
}
