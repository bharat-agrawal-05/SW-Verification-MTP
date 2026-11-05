/*
 * Generated C verification file from: terminator_02_true-unreach-call_true-termination.sl
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
  predicate pre_fun(integer x, integer z) =
    ((x > (0 - 100)) && (x < 200) && (z > 100) && (z < 200));

  predicate trans_fun(integer x, integer z, integer x_next, integer z_next) =
    ((x < 100) && (z > 100) && (((x_next == (x + 1)) && (z_next == z)) || ((x_next == (x - 1)) && (z_next == (z - 1)))));

  predicate post_fun(integer x, integer z) =
    (((x < 100) && (z > 100)) || ((x >= 100) || (z <= 100)));

  predicate inv_fun(integer x, integer z) =
    ((x < 100) || (z >= 101));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long x, long long z) {
    return ((x > (0 - 100)) && (x < 200) && (z > 100) && (z < 200));
}

static inline _Bool c_trans_fun(long long x, long long z, long long x_next, long long z_next) {
    return ((x < 100) && (z > 100) && (((x_next == (x + 1)) && (z_next == z)) || ((x_next == (x - 1)) && (z_next == (z - 1)))));
}

static inline _Bool c_post_fun(long long x, long long z) {
    return (((x < 100) && (z > 100)) || ((x >= 100) || (z <= 100)));
}

static inline _Bool c_inv_fun(long long x, long long z) {
    return ((x < 100) || (z >= 101));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();
    long long z = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x, z)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x, z);
      @ loop assigns x, z;
      @*/
    while (1) {
        long long x_next = nondet_long();
        long long z_next = nondet_long();

        if (!c_trans_fun(x, z, x_next, z_next)) break;

        // State updates
        x = x_next;
        z = z_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x, z));
    /*@ assert post_fun(x, z); */

    return 0;
}
