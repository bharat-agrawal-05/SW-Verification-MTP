/*
 * Generated C verification file from: fib_20.sl
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
  predicate pre_fun(integer x, integer y, integer k, integer j, integer i, integer n, integer m) =
    (((x + y) == k) && (m == 0) && (j == 0));

  predicate trans_fun(integer x, integer y, integer k, integer j, integer i, integer n, integer m, integer x_next, integer y_next, integer k_next, integer j_next, integer i_next, integer n_next, integer m_next) =
    (((j < n) && (j == i) && (x_next == (x + 1)) && (y_next == (y - 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == m)) || ((j < n) && (j == i) && (x_next == (x + 1)) && (y_next == (y - 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == j)) || ((j < n) && !((j == i)) && (x_next == (x - 1)) && (y_next == (y + 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == m)) || ((j < n) && !((j == i)) && (x_next == (x - 1)) && (y_next == (y + 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == j)) || ((j >= n) && (x_next == x) && (y_next == y) && (k_next == k) && (j_next == j) && (i_next == i) && (n_next == n) && (m_next == m)));

  predicate post_fun(integer x, integer y, integer k, integer j, integer i, integer n, integer m) =
    ((j >= n) ==> (((x + y) == k) && ((n <= 0) || (0 <= m)) && ((n <= 0) || (m <= n))));

  predicate inv_fun(integer x, integer y, integer k, integer j, integer i, integer n, integer m) =
    (((x + y) == k) && ((n <= 0) || (0 <= m)) && ((n <= 0) || (m <= n)) && (j >= 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long k, long long j, long long i, long long n, long long m) {
    return (((x + y) == k) && (m == 0) && (j == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long k, long long j, long long i, long long n, long long m, long long x_next, long long y_next, long long k_next, long long j_next, long long i_next, long long n_next, long long m_next) {
    return (((j < n) && (j == i) && (x_next == (x + 1)) && (y_next == (y - 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == m)) || ((j < n) && (j == i) && (x_next == (x + 1)) && (y_next == (y - 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == j)) || ((j < n) && !((j == i)) && (x_next == (x - 1)) && (y_next == (y + 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == m)) || ((j < n) && !((j == i)) && (x_next == (x - 1)) && (y_next == (y + 1)) && (k_next == k) && (j_next == (j + 1)) && (i_next == i) && (n_next == n) && (m_next == j)) || ((j >= n) && (x_next == x) && (y_next == y) && (k_next == k) && (j_next == j) && (i_next == i) && (n_next == n) && (m_next == m)));
}

static inline _Bool c_post_fun(long long x, long long y, long long k, long long j, long long i, long long n, long long m) {
    return (!((j >= n)) || (((x + y) == k) && ((n <= 0) || (0 <= m)) && ((n <= 0) || (m <= n))));
}

static inline _Bool c_inv_fun(long long x, long long y, long long k, long long j, long long i, long long n, long long m) {
    return (((x + y) == k) && ((n <= 0) || (0 <= m)) && ((n <= 0) || (m <= n)) && (j >= 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long k = nondet_long();
    long long j = nondet_long();
    long long i = nondet_long();
    long long n = nondet_long();
    long long m = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, k, j, i, n, m)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, k, j, i, n, m);
      @ loop assigns x, y, k, j, i, n, m;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long k_next = nondet_long();
        long long j_next = nondet_long();
        long long i_next = nondet_long();
        long long n_next = nondet_long();
        long long m_next = nondet_long();

        if (!c_trans_fun(x, y, k, j, i, n, m, x_next, y_next, k_next, j_next, i_next, n_next, m_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        k = k_next;
        j = j_next;
        i = i_next;
        n = n_next;
        m = m_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, k, j, i, n, m));
    /*@ assert post_fun(x, y, k, j, i, n, m); */

    return 0;
}
