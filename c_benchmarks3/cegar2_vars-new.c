/*
 * Generated C verification file from: cegar2_vars-new.sl
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
  predicate pre_fun(integer x, integer n, integer m, integer z1, integer z2, integer z3) =
    ((x == 1) && (m == 1));

  predicate trans_fun(integer x, integer n, integer m, integer z1, integer z2, integer z3, integer x_next, integer n_next, integer m_next, integer z1_next, integer z2_next, integer z3_next) =
    (((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == m)) || ((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == x)));

  predicate post_fun(integer x, integer n, integer m, integer z1, integer z2, integer z3) =
    !((((x >= n) && (n > 1)) && ((n <= m) || (m < 1))));

  predicate inv_fun(integer x, integer n, integer m, integer z1, integer z2, integer z3) =
    (!((!((n <= 1)) && (n <= m))) && (x >= m) && (m >= 1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long n, long long m, long long z1, long long z2, long long z3) {
    return ((x == 1) && (m == 1));
}

static inline _Bool c_trans_fun(long long x, long long n, long long m, long long z1, long long z2, long long z3, long long x_next, long long n_next, long long m_next, long long z1_next, long long z2_next, long long z3_next) {
    return (((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == m)) || ((((x < n) && (x_next == (x + 1))) && (n_next == n)) && (m_next == x)));
}

static inline _Bool c_post_fun(long long x, long long n, long long m, long long z1, long long z2, long long z3) {
    return !((((x >= n) && (n > 1)) && ((n <= m) || (m < 1))));
}

static inline _Bool c_inv_fun(long long x, long long n, long long m, long long z1, long long z2, long long z3) {
    return (!((!((n <= 1)) && (n <= m))) && (x >= m) && (m >= 1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long n = nondet_long();
    long long m = nondet_long();
    long long z1 = nondet_long();
    long long z2 = nondet_long();
    long long z3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, n, m, z1, z2, z3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, n, m, z1, z2, z3);
      @ loop assigns x, n, m, z1, z2, z3;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long n_next = nondet_long();
        long long m_next = nondet_long();
        long long z1_next = nondet_long();
        long long z2_next = nondet_long();
        long long z3_next = nondet_long();

        if (!c_trans_fun(x, n, m, z1, z2, z3, x_next, n_next, m_next, z1_next, z2_next, z3_next)) break;

        // State updates
        x = x_next;
        n = n_next;
        m = m_next;
        z1 = z1_next;
        z2 = z2_next;
        z3 = z3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, n, m, z1, z2, z3));
    /*@ assert post_fun(x, n, m, z1, z2, z3); */

    return 0;
}
