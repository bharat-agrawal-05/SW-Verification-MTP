/*
 * Generated C verification file from: 130_conf5.sl
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
  predicate pre_f(integer d1, integer d2, integer d3, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x1, integer x2, integer x3, integer d1_0, integer d1_1, integer d2_0, integer d2_1, integer d3_0, integer d3_1, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer x1_0, integer x1_1, integer x1_2, integer x1_3, integer x1_4, integer x2_0, integer x2_1, integer x2_2, integer x2_3, integer x3_0, integer x3_1, integer x3_2, integer x3_3) =
    ((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (x1 == x1_1) && (conf_0_0 == 4) && (conf_1_0 == 8) && (conf_2_0 == 5) && (conf_3_0 == 9) && (conf_4_0 == 7) && (d1_1 == 1) && (d2_1 == 1) && (d3_1 == 1) && (x1_1 == 1));

  predicate trans_f(integer d1, integer d2, integer d3, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x1, integer x2, integer x3, integer d1_0, integer d1_1, integer d2_0, integer d2_1, integer d3_0, integer d3_1, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer x1_0, integer x1_1, integer x1_2, integer x1_3, integer x1_4, integer x2_0, integer x2_1, integer x2_2, integer x2_3, integer x3_0, integer x3_1, integer x3_2, integer x3_3, integer d1_next, integer d2_next, integer d3_next, integer conf_0_next, integer conf_1_next, integer conf_2_next, integer conf_3_next, integer conf_4_next, integer x1_next, integer x2_next, integer x3_next, integer d1_0_next, integer d1_1_next, integer d2_0_next, integer d2_1_next, integer d3_0_next, integer d3_1_next, integer conf_0_0_next, integer conf_1_0_next, integer conf_1_1_next, integer conf_1_2_next, integer conf_1_3_next, integer conf_2_0_next, integer conf_3_0_next, integer conf_3_1_next, integer conf_3_2_next, integer conf_3_3_next, integer conf_4_0_next, integer conf_4_1_next, integer conf_4_2_next, integer conf_4_3_next, integer x1_0_next, integer x1_1_next, integer x1_2_next, integer x1_3_next, integer x1_4_next, integer x2_0_next, integer x2_1_next, integer x2_2_next, integer x2_3_next, integer x3_0_next, integer x3_1_next, integer x3_2_next, integer x3_3_next) =
    (((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (x1_2 == x1) && (x2_1 == x2) && (x3_1 == x3) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (conf_4_1 == conf_4_next) && (x1_2 == x1_next) && (x2_1 == x2_next) && (x3_1 == x3_next) && (d1 == d1_next) && (d2 == d2_next) && (d3 == d3_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (x2 == x2_next) && (x3 == x3_next)) || (!((x1_2 > 0)) && !((x2_1 >= 0)) && (d1 == d1_1) && (d1_next == d1_1) && (d2 == d2_1) && (d2_next == d2_1) && (d3 == d3_1) && (d3_next == d3_1) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (x1 == x1_1) && (x1_next == x1_1) && (x2 == x2_0) && (x2_next == x2_0) && (x3 == x3_0) && (x3_next == x3_0)));

  predicate post_f(integer d1, integer d2, integer d3, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x1, integer x2, integer x3, integer d1_0, integer d1_1, integer d2_0, integer d2_1, integer d3_0, integer d3_1, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer x1_0, integer x1_1, integer x1_2, integer x1_3, integer x1_4, integer x2_0, integer x2_1, integer x2_2, integer x2_3, integer x3_0, integer x3_1, integer x3_2, integer x3_3) =
    ((!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && (x2_1 > 0) && (x3_1 > 0) && (x1_3 == (x1_2 - d1_1)) && (conf_1_2 == (conf_4_1 + 828)) && (x2_2 == (x2_1 - d2_1)) && (conf_4_2 == (conf_4_1 + 435)) && (x3_2 == (x3_1 - d3_1)) && (conf_3_2 == (conf_2_0 - 854)) && (conf_1_3 == conf_1_2) && (conf_3_3 == conf_3_2) && (conf_4_3 == conf_4_2) && (x1_4 == x1_3) && (x2_3 == x2_2) && (x3_3 == x3_2) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))) && (!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && (x2_1 > 0) && !((x3_1 > 0)) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_3 == conf_4_1) && (x1_4 == x1_2) && (x2_3 == x2_1) && (x3_3 == x3_1) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))) && (!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && !((x2_1 > 0)) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_3 == conf_4_1) && (x1_4 == x1_2) && (x2_3 == x2_1) && (x3_3 == x3_1) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))));

  predicate inv_f(integer d1, integer d2, integer d3, integer conf_0, integer conf_1, integer conf_2, integer conf_3, integer conf_4, integer x1, integer x2, integer x3, integer d1_0, integer d1_1, integer d2_0, integer d2_1, integer d3_0, integer d3_1, integer conf_0_0, integer conf_1_0, integer conf_1_1, integer conf_1_2, integer conf_1_3, integer conf_2_0, integer conf_3_0, integer conf_3_1, integer conf_3_2, integer conf_3_3, integer conf_4_0, integer conf_4_1, integer conf_4_2, integer conf_4_3, integer x1_0, integer x1_1, integer x1_2, integer x1_3, integer x1_4, integer x2_0, integer x2_1, integer x2_2, integer x2_3, integer x3_0, integer x3_1, integer x3_2, integer x3_3) =
    (1 == x1);

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long d1, long long d2, long long d3, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x1, long long x2, long long x3, long long d1_0, long long d1_1, long long d2_0, long long d2_1, long long d3_0, long long d3_1, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long x1_0, long long x1_1, long long x1_2, long long x1_3, long long x1_4, long long x2_0, long long x2_1, long long x2_2, long long x2_3, long long x3_0, long long x3_1, long long x3_2, long long x3_3) {
    return ((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_0) && (conf_2 == conf_2_0) && (conf_3 == conf_3_0) && (conf_4 == conf_4_0) && (x1 == x1_1) && (conf_0_0 == 4) && (conf_1_0 == 8) && (conf_2_0 == 5) && (conf_3_0 == 9) && (conf_4_0 == 7) && (d1_1 == 1) && (d2_1 == 1) && (d3_1 == 1) && (x1_1 == 1));
}

static inline _Bool c_trans_f(long long d1, long long d2, long long d3, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x1, long long x2, long long x3, long long d1_0, long long d1_1, long long d2_0, long long d2_1, long long d3_0, long long d3_1, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long x1_0, long long x1_1, long long x1_2, long long x1_3, long long x1_4, long long x2_0, long long x2_1, long long x2_2, long long x2_3, long long x3_0, long long x3_1, long long x3_2, long long x3_3, long long d1_next, long long d2_next, long long d3_next, long long conf_0_next, long long conf_1_next, long long conf_2_next, long long conf_3_next, long long conf_4_next, long long x1_next, long long x2_next, long long x3_next, long long d1_0_next, long long d1_1_next, long long d2_0_next, long long d2_1_next, long long d3_0_next, long long d3_1_next, long long conf_0_0_next, long long conf_1_0_next, long long conf_1_1_next, long long conf_1_2_next, long long conf_1_3_next, long long conf_2_0_next, long long conf_3_0_next, long long conf_3_1_next, long long conf_3_2_next, long long conf_3_3_next, long long conf_4_0_next, long long conf_4_1_next, long long conf_4_2_next, long long conf_4_3_next, long long x1_0_next, long long x1_1_next, long long x1_2_next, long long x1_3_next, long long x1_4_next, long long x2_0_next, long long x2_1_next, long long x2_2_next, long long x2_3_next, long long x3_0_next, long long x3_1_next, long long x3_2_next, long long x3_3_next) {
    return (((conf_1_1 == conf_1) && (conf_3_1 == conf_3) && (conf_4_1 == conf_4) && (x1_2 == x1) && (x2_1 == x2) && (x3_1 == x3) && (conf_1_1 == conf_1_next) && (conf_3_1 == conf_3_next) && (conf_4_1 == conf_4_next) && (x1_2 == x1_next) && (x2_1 == x2_next) && (x3_1 == x3_next) && (d1 == d1_next) && (d2 == d2_next) && (d3 == d3_next) && (conf_0 == conf_0_next) && (conf_1 == conf_1_next) && (conf_2 == conf_2_next) && (conf_3 == conf_3_next) && (conf_4 == conf_4_next) && (x2 == x2_next) && (x3 == x3_next)) || (!((x1_2 > 0)) && !((x2_1 >= 0)) && (d1 == d1_1) && (d1_next == d1_1) && (d2 == d2_1) && (d2_next == d2_1) && (d3 == d3_1) && (d3_next == d3_1) && (conf_0 == conf_0_0) && (conf_0_next == conf_0_0) && (conf_1 == conf_1_0) && (conf_1_next == conf_1_0) && (conf_2 == conf_2_0) && (conf_2_next == conf_2_0) && (conf_3 == conf_3_0) && (conf_3_next == conf_3_0) && (conf_4 == conf_4_0) && (conf_4_next == conf_4_0) && (x1 == x1_1) && (x1_next == x1_1) && (x2 == x2_0) && (x2_next == x2_0) && (x3 == x3_0) && (x3_next == x3_0)));
}

static inline _Bool c_post_f(long long d1, long long d2, long long d3, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x1, long long x2, long long x3, long long d1_0, long long d1_1, long long d2_0, long long d2_1, long long d3_0, long long d3_1, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long x1_0, long long x1_1, long long x1_2, long long x1_3, long long x1_4, long long x2_0, long long x2_1, long long x2_2, long long x2_3, long long x3_0, long long x3_1, long long x3_2, long long x3_3) {
    return ((!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && (x2_1 > 0) && (x3_1 > 0) && (x1_3 == (x1_2 - d1_1)) && (conf_1_2 == (conf_4_1 + 828)) && (x2_2 == (x2_1 - d2_1)) && (conf_4_2 == (conf_4_1 + 435)) && (x3_2 == (x3_1 - d3_1)) && (conf_3_2 == (conf_2_0 - 854)) && (conf_1_3 == conf_1_2) && (conf_3_3 == conf_3_2) && (conf_4_3 == conf_4_2) && (x1_4 == x1_3) && (x2_3 == x2_2) && (x3_3 == x3_2) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))) && (!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && (x2_1 > 0) && !((x3_1 > 0)) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_3 == conf_4_1) && (x1_4 == x1_2) && (x2_3 == x2_1) && (x3_3 == x3_1) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))) && (!(((d1 == d1_1) && (d2 == d2_1) && (d3 == d3_1) && (conf_0 == conf_0_0) && (conf_1 == conf_1_1) && (conf_2 == conf_2_0) && (conf_3 == conf_3_1) && (conf_4 == conf_4_1) && (x1 == x1_2) && (x2 == x2_1) && (x3 == x3_1))) || !((!((x1_2 > 0)) && !((x2_1 > 0)) && (conf_1_3 == conf_1_1) && (conf_3_3 == conf_3_1) && (conf_4_3 == conf_4_1) && (x1_4 == x1_2) && (x2_3 == x2_1) && (x3_3 == x3_1) && (conf_1_1 == conf_1_3) && (conf_3_1 == conf_3_3) && (conf_4_1 == conf_4_3) && (x1_2 == x1_4) && (x2_1 == x2_3) && (x3_1 == x3_3) && !((x1_2 > 0)) && !((x2_1 >= 0))))));
}

static inline _Bool c_inv_f(long long d1, long long d2, long long d3, long long conf_0, long long conf_1, long long conf_2, long long conf_3, long long conf_4, long long x1, long long x2, long long x3, long long d1_0, long long d1_1, long long d2_0, long long d2_1, long long d3_0, long long d3_1, long long conf_0_0, long long conf_1_0, long long conf_1_1, long long conf_1_2, long long conf_1_3, long long conf_2_0, long long conf_3_0, long long conf_3_1, long long conf_3_2, long long conf_3_3, long long conf_4_0, long long conf_4_1, long long conf_4_2, long long conf_4_3, long long x1_0, long long x1_1, long long x1_2, long long x1_3, long long x1_4, long long x2_0, long long x2_1, long long x2_2, long long x2_3, long long x3_0, long long x3_1, long long x3_2, long long x3_3) {
    return (1 == x1);
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long d1 = nondet_long();
    long long d2 = nondet_long();
    long long d3 = nondet_long();
    long long conf_0 = nondet_long();
    long long conf_1 = nondet_long();
    long long conf_2 = nondet_long();
    long long conf_3 = nondet_long();
    long long conf_4 = nondet_long();
    long long x1 = nondet_long();
    long long x2 = nondet_long();
    long long x3 = nondet_long();
    long long d1_0 = nondet_long();
    long long d1_1 = nondet_long();
    long long d2_0 = nondet_long();
    long long d2_1 = nondet_long();
    long long d3_0 = nondet_long();
    long long d3_1 = nondet_long();
    long long conf_0_0 = nondet_long();
    long long conf_1_0 = nondet_long();
    long long conf_1_1 = nondet_long();
    long long conf_1_2 = nondet_long();
    long long conf_1_3 = nondet_long();
    long long conf_2_0 = nondet_long();
    long long conf_3_0 = nondet_long();
    long long conf_3_1 = nondet_long();
    long long conf_3_2 = nondet_long();
    long long conf_3_3 = nondet_long();
    long long conf_4_0 = nondet_long();
    long long conf_4_1 = nondet_long();
    long long conf_4_2 = nondet_long();
    long long conf_4_3 = nondet_long();
    long long x1_0 = nondet_long();
    long long x1_1 = nondet_long();
    long long x1_2 = nondet_long();
    long long x1_3 = nondet_long();
    long long x1_4 = nondet_long();
    long long x2_0 = nondet_long();
    long long x2_1 = nondet_long();
    long long x2_2 = nondet_long();
    long long x2_3 = nondet_long();
    long long x3_0 = nondet_long();
    long long x3_1 = nondet_long();
    long long x3_2 = nondet_long();
    long long x3_3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3);
      @ loop assigns d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3;
      @*/
    while (1) {
        long long d1_next = nondet_long();
        long long d2_next = nondet_long();
        long long d3_next = nondet_long();
        long long conf_0_next = nondet_long();
        long long conf_1_next = nondet_long();
        long long conf_2_next = nondet_long();
        long long conf_3_next = nondet_long();
        long long conf_4_next = nondet_long();
        long long x1_next = nondet_long();
        long long x2_next = nondet_long();
        long long x3_next = nondet_long();
        long long d1_0_next = nondet_long();
        long long d1_1_next = nondet_long();
        long long d2_0_next = nondet_long();
        long long d2_1_next = nondet_long();
        long long d3_0_next = nondet_long();
        long long d3_1_next = nondet_long();
        long long conf_0_0_next = nondet_long();
        long long conf_1_0_next = nondet_long();
        long long conf_1_1_next = nondet_long();
        long long conf_1_2_next = nondet_long();
        long long conf_1_3_next = nondet_long();
        long long conf_2_0_next = nondet_long();
        long long conf_3_0_next = nondet_long();
        long long conf_3_1_next = nondet_long();
        long long conf_3_2_next = nondet_long();
        long long conf_3_3_next = nondet_long();
        long long conf_4_0_next = nondet_long();
        long long conf_4_1_next = nondet_long();
        long long conf_4_2_next = nondet_long();
        long long conf_4_3_next = nondet_long();
        long long x1_0_next = nondet_long();
        long long x1_1_next = nondet_long();
        long long x1_2_next = nondet_long();
        long long x1_3_next = nondet_long();
        long long x1_4_next = nondet_long();
        long long x2_0_next = nondet_long();
        long long x2_1_next = nondet_long();
        long long x2_2_next = nondet_long();
        long long x2_3_next = nondet_long();
        long long x3_0_next = nondet_long();
        long long x3_1_next = nondet_long();
        long long x3_2_next = nondet_long();
        long long x3_3_next = nondet_long();

        if (!c_trans_f(d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3, d1_next, d2_next, d3_next, conf_0_next, conf_1_next, conf_2_next, conf_3_next, conf_4_next, x1_next, x2_next, x3_next, d1_0_next, d1_1_next, d2_0_next, d2_1_next, d3_0_next, d3_1_next, conf_0_0_next, conf_1_0_next, conf_1_1_next, conf_1_2_next, conf_1_3_next, conf_2_0_next, conf_3_0_next, conf_3_1_next, conf_3_2_next, conf_3_3_next, conf_4_0_next, conf_4_1_next, conf_4_2_next, conf_4_3_next, x1_0_next, x1_1_next, x1_2_next, x1_3_next, x1_4_next, x2_0_next, x2_1_next, x2_2_next, x2_3_next, x3_0_next, x3_1_next, x3_2_next, x3_3_next)) break;

        // State updates
        d1 = d1_next;
        d2 = d2_next;
        d3 = d3_next;
        conf_0 = conf_0_next;
        conf_1 = conf_1_next;
        conf_2 = conf_2_next;
        conf_3 = conf_3_next;
        conf_4 = conf_4_next;
        x1 = x1_next;
        x2 = x2_next;
        x3 = x3_next;
        d1_0 = d1_0_next;
        d1_1 = d1_1_next;
        d2_0 = d2_0_next;
        d2_1 = d2_1_next;
        d3_0 = d3_0_next;
        d3_1 = d3_1_next;
        conf_0_0 = conf_0_0_next;
        conf_1_0 = conf_1_0_next;
        conf_1_1 = conf_1_1_next;
        conf_1_2 = conf_1_2_next;
        conf_1_3 = conf_1_3_next;
        conf_2_0 = conf_2_0_next;
        conf_3_0 = conf_3_0_next;
        conf_3_1 = conf_3_1_next;
        conf_3_2 = conf_3_2_next;
        conf_3_3 = conf_3_3_next;
        conf_4_0 = conf_4_0_next;
        conf_4_1 = conf_4_1_next;
        conf_4_2 = conf_4_2_next;
        conf_4_3 = conf_4_3_next;
        x1_0 = x1_0_next;
        x1_1 = x1_1_next;
        x1_2 = x1_2_next;
        x1_3 = x1_3_next;
        x1_4 = x1_4_next;
        x2_0 = x2_0_next;
        x2_1 = x2_1_next;
        x2_2 = x2_2_next;
        x2_3 = x2_3_next;
        x3_0 = x3_0_next;
        x3_1 = x3_1_next;
        x3_2 = x3_2_next;
        x3_3 = x3_3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3));
    /*@ assert post_f(d1, d2, d3, conf_0, conf_1, conf_2, conf_3, conf_4, x1, x2, x3, d1_0, d1_1, d2_0, d2_1, d3_0, d3_1, conf_0_0, conf_1_0, conf_1_1, conf_1_2, conf_1_3, conf_2_0, conf_3_0, conf_3_1, conf_3_2, conf_3_3, conf_4_0, conf_4_1, conf_4_2, conf_4_3, x1_0, x1_1, x1_2, x1_3, x1_4, x2_0, x2_1, x2_2, x2_3, x3_0, x3_1, x3_2, x3_3); */

    return 0;
}
