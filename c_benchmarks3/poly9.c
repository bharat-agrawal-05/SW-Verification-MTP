/*
 * Generated C verification file from: poly9.sl
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
  predicate pre_fun(integer c, integer y1, integer y2, integer y1i, integer y2i) =
    ((c == 0) && (y2 >= 1) && (y1 >= 1) && (y1 == y1i) && (y2 == y2i));

  predicate trans_fun(integer c, integer y1, integer y2, integer y1i, integer y2i, integer c_next, integer y1_next, integer y2_next, integer y1i_next, integer y2i_next) =
    ((y1i_next == y1i) && (y2i_next == y2i) && (((y1 == y2) && (c_next == c) && (y1_next == y1) && (y2_next == y2)) || ((y1 >= (y2 + 1)) && (c_next == (c + 1)) && (y1_next == (y1 - y2)) && (y2_next == y2)) || ((y2 >= (y1 + 1)) && (c_next == (c + 1)) && (y2_next == (y2 - y1)) && (y1_next == y1))));

  predicate post_fun(integer c, integer y1, integer y2, integer y1i, integer y2i) =
    (!((y1 == y2)) ==> (c <= ((y1i + y2i) - 2)));

  predicate inv_fun(integer c, integer y1, integer y2, integer y1i, integer y2i) =
    ((c >= 0) && (y1 >= 1) && (y2 >= 1) && ((y1 + y2 + c) <= (y1i + y2i + 1)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long c, long long y1, long long y2, long long y1i, long long y2i) {
    return ((c == 0) && (y2 >= 1) && (y1 >= 1) && (y1 == y1i) && (y2 == y2i));
}

static inline _Bool c_trans_fun(long long c, long long y1, long long y2, long long y1i, long long y2i, long long c_next, long long y1_next, long long y2_next, long long y1i_next, long long y2i_next) {
    return ((y1i_next == y1i) && (y2i_next == y2i) && (((y1 == y2) && (c_next == c) && (y1_next == y1) && (y2_next == y2)) || ((y1 >= (y2 + 1)) && (c_next == (c + 1)) && (y1_next == (y1 - y2)) && (y2_next == y2)) || ((y2 >= (y1 + 1)) && (c_next == (c + 1)) && (y2_next == (y2 - y1)) && (y1_next == y1))));
}

static inline _Bool c_post_fun(long long c, long long y1, long long y2, long long y1i, long long y2i) {
    return (!(!((y1 == y2))) || (c <= ((y1i + y2i) - 2)));
}

static inline _Bool c_inv_fun(long long c, long long y1, long long y2, long long y1i, long long y2i) {
    return ((c >= 0) && (y1 >= 1) && (y2 >= 1) && ((y1 + y2 + c) <= (y1i + y2i + 1)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long c = nondet_long();
    long long y1 = nondet_long();
    long long y2 = nondet_long();
    long long y1i = nondet_long();
    long long y2i = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(c, y1, y2, y1i, y2i)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(c, y1, y2, y1i, y2i);
      @ loop assigns c, y1, y2, y1i, y2i;
      @*/
    while (1) {
        long long c_next = nondet_long();
        long long y1_next = nondet_long();
        long long y2_next = nondet_long();
        long long y1i_next = nondet_long();
        long long y2i_next = nondet_long();

        if (!c_trans_fun(c, y1, y2, y1i, y2i, c_next, y1_next, y2_next, y1i_next, y2i_next)) break;

        // State updates
        c = c_next;
        y1 = y1_next;
        y2 = y2_next;
        y1i = y1i_next;
        y2i = y2i_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(c, y1, y2, y1i, y2i));
    /*@ assert post_fun(c, y1, y2, y1i, y2i); */

    return 0;
}
