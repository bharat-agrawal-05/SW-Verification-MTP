/*
 * Generated C verification file from: gj2007b_true-unreach-call_true-termination.sl
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
  predicate pre_fun(integer x, integer m, integer n) =
    ((x == 0) && (m == 0));

  predicate trans_fun(integer x, integer m, integer n, integer x_next, integer m_next, integer n_next) =
    ((x < n) && ((m_next == x) || (m_next == m)) && (n_next == n) && (x_next == (x + 1)));

  predicate post_fun(integer x, integer m, integer n) =
    (((m >= 0) || (n <= 0)) && ((m < n) || (n <= 0)));

  predicate inv_fun(integer x, integer m, integer n) =
    (((m <= x) || (n <= x)) && ((m >= 0) || (n <= 0)) && ((m < n) || (n <= 0)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long m, long long n) {
    return ((x == 0) && (m == 0));
}

static inline _Bool c_trans_fun(long long x, long long m, long long n, long long x_next, long long m_next, long long n_next) {
    return ((x < n) && ((m_next == x) || (m_next == m)) && (n_next == n) && (x_next == (x + 1)));
}

static inline _Bool c_post_fun(long long x, long long m, long long n) {
    return (((m >= 0) || (n <= 0)) && ((m < n) || (n <= 0)));
}

static inline _Bool c_inv_fun(long long x, long long m, long long n) {
    return (((m <= x) || (n <= x)) && ((m >= 0) || (n <= 0)) && ((m < n) || (n <= 0)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long m = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, m, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, m, n);
      @ loop assigns x, m, n;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long m_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_trans_fun(x, m, n, x_next, m_next, n_next)) break;

        // State updates
        x = x_next;
        m = m_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, m, n));
    /*@ assert post_fun(x, m, n); */

    return 0;
}
