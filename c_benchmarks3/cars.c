/*
 * Generated C verification file from: cars.sl
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
  predicate pre_fun(integer x1, integer x2, integer x3, integer v1, integer v2, integer v3, integer t, integer RETURN) =
    ((RETURN == 0) && (x1 == 100) && (x2 == 75) && (x3 == (0 - 50)) && (v3 >= 0) && (v1 <= 5) && ((v1 - v3) >= 0) && ((((2 * v2) - v1) - v3) == 0) && (t == 0) && ((v2 + 5) >= 0) && (v2 <= 5));

  predicate trans_fun(integer x1, integer x2, integer x3, integer v1, integer v2, integer v3, integer t, integer RETURN, integer x1_next, integer x2_next, integer x3_next, integer v1_next, integer v2_next, integer v3_next, integer t_next, integer RETURN_next) =
    ((RETURN == 0) && ((!(((v2 + 5) >= 0)) && (RETURN_next == 1)) || (((v2 + 5) >= 0) && (RETURN_next == RETURN))) && ((!((v2 <= 5)) && (RETURN_next == 1)) || ((v2 <= 5) && (RETURN_next == RETURN))) && ((((!(((((2 * x2) - x1) - x3) >= 0)) && (RETURN_next == 1)) || (((((2 * x2) - x1) - x3) >= 0) && (RETURN_next == RETURN))) && (x1_next == (x1 + v1)) && (x3_next == (x3 + v3)) && (x2_next == (x2 + v2)) && (v2_next == (v2 - 1)) && (v1_next == v1) && (v3_next == v3) && (t_next == (t + 1))) || (((!(((((2 * x2) - x1) - x3) <= 0)) && (RETURN_next == 1)) || (((((2 * x2) - x1) - x3) <= 0) && (RETURN_next == RETURN))) && (x1_next == (x1 + v1)) && (x3_next == (x3 + v3)) && (x2_next == (x2 + v2)) && (v2_next == (v2 + 1)) && (v1_next == v1) && (v3_next == v3) && (t_next == (t + 1)))));

  predicate post_fun(integer x1, integer x2, integer x3, integer v1, integer v2, integer v3, integer t, integer RETURN) =
    ((RETURN == 0) ==> ((v1 <= 5) && (((2 * v2) + (2 * t)) >= (v1 + v3)) && (((5 * t) + 75) >= x2) && (v2 <= 6) && (v3 >= 0) && ((v2 + 6) >= 0) && ((x2 + (5 * t)) >= 75) && (((v1 + v3 + (2 * t)) - (2 * v2)) >= 0) && ((v1 - v3) >= 0)));

  predicate inv_fun(integer x1, integer x2, integer x3, integer v1, integer v2, integer v3, integer t, integer RETURN) =
    ((v1 <= 5) && (v3 >= 0) && (v2 <= 6) && ((v2 + 6) >= 0) && ((v1 - v3) >= 0) && (((5 * t) + 75) >= x2) && (((2 * v2) + (2 * t)) >= (v1 + v3)) && ((x2 + (5 * t)) >= 75) && (((v1 + v3 + (2 * t)) - (2 * v2)) >= 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x1, long long x2, long long x3, long long v1, long long v2, long long v3, long long t, long long RETURN) {
    return ((RETURN == 0) && (x1 == 100) && (x2 == 75) && (x3 == (0 - 50)) && (v3 >= 0) && (v1 <= 5) && ((v1 - v3) >= 0) && ((((2 * v2) - v1) - v3) == 0) && (t == 0) && ((v2 + 5) >= 0) && (v2 <= 5));
}

static inline _Bool c_trans_fun(long long x1, long long x2, long long x3, long long v1, long long v2, long long v3, long long t, long long RETURN, long long x1_next, long long x2_next, long long x3_next, long long v1_next, long long v2_next, long long v3_next, long long t_next, long long RETURN_next) {
    return ((RETURN == 0) && ((!(((v2 + 5) >= 0)) && (RETURN_next == 1)) || (((v2 + 5) >= 0) && (RETURN_next == RETURN))) && ((!((v2 <= 5)) && (RETURN_next == 1)) || ((v2 <= 5) && (RETURN_next == RETURN))) && ((((!(((((2 * x2) - x1) - x3) >= 0)) && (RETURN_next == 1)) || (((((2 * x2) - x1) - x3) >= 0) && (RETURN_next == RETURN))) && (x1_next == (x1 + v1)) && (x3_next == (x3 + v3)) && (x2_next == (x2 + v2)) && (v2_next == (v2 - 1)) && (v1_next == v1) && (v3_next == v3) && (t_next == (t + 1))) || (((!(((((2 * x2) - x1) - x3) <= 0)) && (RETURN_next == 1)) || (((((2 * x2) - x1) - x3) <= 0) && (RETURN_next == RETURN))) && (x1_next == (x1 + v1)) && (x3_next == (x3 + v3)) && (x2_next == (x2 + v2)) && (v2_next == (v2 + 1)) && (v1_next == v1) && (v3_next == v3) && (t_next == (t + 1)))));
}

static inline _Bool c_post_fun(long long x1, long long x2, long long x3, long long v1, long long v2, long long v3, long long t, long long RETURN) {
    return (!((RETURN == 0)) || ((v1 <= 5) && (((2 * v2) + (2 * t)) >= (v1 + v3)) && (((5 * t) + 75) >= x2) && (v2 <= 6) && (v3 >= 0) && ((v2 + 6) >= 0) && ((x2 + (5 * t)) >= 75) && (((v1 + v3 + (2 * t)) - (2 * v2)) >= 0) && ((v1 - v3) >= 0)));
}

static inline _Bool c_inv_fun(long long x1, long long x2, long long x3, long long v1, long long v2, long long v3, long long t, long long RETURN) {
    return ((v1 <= 5) && (v3 >= 0) && (v2 <= 6) && ((v2 + 6) >= 0) && ((v1 - v3) >= 0) && (((5 * t) + 75) >= x2) && (((2 * v2) + (2 * t)) >= (v1 + v3)) && ((x2 + (5 * t)) >= 75) && (((v1 + v3 + (2 * t)) - (2 * v2)) >= 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long x3 = nondet_long();
    long long v1 = nondet_long();
    long long v2 = nondet_long();
    long long v3 = nondet_long();
    long long t = nondet_long();
    long long RETURN = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x1, x2, x3, v1, v2, v3, t, RETURN)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x1, x2, x3, v1, v2, v3, t, RETURN);
      @ loop assigns x1, x2, x3, v1, v2, v3, t, RETURN;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long x3_next = nondet_long();
        long long v1_next = nondet_long();
        long long v2_next = nondet_long();
        long long v3_next = nondet_long();
        long long t_next = nondet_long();
        long long RETURN_next = nondet_long();

        if (!c_trans_fun(x1, x2, x3, v1, v2, v3, t, RETURN, x1_next, x2_next, x3_next, v1_next, v2_next, v3_next, t_next, RETURN_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        x3 = x3_next;
        v1 = v1_next;
        v2 = v2_next;
        v3 = v3_next;
        t = t_next;
        RETURN = RETURN_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x1, x2, x3, v1, v2, v3, t, RETURN));
    /*@ assert post_fun(x1, x2, x3, v1, v2, v3, t, RETURN); */

    return 0;
}
