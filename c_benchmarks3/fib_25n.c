/*
 * Generated C verification file from: fib_25n.sl
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
  predicate pre_fun(integer x, integer y, integer i, integer j, integer turn) =
    ((x == 0) && (y == 0) && (i == 0) && (j == 0) && (turn == 0));

  predicate trans_fun(integer x, integer y, integer i, integer j, integer turn, integer x_next, integer y_next, integer i_next, integer j_next, integer turn_next) =
    (((turn == 0) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == j) && (turn_next == 1)) || ((turn == 0) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && (x == y) && (x_next == x) && (y_next == y) && (i_next == (i + 1)) && (j_next == j) && (turn_next == 1)) || ((turn == 1) && (x == y) && (x_next == x) && (y_next == y) && (i_next == (i + 1)) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && !((x == y)) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == (j + 1)) && (turn_next == 1)) || ((turn == 1) && !((x == y)) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == (j + 1)) && (turn_next == 2)) || ((turn == 2) && (i >= j) && (x_next == (x + 1)) && (y_next == (y + 1)) && (i_next == i) && (j_next == j) && (turn_next == 0)) || ((turn == 2) && (i < j) && (x_next == x) && (y_next == (y + 1)) && (i_next == i) && (j_next == j) && (turn_next == 0)));

  predicate post_fun(integer x, integer y, integer i, integer j, integer turn) =
    (i >= j);

  predicate inv_fun(integer x, integer y, integer i, integer j, integer turn) =
    ((i >= j) && (x == y));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long i, long long j, long long turn) {
    return ((x == 0) && (y == 0) && (i == 0) && (j == 0) && (turn == 0));
}

static inline _Bool c_trans_fun(long long x, long long y, long long i, long long j, long long turn, long long x_next, long long y_next, long long i_next, long long j_next, long long turn_next) {
    return (((turn == 0) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == j) && (turn_next == 1)) || ((turn == 0) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && (x == y) && (x_next == x) && (y_next == y) && (i_next == (i + 1)) && (j_next == j) && (turn_next == 1)) || ((turn == 1) && (x == y) && (x_next == x) && (y_next == y) && (i_next == (i + 1)) && (j_next == j) && (turn_next == 2)) || ((turn == 1) && !((x == y)) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == (j + 1)) && (turn_next == 1)) || ((turn == 1) && !((x == y)) && (x_next == x) && (y_next == y) && (i_next == i) && (j_next == (j + 1)) && (turn_next == 2)) || ((turn == 2) && (i >= j) && (x_next == (x + 1)) && (y_next == (y + 1)) && (i_next == i) && (j_next == j) && (turn_next == 0)) || ((turn == 2) && (i < j) && (x_next == x) && (y_next == (y + 1)) && (i_next == i) && (j_next == j) && (turn_next == 0)));
}

static inline _Bool c_post_fun(long long x, long long y, long long i, long long j, long long turn) {
    return (i >= j);
}

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long j, long long turn) {
    return ((i >= j) && (x == y));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long i = nondet_long();
    long long j = nondet_long();
    long long turn = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, i, j, turn)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, j, turn);
      @ loop assigns x, y, i, j, turn;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long turn_next = nondet_long();

        if (!c_trans_fun(x, y, i, j, turn, x_next, y_next, i_next, j_next, turn_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        i = i_next;
        j = j_next;
        turn = turn_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, i, j, turn));
    /*@ assert post_fun(x, y, i, j, turn); */

    return 0;
}
