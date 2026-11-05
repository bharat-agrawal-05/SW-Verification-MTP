/*
 * Generated C verification file from: array-copyall.sl
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
  predicate pre_fun(integer a1[], integer a2[], integer n, integer i) =
    ((n >= 0) && (i == 0));

  predicate trans_fun(integer a1[], integer a2[], integer n, integer i, integer a1_next[], integer a2_next[], integer n_next, integer i_next) =
    ((i <= n) && (i_next == (i + 1)) && ((n_next == n) && ((a2_next == a2) && ((a1_next[i] == a2[i]) && (\forall integer _k; !((_k == i)) ==> (a1_next[_k] == a1[_k]))))));

  predicate post_fun(integer a1[], integer a2[], integer n, integer i) =
    ((i <= n) || (\forall integer j; (((0 <= j) && (j <= n)) ==> (a1[j] == a2[j]))));

  predicate inv_fun(integer a1[], integer a2[], integer n, integer i) =
    (\forall integer j; (((j >= 0) && (j < i)) ==> (a1[j] == a2[j])));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long a1[], const long long a2[], long long n, long long i) {
    return ((n >= 0) && (i == 0));
}

static inline _Bool c_trans_fun(const long long a1[], const long long a2[], long long n, long long i, const long long a1_next[], const long long a2_next[], long long n_next, long long i_next) {
    return ((i <= n) && (i_next == (i + 1)) && ((n_next == n) && ((a2_next == a2) && ((a1_next[i] == a2[i])))));
}

// c_post_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
// c_inv_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a1[100];
    for (int _i = 0; _i < 100; ++_i) { a1[_i] = nondet_long(); }
    long long a2[100];
    for (int _i = 0; _i < 100; ++_i) { a2[_i] = nondet_long(); }
    long long n = nondet_long();
    long long i = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(a1, a2, n, i)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a1, a2, n, i);
      @ loop assigns a1[0..99], a2[0..99], n, i;
      @*/
    while (1) {
        long long a1_next[100];
        for (int _i = 0; _i < 100; ++_i) { a1_next[_i] = nondet_long(); }
        long long a2_next[100];
        for (int _i = 0; _i < 100; ++_i) { a2_next[_i] = nondet_long(); }
        long long n_next = nondet_long();
        long long i_next = nondet_long();

        if (!c_trans_fun(a1, a2, n, i, a1_next, a2_next, n_next, i_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { a1[_i] = a1_next[_i]; }
        for (int _i = 0; _i < 100; ++_i) { a2[_i] = a2_next[_i]; }
        n = n_next;
        i = i_next;
    }

    // 4. Post-condition assertion
    /*@ assert post_fun(a1, a2, n, i); */

    return 0;
}
