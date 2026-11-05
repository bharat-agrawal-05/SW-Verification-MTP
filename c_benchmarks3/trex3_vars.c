/*
 * Generated C verification file from: trex3_vars.sl
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
  predicate pre_fun(integer x1, integer x2, integer x3, integer d1, integer d2, integer d3, integer v1, integer v2, integer v3) =
    ((d1 == 1) && ((d2 == 1) && (d3 == 1)));

  predicate trans_fun(integer x1, integer x2, integer x3, integer d1, integer d2, integer d3, integer v1, integer v2, integer v3, integer x1_next, integer x2_next, integer x3_next, integer d1_next, integer d2_next, integer d3_next, integer v1_next, integer v2_next, integer v3_next) =
    ((((x2_next == x2) && ((x3_next == x3) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x1_next == (x1 + (0 - d1))))))) || ((((x1_next == x1) && ((x3_next == x3) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x2_next == (x2 + (0 - d2))))))) || (((x1_next == x1) && ((x2_next == x2) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x3_next == (x3 + (0 - d3)))))))));

  predicate post_fun(integer x1, integer x2, integer x3, integer d1, integer d2, integer d3, integer v1, integer v2, integer v3) =
    ((x1 < 0) || ((x2 < 0) || ((x3 < 0) || ((x1 == 0) || ((x2 == 0) || (x3 == 0))))));

  predicate inv_fun(integer x1, integer x2, integer x3, integer d1, integer d2, integer d3, integer v1, integer v2, integer v3) =
    \false;

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x1, long long x2, long long x3, long long d1, long long d2, long long d3, long long v1, long long v2, long long v3) {
    return ((d1 == 1) && ((d2 == 1) && (d3 == 1)));
}

static inline _Bool c_trans_fun(long long x1, long long x2, long long x3, long long d1, long long d2, long long d3, long long v1, long long v2, long long v3, long long x1_next, long long x2_next, long long x3_next, long long d1_next, long long d2_next, long long d3_next, long long v1_next, long long v2_next, long long v3_next) {
    return ((((x2_next == x2) && ((x3_next == x3) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x1_next == (x1 + (0 - d1))))))) || ((((x1_next == x1) && ((x3_next == x3) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x2_next == (x2 + (0 - d2))))))) || (((x1_next == x1) && ((x2_next == x2) && ((d1_next == d1) && ((d2_next == d2) && (d3_next == d3))))) && ((x1 > 0) && ((x2 > 0) && ((x3 > 0) && (x3_next == (x3 + (0 - d3)))))))));
}

static inline _Bool c_post_fun(long long x1, long long x2, long long x3, long long d1, long long d2, long long d3, long long v1, long long v2, long long v3) {
    return ((x1 < 0) || ((x2 < 0) || ((x3 < 0) || ((x1 == 0) || ((x2 == 0) || (x3 == 0))))));
}

static inline _Bool c_inv_fun(long long x1, long long x2, long long x3, long long d1, long long d2, long long d3, long long v1, long long v2, long long v3) {
    return false;
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long x3 = nondet_long();
    long long d1 = nondet_long();
    long long d2 = nondet_long();
    long long d3 = nondet_long();
    long long v1 = nondet_long();
    long long v2 = nondet_long();
    long long v3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x1, x2, x3, d1, d2, d3, v1, v2, v3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x1, x2, x3, d1, d2, d3, v1, v2, v3);
      @ loop assigns x1, x2, x3, d1, d2, d3, v1, v2, v3;
      @*/
    while (1) {
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long x3_next = nondet_long();
        long long d1_next = nondet_long();
        long long d2_next = nondet_long();
        long long d3_next = nondet_long();
        long long v1_next = nondet_long();
        long long v2_next = nondet_long();
        long long v3_next = nondet_long();

        if (!c_trans_fun(x1, x2, x3, d1, d2, d3, v1, v2, v3, x1_next, x2_next, x3_next, d1_next, d2_next, d3_next, v1_next, v2_next, v3_next)) break;

        // State updates
        x1 = x1_next;
        x2 = x2_next;
        x3 = x3_next;
        d1 = d1_next;
        d2 = d2_next;
        d3 = d3_next;
        v1 = v1_next;
        v2 = v2_next;
        v3 = v3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x1, x2, x3, d1, d2, d3, v1, v2, v3));
    /*@ assert post_fun(x1, x2, x3, d1, d2, d3, v1, v2, v3); */

    return 0;
}
