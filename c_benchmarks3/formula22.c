/*
 * Generated C verification file from: formula22.sl
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
  predicate pre_fun(integer x1, integer x2, integer x3) =
    ((x1 == 0) && ((x2 == 0) && (x3 == 0)));

  predicate trans_fun(integer x1, integer x2, integer x3, integer x1_next, integer x2_next, integer x3_next) =
    ((x1_next <= x2_next) && ((x2_next >= 0) || ((x2_next - x3_next) <= 2)));

  predicate post_fun(integer x1, integer x2, integer x3) =
    ((x1 <= x2) && ((x2 >= 0) || ((x2 - x3) <= 2)));

  predicate inv_fun(integer x1, integer x2, integer x3) =
    ((x1 <= x2) && ((x2 <= (x3 + 2)) || (x2 >= 0)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x1, long long x2, long long x3) {
    return ((x1 == 0) && ((x2 == 0) && (x3 == 0)));
}

static inline _Bool c_trans_fun(long long x1, long long x2, long long x3, long long x1_next, long long x2_next, long long x3_next) {
    return ((x1_next <= x2_next) && ((x2_next >= 0) || ((x2_next - x3_next) <= 2)));
}

static inline _Bool c_post_fun(long long x1, long long x2, long long x3) {
    return ((x1 <= x2) && ((x2 >= 0) || ((x2 - x3) <= 2)));
}

static inline _Bool c_inv_fun(long long x1, long long x2, long long x3) {
    return ((x1 <= x2) && ((x2 <= (x3 + 2)) || (x2 >= 0)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long x3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x1, x2, x3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x1, x2, x3);
      @ loop assigns x1, x2, x3;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long x3_next = nondet_long();

        if (!c_trans_fun(x1, x2, x3, x1_next, x2_next, x3_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        x3 = x3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x1, x2, x3));
    /*@ assert post_fun(x1, x2, x3); */

    return 0;
}
