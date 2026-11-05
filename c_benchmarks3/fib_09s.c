/*
 * Generated C verification file from: fib_09s.sl
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
  predicate pre_fun(integer i, integer pvlen, integer t, integer k, integer n, integer j, integer turn) =
    ((k == 0) && (i == 0) && (turn == 0));

  predicate trans_fun(integer i, integer pvlen, integer t, integer k, integer n, integer j, integer turn, integer i_next, integer pvlen_next, integer t_next, integer k_next, integer n_next, integer j_next, integer turn_next) =
    (((turn == 0) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 0)) || ((turn == 0) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 1)) || ((turn == 1) && (i > pvlen) && (i_next == 0) && (pvlen_next == i) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && (i <= pvlen) && (i_next == 0) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 2) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == i) && (k_next == (k + 1)) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 2) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == i) && (k_next == (k + 1)) && (n_next == n) && (j_next == j) && (turn_next == 3)) || ((turn == 3) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 3)) || ((turn == 3) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 4)) || ((turn == 4) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == i) && (j_next == 0) && (turn_next == 5)));

  predicate post_fun(integer i, integer pvlen, integer t, integer k, integer n, integer j, integer turn) =
    (k >= 0);

  predicate inv_fun(integer i, integer pvlen, integer t, integer k, integer n, integer j, integer turn) =
    ((k >= 0) && (i >= 0) && (turn >= 0) && (turn <= 5));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long i, long long pvlen, long long t, long long k, long long n, long long j, long long turn) {
    return ((k == 0) && (i == 0) && (turn == 0));
}

static inline _Bool c_trans_fun(long long i, long long pvlen, long long t, long long k, long long n, long long j, long long turn, long long i_next, long long pvlen_next, long long t_next, long long k_next, long long n_next, long long j_next, long long turn_next) {
    return (((turn == 0) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 0)) || ((turn == 0) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 1)) || ((turn == 1) && (i > pvlen) && (i_next == 0) && (pvlen_next == i) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && (i <= pvlen) && (i_next == 0) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 2) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == i) && (k_next == (k + 1)) && (n_next == n) && (j_next == j) && (turn_next == 2)) || ((turn == 2) && (i_next == (i + 1)) && (pvlen_next == pvlen) && (t_next == i) && (k_next == (k + 1)) && (n_next == n) && (j_next == j) && (turn_next == 3)) || ((turn == 3) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 3)) || ((turn == 3) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == n) && (j_next == j) && (turn_next == 4)) || ((turn == 4) && (i_next == i) && (pvlen_next == pvlen) && (t_next == t) && (k_next == k) && (n_next == i) && (j_next == 0) && (turn_next == 5)));
}

static inline _Bool c_post_fun(long long i, long long pvlen, long long t, long long k, long long n, long long j, long long turn) {
    return (k >= 0);
}

static inline _Bool c_inv_fun(long long i, long long pvlen, long long t, long long k, long long n, long long j, long long turn) {
    return ((k >= 0) && (i >= 0) && (turn >= 0) && (turn <= 5));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long pvlen = nondet_long();
    long long t = nondet_long();
    long long k = nondet_long();
    long long n = nondet_long();
    long long j = nondet_long();
    long long turn = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(i, pvlen, t, k, n, j, turn)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, pvlen, t, k, n, j, turn);
      @ loop assigns i, pvlen, t, k, n, j, turn;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long pvlen_next = nondet_long();
        long long t_next = nondet_long();
        long long k_next = nondet_long();
        long long n_next = nondet_long();
        long long j_next = nondet_long();
        long long turn_next = nondet_long();

        if (!c_trans_fun(i, pvlen, t, k, n, j, turn, i_next, pvlen_next, t_next, k_next, n_next, j_next, turn_next)) break;

        // State updates
        i = i_next;
        pvlen = pvlen_next;
        t = t_next;
        k = k_next;
        n = n_next;
        j = j_next;
        turn = turn_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(i, pvlen, t, k, n, j, turn));
    /*@ assert post_fun(i, pvlen, t, k, n, j, turn); */

    return 0;
}
