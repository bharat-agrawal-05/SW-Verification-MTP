/*
 * Generated C verification file from: fib_19.sl
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
  predicate pre_fun(integer n, integer m, integer x, integer y) =
    ((n >= 0) && (m >= 0) && (m < n) && (x == 0) && (y == m));

  predicate trans_fun(integer n, integer m, integer x, integer y, integer n_next, integer m_next, integer x_next, integer y_next) =
    (((x < n) && ((x + 1) <= m) && (x_next == (x + 1)) && (y_next == y) && (n_next == n) && (m_next == m)) || ((x < n) && ((x + 1) > m) && (x_next == (x + 1)) && (y_next == (y + 1)) && (n_next == n) && (m_next == m)) || ((x >= n) && (x_next == x) && (y_next == y) && (n_next == n) && (m_next == m)));

  predicate post_fun(integer n, integer m, integer x, integer y) =
    (!((x < n)) ==> (y == n));

  predicate inv_fun(integer n, integer m, integer x, integer y) =
    ((!((n <= x)) || (y == n)) && ((m == y) || (x == y)) && (y >= m) && (m >= 0) && ((n == x) || ((y >= x) && !((n <= y)))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long n, long long m, long long x, long long y) {
    return ((n >= 0) && (m >= 0) && (m < n) && (x == 0) && (y == m));
}

static inline _Bool c_trans_fun(long long n, long long m, long long x, long long y, long long n_next, long long m_next, long long x_next, long long y_next) {
    return (((x < n) && ((x + 1) <= m) && (x_next == (x + 1)) && (y_next == y) && (n_next == n) && (m_next == m)) || ((x < n) && ((x + 1) > m) && (x_next == (x + 1)) && (y_next == (y + 1)) && (n_next == n) && (m_next == m)) || ((x >= n) && (x_next == x) && (y_next == y) && (n_next == n) && (m_next == m)));
}

static inline _Bool c_post_fun(long long n, long long m, long long x, long long y) {
    return (!(!((x < n))) || (y == n));
}

static inline _Bool c_inv_fun(long long n, long long m, long long x, long long y) {
    return ((!((n <= x)) || (y == n)) && ((m == y) || (x == y)) && (y >= m) && (m >= 0) && ((n == x) || ((y >= x) && !((n <= y)))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long n = nondet_long();
    long long m = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(n, m, x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(n, m, x, y);
      @ loop assigns n, m, x, y;
      @*/
    while (1) {
        long long n_next = nondet_long();
        long long m_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_trans_fun(n, m, x, y, n_next, m_next, x_next, y_next)) break;

        // State updates
        n = n_next;
        m = m_next;
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(n, m, x, y));
    /*@ assert post_fun(n, m, x, y); */

    return 0;
}
