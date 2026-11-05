/*
 * Generated C verification file from: minor1.sl
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
  predicate pre_fun(integer x) =
    ((x <= -2) && (x >= -3));

  predicate trans_fun(integer x, integer x_next) =
    (((x_next == (x + 2)) && (x < 1)) || ((x_next == (x + 1)) && (x >= 1)));

  predicate post_fun(integer x) =
    ((x >= -5));

  predicate inv_fun(integer x) =
    (((x <= -2) || (x >= -4)) && ((x == -2) || (x >= -3)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x) {
    return ((x <= -2) && (x >= -3));
}

static inline _Bool c_trans_fun(long long x, long long x_next) {
    return (((x_next == (x + 2)) && (x < 1)) || ((x_next == (x + 1)) && (x >= 1)));
}

static inline _Bool c_post_fun(long long x) {
    return ((x >= -5));
}

static inline _Bool c_inv_fun(long long x) {
    return (((x <= -2) || (x >= -4)) && ((x == -2) || (x >= -3)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x);
      @ loop assigns x;
      @*/
    while (1) {
        long long x_next = nondet_long();

        if (!c_trans_fun(x, x_next)) break;

        // State updates
        x = x_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x));
    /*@ assert post_fun(x); */

    return 0;
}
