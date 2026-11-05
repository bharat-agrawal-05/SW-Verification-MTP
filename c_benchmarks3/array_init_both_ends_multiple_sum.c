/*
 * Generated C verification file from: array_init_both_ends_multiple_sum.sl
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
  predicate pre_fun(integer a[], integer b[], integer n, integer i, integer i1, integer sum) =
    ((n >= 0) && (i == 0) && (sum == 0) && (i1 == 0));

  predicate trans_fun(integer a[], integer b[], integer n, integer i, integer i1, integer sum, integer a_next[], integer b_next[], integer n_next, integer i_next, integer i1_next, integer sum_next) =
    ((i1 < (2 * n)) && (i1_next == (i1_next + 1)) && (n_next == n) && (((i1 < n)) ? (((i < n) && (i_next == (i + 1)) && ((a_next[i] == i) && (\forall integer _k; !((_k == i)) ==> (a_next[_k] == a[_k]))) && ((b_next[(n + (-(i)) + -1)] == i) && (\forall integer _k; !((_k == (n + (-(i)) + -1))) ==> (b_next[_k] == b[_k]))))) : ((sum_next == (sum + (a[(i1 - n)] - b[(n + (-((i1 - n))) + -1)]))))));

  predicate post_fun(integer a[], integer b[], integer n, integer i, integer i1, integer sum) =
    ((i1 < (2 * n)) || (sum == 0));

  predicate inv_fun(integer a[], integer b[], integer n, integer i, integer i1, integer sum) =
    ((i1 < (2 * n)) || (sum == 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long a[], const long long b[], long long n, long long i, long long i1, long long sum) {
    return ((n >= 0) && (i == 0) && (sum == 0) && (i1 == 0));
}

static inline _Bool c_trans_fun(const long long a[], const long long b[], long long n, long long i, long long i1, long long sum, const long long a_next[], const long long b_next[], long long n_next, long long i_next, long long i1_next, long long sum_next) {
    return ((i1 < (2 * n)) && (i1_next == (i1_next + 1)) && (n_next == n) && (((i1 < n)) ? (((i < n) && (i_next == (i + 1)) && ((a_next[i] == i)) && ((b_next[(n + (-(i)) + -1)] == i)))) : ((sum_next == (sum + (a[(i1 - n)] - b[(n + (-((i1 - n))) + -1)]))))));
}

static inline _Bool c_post_fun(const long long a[], const long long b[], long long n, long long i, long long i1, long long sum) {
    return ((i1 < (2 * n)) || (sum == 0));
}

static inline _Bool c_inv_fun(const long long a[], const long long b[], long long n, long long i, long long i1, long long sum) {
    return ((i1 < (2 * n)) || (sum == 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a[100];
    for (int _i = 0; _i < 100; ++_i) { a[_i] = nondet_long(); }
    long long b[100];
    for (int _i = 0; _i < 100; ++_i) { b[_i] = nondet_long(); }
    long long n = nondet_long();
    long long i = nondet_long();
    long long i1 = nondet_long();
    long long sum = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(a, b, n, i, i1, sum)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a, b, n, i, i1, sum);
      @ loop assigns a[0..99], b[0..99], n, i, i1, sum;
      @*/
    while (1) {
        long long a_next[100];
        for (int _i = 0; _i < 100; ++_i) { a_next[_i] = nondet_long(); }
        long long b_next[100];
        for (int _i = 0; _i < 100; ++_i) { b_next[_i] = nondet_long(); }
        long long n_next = nondet_long();
        long long i_next = nondet_long();
        long long i1_next = nondet_long();
        long long sum_next = nondet_long();

        if (!c_trans_fun(a, b, n, i, i1, sum, a_next, b_next, n_next, i_next, i1_next, sum_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { a[_i] = a_next[_i]; }
        for (int _i = 0; _i < 100; ++_i) { b[_i] = b_next[_i]; }
        n = n_next;
        i = i_next;
        i1 = i1_next;
        sum = sum_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(a, b, n, i, i1, sum));
    /*@ assert post_fun(a, b, n, i, i1, sum); */

    return 0;
}
