/*
 * Generated C verification file from: 132.c.sl
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
  predicate pre_f(integer c, integer i, integer j, integer t, integer tmp, integer c_0, integer i_0, integer i_1, integer i_2, integer i_3, integer j_0, integer j_1, integer j_2, integer j_3, integer t_0, integer t_1, integer t_2, integer t_3) =
    ((i == i_0) && (i_0 == 0));

  predicate trans_f(integer c, integer i, integer j, integer t, integer tmp, integer c_0, integer i_0, integer i_1, integer i_2, integer i_3, integer j_0, integer j_1, integer j_2, integer j_3, integer t_0, integer t_1, integer t_2, integer t_3, integer c_next, integer i_next, integer j_next, integer t_next, integer tmp_next, integer c_0_next, integer i_0_next, integer i_1_next, integer i_2_next, integer i_3_next, integer j_0_next, integer j_1_next, integer j_2_next, integer j_3_next, integer t_0_next, integer t_1_next, integer t_2_next, integer t_3_next) =
    (((i_1 == i) && (j_1 == j) && (t_1 == t) && (i_1 == i_next) && (j_1 == j_next) && (t_1 == t_next) && (c == c_next) && (i == i_next) && (j == j_next) && (t == t_next) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && (c_0 > 48) && (c_0 < 57) && (j_2 == (i_1 + i_1)) && (t_2 == (c_0 - 48)) && (i_2 == (j_2 + t_2)) && (i_3 == i_2) && (j_3 == j_2) && (t_3 == t_2) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && (c_0 > 48) && !((c_0 < 57)) && (i_3 == i_1) && (j_3 == j_1) && (t_3 == t_1) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && !((c_0 > 48)) && (i_3 == i_1) && (j_3 == j_1) && (t_3 == t_1) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)));

  predicate post_f(integer c, integer i, integer j, integer t, integer tmp, integer c_0, integer i_0, integer i_1, integer i_2, integer i_3, integer j_0, integer j_1, integer j_2, integer j_3, integer t_0, integer t_1, integer t_2, integer t_3) =
    (!(((c == c_0) && (i == i_1) && (j == j_1) && (t == t_1))) || !((!((i_1 >= 0)))));

  predicate inv_f(integer c, integer i, integer j, integer t, integer tmp, integer c_0, integer i_0, integer i_1, integer i_2, integer i_3, integer j_0, integer j_1, integer j_2, integer j_3, integer t_0, integer t_1, integer t_2, integer t_3) =
    ((i >= 0) && (!(((c == c_0) && (i == i_1) && (j == j_1) && (t == t_1))) || !((!((i_1 >= 0))))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long c, long long i, long long j, long long t, long long tmp, long long c_0, long long i_0, long long i_1, long long i_2, long long i_3, long long j_0, long long j_1, long long j_2, long long j_3, long long t_0, long long t_1, long long t_2, long long t_3) {
    return ((i == i_0) && (i_0 == 0));
}

static inline _Bool c_trans_f(long long c, long long i, long long j, long long t, long long tmp, long long c_0, long long i_0, long long i_1, long long i_2, long long i_3, long long j_0, long long j_1, long long j_2, long long j_3, long long t_0, long long t_1, long long t_2, long long t_3, long long c_next, long long i_next, long long j_next, long long t_next, long long tmp_next, long long c_0_next, long long i_0_next, long long i_1_next, long long i_2_next, long long i_3_next, long long j_0_next, long long j_1_next, long long j_2_next, long long j_3_next, long long t_0_next, long long t_1_next, long long t_2_next, long long t_3_next) {
    return (((i_1 == i) && (j_1 == j) && (t_1 == t) && (i_1 == i_next) && (j_1 == j_next) && (t_1 == t_next) && (c == c_next) && (i == i_next) && (j == j_next) && (t == t_next) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && (c_0 > 48) && (c_0 < 57) && (j_2 == (i_1 + i_1)) && (t_2 == (c_0 - 48)) && (i_2 == (j_2 + t_2)) && (i_3 == i_2) && (j_3 == j_2) && (t_3 == t_2) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && (c_0 > 48) && !((c_0 < 57)) && (i_3 == i_1) && (j_3 == j_1) && (t_3 == t_1) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)) || ((i_1 == i) && (j_1 == j) && (t_1 == t) && !((c_0 > 48)) && (i_3 == i_1) && (j_3 == j_1) && (t_3 == t_1) && (i_3 == i_next) && (j_3 == j_next) && (t_3 == t_next) && (c == c_0) && (c_next == c_0) && (tmp == tmp_next)));
}

static inline _Bool c_post_f(long long c, long long i, long long j, long long t, long long tmp, long long c_0, long long i_0, long long i_1, long long i_2, long long i_3, long long j_0, long long j_1, long long j_2, long long j_3, long long t_0, long long t_1, long long t_2, long long t_3) {
    return (!(((c == c_0) && (i == i_1) && (j == j_1) && (t == t_1))) || !((!((i_1 >= 0)))));
}

static inline _Bool c_inv_f(long long c, long long i, long long j, long long t, long long tmp, long long c_0, long long i_0, long long i_1, long long i_2, long long i_3, long long j_0, long long j_1, long long j_2, long long j_3, long long t_0, long long t_1, long long t_2, long long t_3) {
    return ((i >= 0) && (!(((c == c_0) && (i == i_1) && (j == j_1) && (t == t_1))) || !((!((i_1 >= 0))))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long i = nondet_long();
    long long j = nondet_long();
    long long t = nondet_long();
    long long tmp = nondet_long();
    long long c_0 = nondet_long();
    long long i_0 = nondet_long();
    long long i_1 = nondet_long();
    long long i_2 = nondet_long();
    long long i_3 = nondet_long();
    long long j_0 = nondet_long();
    long long j_1 = nondet_long();
    long long j_2 = nondet_long();
    long long j_3 = nondet_long();
    long long t_0 = nondet_long();
    long long t_1 = nondet_long();
    long long t_2 = nondet_long();
    long long t_3 = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3);
      @ loop assigns c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long t_next = nondet_long();
        long long tmp_next = nondet_long();
        long long c_0_next = nondet_long();
        long long i_0_next = nondet_long();
        long long i_1_next = nondet_long();
        long long i_2_next = nondet_long();
        long long i_3_next = nondet_long();
        long long j_0_next = nondet_long();
        long long j_1_next = nondet_long();
        long long j_2_next = nondet_long();
        long long j_3_next = nondet_long();
        long long t_0_next = nondet_long();
        long long t_1_next = nondet_long();
        long long t_2_next = nondet_long();
        long long t_3_next = nondet_long();

        if (!c_trans_f(c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3, c_next, i_next, j_next, t_next, tmp_next, c_0_next, i_0_next, i_1_next, i_2_next, i_3_next, j_0_next, j_1_next, j_2_next, j_3_next, t_0_next, t_1_next, t_2_next, t_3_next)) break;

        // State updates
        c = c_next;
        i = i_next;
        j = j_next;
        t = t_next;
        tmp = tmp_next;
        c_0 = c_0_next;
        i_0 = i_0_next;
        i_1 = i_1_next;
        i_2 = i_2_next;
        i_3 = i_3_next;
        j_0 = j_0_next;
        j_1 = j_1_next;
        j_2 = j_2_next;
        j_3 = j_3_next;
        t_0 = t_0_next;
        t_1 = t_1_next;
        t_2 = t_2_next;
        t_3 = t_3_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3));
    /*@ assert post_f(c, i, j, t, tmp, c_0, i_0, i_1, i_2, i_3, j_0, j_1, j_2, j_3, t_0, t_1, t_2, t_3); */

    return 0;
}
