/*
 * Generated C verification file from: fib_21.sl
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
  predicate pre_fun(integer i, integer j, integer k, integer c1, integer c2, integer n, integer v) =
    ((n > 0) && (n < 10) && (k == 0) && (i == 0) && (c1 == 4000) && (c2 == 2000));

  predicate trans_fun(integer i, integer j, integer k, integer c1, integer c2, integer n, integer v, integer i_next, integer j_next, integer k_next, integer c1_next, integer c2_next, integer n_next, integer v_next) =
    (((i >= n) && (i_next == i) && (j_next == j) && (k_next == k) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == v)) || ((i < n) && (i_next == (i + 1)) && (j_next == j) && (k_next == (k + c1)) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == 0)) || ((i < n) && (i_next == (i + 1)) && (j_next == j) && (k_next == (k + c2)) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == 1)));

  predicate post_fun(integer i, integer j, integer k, integer c1, integer c2, integer n, integer v) =
    ((i >= n) ==> (k > n));

  predicate inv_fun(integer i, integer j, integer k, integer c1, integer c2, integer n, integer v) =
    ((!((i >= n)) || !((k <= n))) && (2000 == c2) && (10 >= i) && (4000 == c1) && (k >= 0) && (10 >= n));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long i, long long j, long long k, long long c1, long long c2, long long n, long long v) {
    return ((n > 0) && (n < 10) && (k == 0) && (i == 0) && (c1 == 4000) && (c2 == 2000));
}

static inline _Bool c_trans_fun(long long i, long long j, long long k, long long c1, long long c2, long long n, long long v, long long i_next, long long j_next, long long k_next, long long c1_next, long long c2_next, long long n_next, long long v_next) {
    return (((i >= n) && (i_next == i) && (j_next == j) && (k_next == k) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == v)) || ((i < n) && (i_next == (i + 1)) && (j_next == j) && (k_next == (k + c1)) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == 0)) || ((i < n) && (i_next == (i + 1)) && (j_next == j) && (k_next == (k + c2)) && (c1_next == c1) && (c2_next == c2) && (n_next == n) && (v_next == 1)));
}

static inline _Bool c_post_fun(long long i, long long j, long long k, long long c1, long long c2, long long n, long long v) {
    return (!((i >= n)) || (k > n));
}

static inline _Bool c_inv_fun(long long i, long long j, long long k, long long c1, long long c2, long long n, long long v) {
    return ((!((i >= n)) || !((k <= n))) && (2000 == c2) && (10 >= i) && (4000 == c1) && (k >= 0) && (10 >= n));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long j = nondet_long();
    long long k = nondet_long();
    long long c1 = nondet_long();
    long long c2 = nondet_long();
    long long n = nondet_long();
    long long v = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(i, j, k, c1, c2, n, v)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, k, c1, c2, n, v);
      @ loop assigns i, j, k, c1, c2, n, v;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long k_next = nondet_long();
        long long c1_next = nondet_long();
        long long c2_next = nondet_long();
        long long n_next = nondet_long();
        long long v_next = nondet_long();

        if (!c_trans_fun(i, j, k, c1, c2, n, v, i_next, j_next, k_next, c1_next, c2_next, n_next, v_next)) break;

        // State updates
        i = i_next;
        j = j_next;
        k = k_next;
        c1 = c1_next;
        c2 = c2_next;
        n = n_next;
        v = v_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(i, j, k, c1, c2, n, v));
    /*@ assert post_fun(i, j, k, c1, c2, n, v); */

    return 0;
}
