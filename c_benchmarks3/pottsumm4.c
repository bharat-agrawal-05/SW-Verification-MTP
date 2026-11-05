/*
 * Generated C verification file from: pottsumm4.sl
 * SMT-LIB Logic: NIA
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
  predicate pre_f(integer x, integer y, integer i, integer k) =
    ((x == 0) && (y == 0) && (i == 0) && (k >= 0));

  predicate trans_f(integer x, integer y, integer i, integer k, integer x_next, integer y_next, integer i_next, integer k_next) =
    ((i < k) && (k_next == k) && (i_next == (i + 1)) && (y_next == (y + 1)) && (x_next == (x + (y_next * y_next * y_next))));

  predicate post_f(integer x, integer y, integer i, integer k) =
    ((i < k) || ((y == k) && ((4 * x) == (((2 * ((y * y) * y)) + (y * y)) + ((y * y) * (y * y))))));

  predicate inv_f(integer x, integer y, integer i, integer k) =
    ((i >= 0) && (i <= k) && ((4 * x) == ((2 * ((y * y) * y)) + (y * y) + ((y * y) * (y * y)))) && (y == i));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long x, long long y, long long i, long long k) {
    return ((x == 0) && (y == 0) && (i == 0) && (k >= 0));
}

static inline _Bool c_trans_f(long long x, long long y, long long i, long long k, long long x_next, long long y_next, long long i_next, long long k_next) {
    return ((i < k) && (k_next == k) && (i_next == (i + 1)) && (y_next == (y + 1)) && (x_next == (x + (y_next * y_next * y_next))));
}

static inline _Bool c_post_f(long long x, long long y, long long i, long long k) {
    return ((i < k) || ((y == k) && ((4 * x) == (((2 * ((y * y) * y)) + (y * y)) + ((y * y) * (y * y))))));
}

static inline _Bool c_inv_f(long long x, long long y, long long i, long long k) {
    return ((i >= 0) && (i <= k) && ((4 * x) == ((2 * ((y * y) * y)) + (y * y) + ((y * y) * (y * y)))) && (y == i));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long i = nondet_long();
    long long k = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(x, y, i, k)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(x, y, i, k);
      @ loop assigns x, y, i, k;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long i_next = nondet_long();
        long long k_next = nondet_long();

        if (!c_trans_f(x, y, i, k, x_next, y_next, i_next, k_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        i = i_next;
        k = k_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(x, y, i, k));
    /*@ assert post_f(x, y, i, k); */

    return 0;
}
