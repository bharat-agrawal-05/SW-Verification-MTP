/*
 * Generated C verification file from: cegar2.sl
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
  predicate pre_fun(integer x, integer n, integer m) =
    ((x == 0) && (m == 0));

  predicate trans_fun(integer x, integer n, integer m, integer x_next, integer n_next, integer m_next) =
    (((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == m)) || ((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == x)));

  predicate post_fun(integer x, integer n, integer m) =
    !((((x >= n) && (n > 0)) && ((n <= m) || (m < 0))));

  predicate inv_fun(integer x, integer n, integer m) =
    (!((!((n <= 0)) && (n <= m))) && (x >= m) && (m >= 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long n, long long m) {
    return ((x == 0) && (m == 0));
}

static inline _Bool c_trans_fun(long long x, long long n, long long m, long long x_next, long long n_next, long long m_next) {
    return (((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == m)) || ((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == x)));
}

static inline _Bool c_post_fun(long long x, long long n, long long m) {
    return !((((x >= n) && (n > 0)) && ((n <= m) || (m < 0))));
}

static inline _Bool c_inv_fun(long long x, long long n, long long m) {
    return (!((!((n <= 0)) && (n <= m))) && (x >= m) && (m >= 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long n = nondet_long();
    long long m = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, n, m)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, n, m);
      @ loop assigns x, n, m;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long n_next = nondet_long();
        long long m_next = nondet_long();

        if (!c_trans_fun(x, n, m, x_next, n_next, m_next)) break;

        // State updates
        x = x_next;
        n = n_next;
        m = m_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, n, m));
    /*@ assert post_fun(x, n, m); */

    return 0;
}
