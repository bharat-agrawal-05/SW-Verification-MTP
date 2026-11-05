/*
 * Generated C verification file from: 52.c.sl
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
  predicate pre_f(integer c, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5) =
    ((c == c_1) && (c_1 == 0));

  predicate trans_f(integer c, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5, integer c_next, integer tmp_next, integer c_0_next, integer c_1_next, integer c_2_next, integer c_3_next, integer c_4_next, integer c_5_next) =
    (((c_2 == c) && (c_2 == c_next) && (c == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !((c_2 == 4)) && (c_3 == (c_2 + 1)) && (c_4 == c_3) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !(!((c_2 == 4))) && (c_4 == c_2) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && (c_2 == 4) && (c_5 == 1) && (c_4 == c_5) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !((c_2 == 4)) && (c_4 == c_2) && (c_4 == c_next) && (tmp == tmp_next)));

  predicate post_f(integer c, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5) =
    (!((c == c_2)) || !(((c_2 < 0) && (c_2 > 4) && !((c_2 == 4)))));

  predicate inv_f(integer c, integer tmp, integer c_0, integer c_1, integer c_2, integer c_3, integer c_4, integer c_5) =
    ((c == 0) || (c == 1) || (c == 2) || (c == 3) || (c == 4));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long c, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5) {
    return ((c == c_1) && (c_1 == 0));
}

static inline _Bool c_trans_f(long long c, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5, long long c_next, long long tmp_next, long long c_0_next, long long c_1_next, long long c_2_next, long long c_3_next, long long c_4_next, long long c_5_next) {
    return (((c_2 == c) && (c_2 == c_next) && (c == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !((c_2 == 4)) && (c_3 == (c_2 + 1)) && (c_4 == c_3) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !(!((c_2 == 4))) && (c_4 == c_2) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && (c_2 == 4) && (c_5 == 1) && (c_4 == c_5) && (c_4 == c_next) && (tmp == tmp_next)) || ((c_2 == c) && !((c_2 == 4)) && (c_4 == c_2) && (c_4 == c_next) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long c, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5) {
    return (!((c == c_2)) || !(((c_2 < 0) && (c_2 > 4) && !((c_2 == 4)))));
}

static inline _Bool c_inv_f(long long c, long long tmp, long long c_0, long long c_1, long long c_2, long long c_3, long long c_4, long long c_5) {
    return ((c == 0) || (c == 1) || (c == 2) || (c == 3) || (c == 4));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long tmp = nondet_long();
    long long c_0 = nondet_long();
    long long c_1 = nondet_long();
    long long c_2 = nondet_long();
    long long c_3 = nondet_long();
    long long c_4 = nondet_long();
    long long c_5 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(c, tmp, c_0, c_1, c_2, c_3, c_4, c_5)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(c, tmp, c_0, c_1, c_2, c_3, c_4, c_5);
      @ loop assigns c, tmp, c_0, c_1, c_2, c_3, c_4, c_5;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long tmp_next = nondet_long();
        long long c_0_next = nondet_long();
        long long c_1_next = nondet_long();
        long long c_2_next = nondet_long();
        long long c_3_next = nondet_long();
        long long c_4_next = nondet_long();
        long long c_5_next = nondet_long();

        if (!c_trans_f(c, tmp, c_0, c_1, c_2, c_3, c_4, c_5, c_next, tmp_next, c_0_next, c_1_next, c_2_next, c_3_next, c_4_next, c_5_next)) break;

        // State updates
        c = c_next;
        tmp = tmp_next;
        c_0 = c_0_next;
        c_1 = c_1_next;
        c_2 = c_2_next;
        c_3 = c_3_next;
        c_4 = c_4_next;
        c_5 = c_5_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(c, tmp, c_0, c_1, c_2, c_3, c_4, c_5));
    /*@ assert post_f(c, tmp, c_0, c_1, c_2, c_3, c_4, c_5); */

    return 0;
}
