/*
 * Generated C verification file from: array_tiling_poly6.sl
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
  predicate pre_fun(integer a[], integer i, integer s) =
    ((i == 0) && (s > 1));

  predicate trans_fun(integer a[], integer i, integer s, integer a_next[], integer i_next, integer s_next) =
    ((i < (2 * s)) && (i_next == (i_next + 1)) && (s_next == s) && (((i < s)) ? (((a_next[i] == ((i - 1) * (i + 1))) && (\forall integer _k; !((_k == i)) ==> (a_next[_k] == a[_k])))) : (((a_next[(i - s)] == (a[(i - s)] - ((i - s) * (i - s)))) && (\forall integer _k; !((_k == (i - s))) ==> (a_next[_k] == a[_k]))))));

  predicate post_fun(integer a[], integer i, integer s) =
    ((i < (2 * s)) || (\forall integer j; (((j >= 0) && (j < s)) ==> (-1 == a[j]))));

  predicate inv_fun(integer a[], integer i, integer s) =
    ((s >= 1) && ((i < (2 * s)) || (\forall integer j; (((j >= 0) && (j < s)) ==> (-1 == a[j])))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(const long long a[], long long i, long long s) {
    return ((i == 0) && (s > 1));
}

static inline _Bool c_trans_fun(const long long a[], long long i, long long s, const long long a_next[], long long i_next, long long s_next) {
    return ((i < (2 * s)) && (i_next == (i_next + 1)) && (s_next == s) && (((i < s)) ? (((a_next[i] == ((i - 1) * (i + 1))))) : (((a_next[(i - s)] == (a[(i - s)] - ((i - s) * (i - s))))))));
}

// c_post_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
// c_inv_fun omitted (contains logic quantifier \forall/\exists; verified via ACSL predicate)
int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long a[100];
    for (int _i = 0; _i < 100; ++_i) { a[_i] = nondet_long(); }
    long long i = nondet_long();
    long long s = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(a, i, s)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a, i, s);
      @ loop assigns a[0..99], i, s;
      @*/
    while (1) {
        long long a_next[100];
        for (int _i = 0; _i < 100; ++_i) { a_next[_i] = nondet_long(); }
        long long i_next = nondet_long();
        long long s_next = nondet_long();

        if (!c_trans_fun(a, i, s, a_next, i_next, s_next)) break;

        // State updates
        for (int _i = 0; _i < 100; ++_i) { a[_i] = a_next[_i]; }
        i = i_next;
        s = s_next;
    }

    // 4. Post-condition assertion
    /*@ assert post_fun(a, i, s); */

    return 0;
}
