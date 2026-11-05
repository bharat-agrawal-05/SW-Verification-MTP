/*
 * Generated C verification file from: fib_18.sl
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
  predicate pre_fun(integer b, integer j, integer n, integer flag) =
    ((j == 0) && (n > 0) && (b == 0));

  predicate trans_fun(integer b, integer j, integer n, integer flag, integer b_next, integer j_next, integer n_next, integer flag_next) =
    (((b < n) && (flag == 1) && (j_next == (j + 1)) && (b_next == (b + 1)) && (n_next == n) && (flag_next == flag)) || ((b < n) && !((flag == 1)) && (j_next == j) && (b_next == (b + 1)) && (n_next == n) && (flag_next == flag)) || ((b >= n) && (j_next == j) && (b_next == b) && (n_next == n) && (flag_next == flag)));

  predicate post_fun(integer b, integer j, integer n, integer flag) =
    (!((b < n)) ==> (!((flag == 1)) || (j == n)));

  predicate inv_fun(integer b, integer j, integer n, integer flag) =
    ((b >= 0) && (b <= n) && (((flag == 1) && (j == b)) || (!((flag == 1)) && (j == 0))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long b, long long j, long long n, long long flag) {
    return ((j == 0) && (n > 0) && (b == 0));
}

static inline _Bool c_trans_fun(long long b, long long j, long long n, long long flag, long long b_next, long long j_next, long long n_next, long long flag_next) {
    return (((b < n) && (flag == 1) && (j_next == (j + 1)) && (b_next == (b + 1)) && (n_next == n) && (flag_next == flag)) || ((b < n) && !((flag == 1)) && (j_next == j) && (b_next == (b + 1)) && (n_next == n) && (flag_next == flag)) || ((b >= n) && (j_next == j) && (b_next == b) && (n_next == n) && (flag_next == flag)));
}

static inline _Bool c_post_fun(long long b, long long j, long long n, long long flag) {
    return (!(!((b < n))) || (!((flag == 1)) || (j == n)));
}

static inline _Bool c_inv_fun(long long b, long long j, long long n, long long flag) {
    return ((b >= 0) && (b <= n) && (((flag == 1) && (j == b)) || (!((flag == 1)) && (j == 0))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long b = nondet_long();
    long long j = nondet_long();
    long long n = nondet_long();
    long long flag = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(b, j, n, flag)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(b, j, n, flag);
      @ loop assigns b, j, n, flag;
      @*/
    while (1) {
        long long b_next = nondet_long();
        long long j_next = nondet_long();
        long long n_next = nondet_long();
        long long flag_next = nondet_long();

        if (!c_trans_fun(b, j, n, flag, b_next, j_next, n_next, flag_next)) break;

        // State updates
        b = b_next;
        j = j_next;
        n = n_next;
        flag = flag_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(b, j, n, flag));
    /*@ assert post_fun(b, j, n, flag); */

    return 0;
}
