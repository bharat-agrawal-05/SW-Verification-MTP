/*
 * Generated C verification file from: add-array.sl
 * SMT-LIB Logic: ALIA
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
  predicate pre_fun(integer x[], integer y, integer n) =
    ((n >= 0) && ((n == x[0]) && (y == 0)));

  predicate trans_fun(integer x[], integer y, integer n, integer x_next[], integer y_next, integer n_next) =
    ((x[0] > 0) && ((n_next == n) && ((y_next == (y + 1)) && ((x_next[0] == (x[0] - 1)) && (\forall integer _k; !((_k == 0)) ==> (x_next[_k] == x[_k]))))));

  predicate post_fun(integer x[], integer y, integer n) =
    ((x[0] > 0) || (n == (x[0] + y)));

  predicate inv_fun(integer x[], integer y, integer n) =
    ((x[0] >= 0) && ((x[0] + y) == n));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long x[], long long y, long long n) {
    return ((n >= 0) && ((n == x[0]) && (y == 0)));
}

static inline _Bool c_trans_fun(const long long x[], long long y, long long n, const long long x_next[], long long y_next, long long n_next) {
    return ((x[0] > 0) && ((n_next == n) && ((y_next == (y + 1)) && ((x_next[0] == (x[0] - 1))))));
}

static inline _Bool c_post_fun(const long long x[], long long y, long long n) {
    return ((x[0] > 0) || (n == (x[0] + y)));
}

static inline _Bool c_inv_fun(const long long x[], long long y, long long n) {
    return ((x[0] >= 0) && ((x[0] + y) == n));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x[100];
    for (int _i = 0; _i < 100; ++_i) { x[_i] = nondet_long(); }
    long long y = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, n);
      @ loop assigns x[0..99], y, n;
      @*/
    while (1) {
        long long x_next[100];
        for (int _i = 0; _i < 100; ++_i) { x_next[_i] = nondet_long(); }
        long long y_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_trans_fun(x, y, n, x_next, y_next, n_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { x[_i] = x_next[_i]; }
        y = y_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, n));
    /*@ assert post_fun(x, y, n); */

    return 0;
}
