/*
 * Generated C verification file from: hola.07.sl
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
  predicate pre_fun(integer x, integer y, integer i, integer n) =
    ((n >= 0) && ((i == 0) && ((x == 0) && (y == 0))));

  predicate trans_fun(integer x, integer y, integer i, integer n, integer x_next, integer y_next, integer i_next, integer n_next) =
    ((n_next == n) && ((i < n) && ((i_next == (i + 1)) && (((x_next == (x + 1)) && (y_next == (y + 2))) || ((x_next == (x + 2)) && (y_next == (y + 1)))))));

  predicate post_fun(integer x, integer y, integer i, integer n) =
    ((i < n) || ((3 * n) == (x + y)));

  predicate inv_fun(integer x, integer y, integer i, integer n) =
    (((i <= n) && ((x + y) == (3 * i))) || ((i > n) && ((x + y) == (3 * n))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long i, long long n) {
    return ((n >= 0) && ((i == 0) && ((x == 0) && (y == 0))));
}

static inline _Bool c_trans_fun(long long x, long long y, long long i, long long n, long long x_next, long long y_next, long long i_next, long long n_next) {
    return ((n_next == n) && ((i < n) && ((i_next == (i + 1)) && (((x_next == (x + 1)) && (y_next == (y + 2))) || ((x_next == (x + 2)) && (y_next == (y + 1)))))));
}

static inline _Bool c_post_fun(long long x, long long y, long long i, long long n) {
    return ((i < n) || ((3 * n) == (x + y)));
}

static inline _Bool c_inv_fun(long long x, long long y, long long i, long long n) {
    return (((i <= n) && ((x + y) == (3 * i))) || ((i > n) && ((x + y) == (3 * n))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long i = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, i, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, i, n);
      @ loop assigns x, y, i, n;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long i_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_trans_fun(x, y, i, n, x_next, y_next, i_next, n_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        i = i_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, i, n));
    /*@ assert post_fun(x, y, i, n); */

    return 0;
}
