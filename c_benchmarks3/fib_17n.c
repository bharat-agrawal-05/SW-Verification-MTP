/*
 * Generated C verification file from: fib_17n.sl
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
  predicate pre_fun(integer k, integer i, integer j, integer n, integer turn) =
    ((k == 1) && (i == 1) && (j == 0) && (turn == 0));

  predicate trans_fun(integer k, integer i, integer j, integer n, integer turn, integer k_next, integer i_next, integer j_next, integer n_next, integer turn_next) =
    (((turn == 0) && (i < n) && (k_next == k) && (i_next == i) && (j_next == 0) && (n_next == n) && (turn_next == 1)) || ((turn == 0) && (i >= n) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == 3)) || ((turn == 1) && (j < i) && (k_next == ((k + i) - j)) && (i_next == i) && (j_next == (j + 1)) && (n_next == n) && (turn_next == turn)) || ((turn == 1) && (j >= i) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == 2)) || ((turn == 2) && (k_next == k) && (i_next == (i + 1)) && (j_next == j) && (n_next == n) && (turn_next == 0)) || ((turn >= 3) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == turn)) || ((turn < 0) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == turn)));

  predicate post_fun(integer k, integer i, integer j, integer n, integer turn) =
    ((turn == 3) ==> (k >= n));

  predicate inv_fun(integer k, integer i, integer j, integer n, integer turn) =
    ((!((turn == 3)) || (k >= n)) && (k >= i) && (((k + (-1 * i)) >= turn) || !((k <= i)) || (1 == turn) || (3 == turn)) && !((k <= j)) && (i >= 1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long k, long long i, long long j, long long n, long long turn) {
    return ((k == 1) && (i == 1) && (j == 0) && (turn == 0));
}

static inline _Bool c_trans_fun(long long k, long long i, long long j, long long n, long long turn, long long k_next, long long i_next, long long j_next, long long n_next, long long turn_next) {
    return (((turn == 0) && (i < n) && (k_next == k) && (i_next == i) && (j_next == 0) && (n_next == n) && (turn_next == 1)) || ((turn == 0) && (i >= n) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == 3)) || ((turn == 1) && (j < i) && (k_next == ((k + i) - j)) && (i_next == i) && (j_next == (j + 1)) && (n_next == n) && (turn_next == turn)) || ((turn == 1) && (j >= i) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == 2)) || ((turn == 2) && (k_next == k) && (i_next == (i + 1)) && (j_next == j) && (n_next == n) && (turn_next == 0)) || ((turn >= 3) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == turn)) || ((turn < 0) && (k_next == k) && (i_next == i) && (j_next == j) && (n_next == n) && (turn_next == turn)));
}

static inline _Bool c_post_fun(long long k, long long i, long long j, long long n, long long turn) {
    return (!((turn == 3)) || (k >= n));
}

static inline _Bool c_inv_fun(long long k, long long i, long long j, long long n, long long turn) {
    return ((!((turn == 3)) || (k >= n)) && (k >= i) && (((k + (-1 * i)) >= turn) || !((k <= i)) || (1 == turn) || (3 == turn)) && !((k <= j)) && (i >= 1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long k = nondet_long();
    long long i = nondet_long();
    long long j = nondet_long();
    long long n = nondet_long();
    long long turn = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(k, i, j, n, turn)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(k, i, j, n, turn);
      @ loop assigns k, i, j, n, turn;
      @*/
    while (1) {
        long long k_next = nondet_long();
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long n_next = nondet_long();
        long long turn_next = nondet_long();

        if (!c_trans_fun(k, i, j, n, turn, k_next, i_next, j_next, n_next, turn_next)) break;

        // State updates
        k = k_next;
        i = i_next;
        j = j_next;
        n = n_next;
        turn = turn_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(k, i, j, n, turn));
    /*@ assert post_fun(k, i, j, n, turn); */

    return 0;
}
