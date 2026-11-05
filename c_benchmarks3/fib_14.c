/*
 * Generated C verification file from: fib_14.sl
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
  predicate pre_fun(integer a, integer j, integer m) =
    ((a == 0) && (m > 0) && (j == 1));

  predicate trans_fun(integer a, integer j, integer m, integer a_next, integer j_next, integer m_next) =
    (((j > m) && (a_next == a) && (j_next == j) && (m_next == m)) || ((j <= m) && (j_next == (j + 1)) && (a_next == (a + 1)) && (m_next == m)) || ((j <= m) && (j_next == (j + 1)) && (a_next == (a - 1)) && (m_next == m)));

  predicate post_fun(integer a, integer j, integer m) =
    (!((j <= m)) ==> ((a >= (0 - m)) && (a <= m)));

  predicate inv_fun(integer a, integer j, integer m) =
    (((j <= m) && (a >= (-(j))) && (a <= j) && (((j + a) % 2) == 1)) || ((j > m) && (a >= (-(m))) && (a <= m)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long a, long long j, long long m) {
    return ((a == 0) && (m > 0) && (j == 1));
}

static inline _Bool c_trans_fun(long long a, long long j, long long m, long long a_next, long long j_next, long long m_next) {
    return (((j > m) && (a_next == a) && (j_next == j) && (m_next == m)) || ((j <= m) && (j_next == (j + 1)) && (a_next == (a + 1)) && (m_next == m)) || ((j <= m) && (j_next == (j + 1)) && (a_next == (a - 1)) && (m_next == m)));
}

static inline _Bool c_post_fun(long long a, long long j, long long m) {
    return (!(!((j <= m))) || ((a >= (0 - m)) && (a <= m)));
}

static inline _Bool c_inv_fun(long long a, long long j, long long m) {
    return (((j <= m) && (a >= (-(j))) && (a <= j) && (((j + a) % 2) == 1)) || ((j > m) && (a >= (-(m))) && (a <= m)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a = nondet_long();
    long long j = nondet_long();
    long long m = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(a, j, m)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a, j, m);
      @ loop assigns a, j, m;
      @*/
    while (1) {
        long long a_next = nondet_long();
        long long j_next = nondet_long();
        long long m_next = nondet_long();

        if (!c_trans_fun(a, j, m, a_next, j_next, m_next)) break;

        // State updates
        a = a_next;
        j = j_next;
        m = m_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(a, j, m));
    /*@ assert post_fun(a, j, m); */

    return 0;
}
