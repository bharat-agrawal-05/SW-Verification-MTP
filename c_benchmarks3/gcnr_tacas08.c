/*
 * Generated C verification file from: gcnr_tacas08.sl
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
  predicate pre_fun(integer w, integer x, integer y, integer z) =
    ((w == 0) && (x == 0) && (y == 0) && (z == 0));

  predicate trans_fun(integer w, integer x, integer y, integer z, integer w_next, integer x_next, integer y_next, integer z_next) =
    ((((x_next == (x + 1)) && (y_next == (y + 100))) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 1))) || ((y > (10 * w)) && (z >= (100 * x)) && (y_next == (0 - y)) && (x_next == x))) && (w_next == (w + 1)) && (z_next == (z + 10)));

  predicate post_fun(integer w, integer x, integer y, integer z) =
    !(((x >= 4) && (y <= 2)));

  predicate inv_fun(integer w, integer x, integer y, integer z) =
    ((w >= 0) && (x >= 0) && (y >= 0) && (z >= 0) && (z <= (10 * x)) && (y <= ((100 * x) + (10 * w))) && ((x < 4) || (y > 2)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long w, long long x, long long y, long long z) {
    return ((w == 0) && (x == 0) && (y == 0) && (z == 0));
}

static inline _Bool c_trans_fun(long long w, long long x, long long y, long long z, long long w_next, long long x_next, long long y_next, long long z_next) {
    return ((((x_next == (x + 1)) && (y_next == (y + 100))) || ((x >= 4) && (x_next == (x + 1)) && (y_next == (y + 1))) || ((y > (10 * w)) && (z >= (100 * x)) && (y_next == (0 - y)) && (x_next == x))) && (w_next == (w + 1)) && (z_next == (z + 10)));
}

static inline _Bool c_post_fun(long long w, long long x, long long y, long long z) {
    return !(((x >= 4) && (y <= 2)));
}

static inline _Bool c_inv_fun(long long w, long long x, long long y, long long z) {
    return ((w >= 0) && (x >= 0) && (y >= 0) && (z >= 0) && (z <= (10 * x)) && (y <= ((100 * x) + (10 * w))) && ((x < 4) || (y > 2)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long w = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(w, x, y, z)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(w, x, y, z);
      @ loop assigns w, x, y, z;
      @*/
    while (1) {
        long long w_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();

        if (!c_trans_fun(w, x, y, z, w_next, x_next, y_next, z_next)) break;

        // State updates
        w = w_next;
        x = x_next;
        y = y_next;
        z = z_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(w, x, y, z));
    /*@ assert post_fun(w, x, y, z); */

    return 0;
}
