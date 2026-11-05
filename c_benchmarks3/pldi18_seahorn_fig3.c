/*
 * Generated C verification file from: pldi18_seahorn_fig3.sl
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
  predicate pre_fun(integer x, integer y, boolean failed) =
    ((x == 0) && (failed == \false));

  predicate trans_fun(integer x, integer y, boolean failed, integer x_next, integer y_next, boolean failed_next) =
    (!((y == 0)) && (((y < 0) && (x_next == (x - 1)) && (y_next == (y + 1))) || ((y >= 0) && (x_next == (x + 1)) && (y_next == (y - 1)))) && (((x_next == 0) && (failed_next == \true)) || (!((x_next == 0)) && (failed_next == failed))));

  predicate post_fun(integer x, integer y, boolean failed) =
    (!((y == 0)) || (failed == \false));

  predicate inv_fun(integer x, integer y, boolean failed) =
    (!(failed) && (!(((x + y) == 0)) || (0 == y)) && (((x >= 0) && (y >= 0)) || ((1 >= y) && (0 >= x))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, _Bool failed) {
    return ((x == 0) && (failed == false));
}

static inline _Bool c_trans_fun(long long x, long long y, _Bool failed, long long x_next, long long y_next, _Bool failed_next) {
    return (!((y == 0)) && (((y < 0) && (x_next == (x - 1)) && (y_next == (y + 1))) || ((y >= 0) && (x_next == (x + 1)) && (y_next == (y - 1)))) && (((x_next == 0) && (failed_next == true)) || (!((x_next == 0)) && (failed_next == failed))));
}

static inline _Bool c_post_fun(long long x, long long y, _Bool failed) {
    return (!((y == 0)) || (failed == false));
}

static inline _Bool c_inv_fun(long long x, long long y, _Bool failed) {
    return (!(failed) && (!(((x + y) == 0)) || (0 == y)) && (((x >= 0) && (y >= 0)) || ((1 >= y) && (0 >= x))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    _Bool failed = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, failed)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, failed);
      @ loop assigns x, y, failed;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        _Bool failed_next = nondet_bool();

        if (!c_trans_fun(x, y, failed, x_next, y_next, failed_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        failed = failed_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, failed));
    /*@ assert post_fun(x, y, failed); */

    return 0;
}
