/*
 * Generated C verification file from: inc-array.sl
 * SMT-LIB Logic: ALIA
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
  predicate pre_fun(integer x[]) =
    (1 == x[0]);

  predicate trans_fun(integer x[], integer x_next[]) =
    ((x[0] < 100) && ((x_next[0] == (x[0] + 2)) && (\forall integer _k; !((_k == 0)) ==> (x_next[_k] == x[_k]))));

  predicate post_fun(integer x[]) =
    (!((x[0] >= 100)) || (x[0] == 101));

  predicate inv_fun(integer x[]) =
    ((x[0] >= 1) && (x[0] <= 101) && ((x[0] % 2) == 1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long x[]) {
    return (1 == x[0]);
}

static inline _Bool c_trans_fun(const long long x[], const long long x_next[]) {
    return ((x[0] < 100) && ((x_next[0] == (x[0] + 2))));
}

static inline _Bool c_post_fun(const long long x[]) {
    return (!((x[0] >= 100)) || (x[0] == 101));
}

static inline _Bool c_inv_fun(const long long x[]) {
    return ((x[0] >= 1) && (x[0] <= 101) && ((x[0] % 2) == 1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x[100];
    for (int _i = 0; _i < 100; ++_i) { x[_i] = nondet_long(); }

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(x)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(x);
      @ loop assigns x[0..99];
      @*/
    while (1) {
        long long x_next[100];
        for (int _i = 0; _i < 100; ++_i) { x_next[_i] = nondet_long(); }

        if (!c_trans_fun(x, x_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { x[_i] = x_next[_i]; }
    }

    // 4. Post-condition assertion
    assert(c_post_fun(x));
    /*@ assert post_fun(x); */

    return 0;
}
