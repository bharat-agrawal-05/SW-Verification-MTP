/*
 * Generated C verification file from: formula25.sl
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
  predicate pre_fun(integer x1, integer x2, integer x3, integer x4) =
    (((x1 == 0) && ((x2 == 0) && (x3 == 0))) && (x4 == -1));

  predicate trans_fun(integer x1, integer x2, integer x3, integer x4, integer x1_next, integer x2_next, integer x3_next, integer x4_next) =
    ((x1_next <= 0) && ((x1_next >= (x4_next + 1)) && ((x2_next == x3_next) && ((x4_next >= 0) || (x4_next <= x3_next)))));

  predicate post_fun(integer x1, integer x2, integer x3, integer x4) =
    ((x1 <= 0) && ((x1 >= (x4 + 1)) && ((x2 == x3) && ((x4 >= 0) || (x4 <= x3)))));

  predicate inv_fun(integer x1, integer x2, integer x3, integer x4) =
    ((x1 <= 0) && ((x1 >= (x4 + 1)) && ((x2 == x3) && ((x4 >= 0) || (x4 <= x3)))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x1, long long x2, long long x3, long long x4) {
    return (((x1 == 0) && ((x2 == 0) && (x3 == 0))) && (x4 == -1));
}

static inline _Bool c_trans_fun(long long x1, long long x2, long long x3, long long x4, long long x1_next, long long x2_next, long long x3_next, long long x4_next) {
    return ((x1_next <= 0) && ((x1_next >= (x4_next + 1)) && ((x2_next == x3_next) && ((x4_next >= 0) || (x4_next <= x3_next)))));
}

static inline _Bool c_post_fun(long long x1, long long x2, long long x3, long long x4) {
    return ((x1 <= 0) && ((x1 >= (x4 + 1)) && ((x2 == x3) && ((x4 >= 0) || (x4 <= x3)))));
}

static inline _Bool c_inv_fun(long long x1, long long x2, long long x3, long long x4) {
    return ((x1 <= 0) && ((x1 >= (x4 + 1)) && ((x2 == x3) && ((x4 >= 0) || (x4 <= x3)))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long x3 = nondet_long();
    long long x4 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x1, x2, x3, x4)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x1, x2, x3, x4);
      @ loop assigns x1, x2, x3, x4;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long x3_next = nondet_long();
        long long x4_next = nondet_long();

        if (!c_trans_fun(x1, x2, x3, x4, x1_next, x2_next, x3_next, x4_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        x3 = x3_next;
        x4 = x4_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x1, x2, x3, x4));
    /*@ assert post_fun(x1, x2, x3, x4); */

    return 0;
}
