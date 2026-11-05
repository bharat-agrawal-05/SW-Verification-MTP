/*
 * Generated C verification file from: array_tripl_access_init_const.sl
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
  predicate pre_fun(integer a[], integer n, integer i) =
    ((n >= 0) && (i == 0));

  predicate trans_fun(integer a[], integer n, integer i, integer a_next[], integer n_next, integer i_next) =
    ((i <= n) && (i_next == (i + 1)) && (n_next == n) && ((a_next[(2 + (3 * i))] == 0) && (a_next[(1 + (3 * i))] == 0) && (a_next[(3 * i)] == 0) && (\forall integer _k; !((_k == (2 + (3 * i))) || (_k == (1 + (3 * i))) || (_k == (3 * i))) ==> (a_next[_k] == a[_k]))));

  predicate post_fun(integer a[], integer n, integer i) =
    ((i <= n) || (\forall integer j; (((j >= 0) && (j <= (3 * n))) ==> (0 >= a[j]))));

  predicate inv_fun(integer a[], integer n, integer i) =
    (\forall integer j; (((j >= 0) && (j <= (3 * i))) ==> (0 >= store(store(store(a, (3 * i), 0), (1 + (3 * i)), 0), (2 + (3 * i)), 0)[j])));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long a[], long long n, long long i) {
    return ((n >= 0) && (i == 0));
}

static inline _Bool c_trans_fun(const long long a[], long long n, long long i, const long long a_next[], long long n_next, long long i_next) {
    return ((i <= n) && (i_next == (i + 1)) && (n_next == n) && ((a_next[(2 + (3 * i))] == 0) && (a_next[(1 + (3 * i))] == 0) && (a_next[(3 * i)] == 0)));
}

// c_post_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
// c_inv_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a[100];
    for (int _i = 0; _i < 100; ++_i) { a[_i] = nondet_long(); }
    long long n = nondet_long();
    long long i = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(a, n, i)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a, n, i);
      @ loop assigns a[0..99], n, i;
      @*/
    while (1) {
        long long a_next[100];
        for (int _i = 0; _i < 100; ++_i) { a_next[_i] = nondet_long(); }
        long long n_next = nondet_long();
        long long i_next = nondet_long();

        if (!c_trans_fun(a, n, i, a_next, n_next, i_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { a[_i] = a_next[_i]; }
        n = n_next;
        i = i_next;
    }

    // 4. Post-condition assertion
    /*@ assert post_fun(a, n, i); */

    return 0;
}
