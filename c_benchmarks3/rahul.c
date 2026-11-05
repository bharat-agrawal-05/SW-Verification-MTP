/*
 * Generated C verification file from: rahul.sl
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
  predicate pre_fun(integer N, integer x, integer y) =
    ((N >= 0) && (x == y) && (x <= N));

  predicate trans_fun(integer N, integer x, integer y, integer N_next, integer x_next, integer y_next) =
    ((y >= 0) && (((x <= N) && (y_next == (y + 1))) || ((x > N) && (y_next == (y - 1)))) && (x_next == (x + 1)) && (N_next == N));

  predicate post_fun(integer N, integer x, integer y) =
    ((y >= 0) || (x < (4 + (2 * N))));

  predicate inv_fun(integer N, integer x, integer y) =
    (!(((2 * N) <= (-4 + x))) && (((-1 * x) + (2 * N)) >= (-2 + y)) && (x >= y));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long N, long long x, long long y) {
    return ((N >= 0) && (x == y) && (x <= N));
}

static inline _Bool c_trans_fun(long long N, long long x, long long y, long long N_next, long long x_next, long long y_next) {
    return ((y >= 0) && (((x <= N) && (y_next == (y + 1))) || ((x > N) && (y_next == (y - 1)))) && (x_next == (x + 1)) && (N_next == N));
}

static inline _Bool c_post_fun(long long N, long long x, long long y) {
    return ((y >= 0) || (x < (4 + (2 * N))));
}

static inline _Bool c_inv_fun(long long N, long long x, long long y) {
    return (!(((2 * N) <= (-4 + x))) && (((-1 * x) + (2 * N)) >= (-2 + y)) && (x >= y));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long N = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(N, x, y)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(N, x, y);
      @ loop assigns N, x, y;
      @*/
    while (1) {
        long long N_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();

        if (!c_trans_fun(N, x, y, N_next, x_next, y_next)) break;

        // State updates
        N = N_next;
        x = x_next;
        y = y_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(N, x, y));
    /*@ assert post_fun(N, x, y); */

    return 0;
}
