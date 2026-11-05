/*
 * Generated C verification file from: array_simp.sl
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
  predicate pre_fun(integer x, integer y, integer z, integer size) =
    (x == 0);

  predicate trans_fun(integer x, integer y, integer z, integer size, integer x_next, integer y_next, integer z_next, integer size_next) =
    (((x_next == (x + 1)) && ((y_next == z_next) && ((z_next <= y) && (x < size)))) || ((x_next == (x + 1)) && ((y_next == y) && ((z_next > y) && (x < size)))));

  predicate post_fun(integer x, integer y, integer z, integer size) =
    !((((x >= size) && (z < y)) && (size > 0)));

  predicate inv_fun(integer x, integer y, integer z, integer size) =
    (((z < y) && (x >= 0) && (x < size)) || !((((x >= size) && (z < y)) && (size > 0))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long y, long long z, long long size) {
    return (x == 0);
}

static inline _Bool c_trans_fun(long long x, long long y, long long z, long long size, long long x_next, long long y_next, long long z_next, long long size_next) {
    return (((x_next == (x + 1)) && ((y_next == z_next) && ((z_next <= y) && (x < size)))) || ((x_next == (x + 1)) && ((y_next == y) && ((z_next > y) && (x < size)))));
}

static inline _Bool c_post_fun(long long x, long long y, long long z, long long size) {
    return !((((x >= size) && (z < y)) && (size > 0)));
}

static inline _Bool c_inv_fun(long long x, long long y, long long z, long long size) {
    return (((z < y) && (x >= 0) && (x < size)) || !((((x >= size) && (z < y)) && (size > 0))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long y = nondet_long();
    long long z = nondet_long();
    long long size = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, y, z, size)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, y, z, size);
      @ loop assigns x, y, z, size;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long z_next = nondet_long();
        long long size_next = nondet_long();

        if (!c_trans_fun(x, y, z, size, x_next, y_next, z_next, size_next)) break;

        // State updates
        x = x_next;
        y = y_next;
        z = z_next;
        size = size_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, y, z, size));
    /*@ assert post_fun(x, y, z, size); */

    return 0;
}
