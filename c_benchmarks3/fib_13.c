/*
 * Generated C verification file from: fib_13.sl
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
  predicate pre_fun(integer j, integer k, integer t) =
    ((j == 2) && (k == 0));

  predicate trans_fun(integer j, integer k, integer t, integer j_next, integer k_next, integer t_next) =
    (((t == 0) && (j_next == (j + 4)) && (k_next == k) && (t_next == t)) || (!((t == 0)) && (j_next == (j + 2)) && (k_next == (k + 1)) && (t_next == t)));

  predicate post_fun(integer j, integer k, integer t) =
    ((k == 0) || (j == ((k * 2) + 2)));

  predicate inv_fun(integer j, integer k, integer t) =
    (((k == 0) || (j == (2 + (2 * k)))) && (!(((0 == k) || (0 == t))) || (2 == j) || (k == t)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long j, long long k, long long t) {
    return ((j == 2) && (k == 0));
}

static inline _Bool c_trans_fun(long long j, long long k, long long t, long long j_next, long long k_next, long long t_next) {
    return (((t == 0) && (j_next == (j + 4)) && (k_next == k) && (t_next == t)) || (!((t == 0)) && (j_next == (j + 2)) && (k_next == (k + 1)) && (t_next == t)));
}

static inline _Bool c_post_fun(long long j, long long k, long long t) {
    return ((k == 0) || (j == ((k * 2) + 2)));
}

static inline _Bool c_inv_fun(long long j, long long k, long long t) {
    return (((k == 0) || (j == (2 + (2 * k)))) && (!(((0 == k) || (0 == t))) || (2 == j) || (k == t)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long j = nondet_long();
    long long k = nondet_long();
    long long t = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(j, k, t)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(j, k, t);
      @ loop assigns j, k, t;
      @*/
    while (1) {
        long long j_next = nondet_long();
        long long k_next = nondet_long();
        long long t_next = nondet_long();

        if (!c_trans_fun(j, k, t, j_next, k_next, t_next)) break;

        // State updates
        j = j_next;
        k = k_next;
        t = t_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(j, k, t));
    /*@ assert post_fun(j, k, t); */

    return 0;
}
