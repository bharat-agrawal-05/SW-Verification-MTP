/*
 * Generated C verification file from: hola.05.sl
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
  predicate pre_fun(integer x, integer y, integer i, integer j) =
    ((j == 0) && ((i == 0) && ((x == 0) && (y == 0))));

  predicate trans_fun(integer x, integer y, integer i, integer j, integer x_next, integer y_next, integer i_next, integer j_next) =
    ((x_next == (x + 1)) && ((y_next == (y + 1)) && ((i_next == (i + (x + 1))) && ((j_next == (j + (y + 1))) || (j_next == (j + (y + 2)))))));

  predicate post_fun(integer x, integer y, integer i, integer j) =
    (j >= i);

  predicate inv_fun(integer x, integer y, integer i, integer j) =
    ((i <= j) && (x <= y));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long i, long long j) {
    return ((j == 0) && ((i == 0) && ((x == 0) && (y == 0))));
}

static inline _Bool c_trans_fun(long long x, long long y, long long i, long long j, long long x_next, long long y_next, long long i_next, long long j_next) {
    return ((x_next == (x + 1)) && ((y_next == (y + 1)) && ((i_next == (i + (x + 1))) && ((j_next == (j + (y + 1))) || (j_next == (j + (y + 2)))))));
}

static inline _Bool c_post_fun(long long x, long long y, long long i, long long j) {
    return (j >= i);
}

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long j) {
    return ((i <= j) && (x <= y));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long i = nondet_long();
    long long j = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, i, j)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, j);
      @ loop assigns x, y, i, j;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long i_next = nondet_long();
        long long j_next = nondet_long();

        if (!c_trans_fun(x, y, i, j, x_next, y_next, i_next, j_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        i = i_next;
        j = j_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, i, j));
    /*@ assert post_fun(x, y, i, j); */

    return 0;
}
