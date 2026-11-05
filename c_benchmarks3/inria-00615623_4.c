/*
 * Generated C verification file from: inria-00615623_4.sl
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
  predicate pre_fun(integer i, integer b, integer n) =
    ((i == 0) && (i < n));

  predicate trans_fun(integer i, integer b, integer n, integer i_next, integer b_next, integer n_next) =
    ((i < n) && (n_next == n) && (((b_next == 0) && (i_next == i)) || (!((b_next == 0)) && (i_next == (i + 1)))));

  predicate post_fun(integer i, integer b, integer n) =
    ((i < n) || ((i == n) && !((b == 0))));

  predicate inv_fun(integer i, integer b, integer n) =
    (((0 <= i) && (i <= n)) && ((b == 0) ==> (i < n)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long i, long long b, long long n) {
    return ((i == 0) && (i < n));
}

static inline _Bool c_trans_fun(long long i, long long b, long long n, long long i_next, long long b_next, long long n_next) {
    return ((i < n) && (n_next == n) && (((b_next == 0) && (i_next == i)) || (!((b_next == 0)) && (i_next == (i + 1)))));
}

static inline _Bool c_post_fun(long long i, long long b, long long n) {
    return ((i < n) || ((i == n) && !((b == 0))));
}

static inline _Bool c_inv_fun(long long i, long long b, long long n) {
    return (((0 <= i) && (i <= n)) && (!((b == 0)) || (i < n)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long b = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(i, b, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(i, b, n);
      @ loop assigns i, b, n;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long b_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_trans_fun(i, b, n, i_next, b_next, n_next)) break;

        // State updates
        i = i_next;
        b = b_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(i, b, n));
    /*@ assert post_fun(i, b, n); */

    return 0;
}
