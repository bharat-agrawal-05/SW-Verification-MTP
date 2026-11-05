/*
 * Generated C verification file from: hola.41-fixed.sl
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
  predicate pre_fun(integer i, integer j, integer k, integer n) =
    (((k == 1) || (k >= 0)) && ((n >= 0) && ((i == 0) && (j == 0))));

  predicate trans_fun(integer i, integer j, integer k, integer n, integer i_next, integer j_next, integer k_next, integer n_next) =
    ((i <= n) && ((n_next == n) && ((k_next == k) && ((i_next == (i + 1)) && (j_next == (j + i_next))))));

  predicate post_fun(integer i, integer j, integer k, integer n) =
    ((i <= n) || ((i + (j + k)) > (2 * n)));

  predicate inv_fun(integer i, integer j, integer k, integer n) =
    (((i <= n) || !(((i + j + k) <= (2 * n)))) && ((0 == j) || (1 == j) || (j >= 2)) && ((0 == k) || (1 == k) || (k >= 2)) && (i >= 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long i, long long j, long long k, long long n) {
    return (((k == 1) || (k >= 0)) && ((n >= 0) && ((i == 0) && (j == 0))));
}

static inline _Bool c_trans_fun(long long i, long long j, long long k, long long n, long long i_next, long long j_next, long long k_next, long long n_next) {
    return ((i <= n) && ((n_next == n) && ((k_next == k) && ((i_next == (i + 1)) && (j_next == (j + i_next))))));
}

static inline _Bool c_post_fun(long long i, long long j, long long k, long long n) {
    return ((i <= n) || ((i + (j + k)) > (2 * n)));
}

static inline _Bool c_inv_fun(long long i, long long j, long long k, long long n) {
    return (((i <= n) || !(((i + j + k) <= (2 * n)))) && ((0 == j) || (1 == j) || (j >= 2)) && ((0 == k) || (1 == k) || (k >= 2)) && (i >= 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long j = nondet_long();
    long long k = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(i, j, k, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, j, k, n);
      @ loop assigns i, j, k, n;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long j_next = nondet_long();
        long long k_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_trans_fun(i, j, k, n, i_next, j_next, k_next, n_next)) break;

        // State updates
        i = i_next;
        j = j_next;
        k = k_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(i, j, k, n));
    /*@ assert post_fun(i, j, k, n); */

    return 0;
}
