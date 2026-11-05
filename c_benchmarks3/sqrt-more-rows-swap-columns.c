/*
 * Generated C verification file from: sqrt-more-rows-swap-columns.sl
 * SMT-LIB Logic: NIA
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
  predicate pre_f(integer n, integer a, integer su, integer t) =
    ((a == 0) && (su == 1) && (t == 1) && (n > 0));

  predicate trans_f(integer n, integer a, integer su, integer t, integer n_next, integer a_next, integer su_next, integer t_next) =
    ((su <= n) && (n_next == n) && (a_next == (a + 1)) && (t_next == (t + 2)) && (su_next == (su + t_next)));

  predicate post_f(integer n, integer a, integer su, integer t) =
    ((su <= n) || (su == ((a + 1) * (a + 1))));

  predicate inv_f(integer n, integer a, integer su, integer t) =
    ((0 <= a) && (1 <= su) && (t == ((2 * a) + 1)) && (su == ((a * a) + (a * 2) + 1)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_f(long long n, long long a, long long su, long long t) {
    return ((a == 0) && (su == 1) && (t == 1) && (n > 0));
}

static inline _Bool c_trans_f(long long n, long long a, long long su, long long t, long long n_next, long long a_next, long long su_next, long long t_next) {
    return ((su <= n) && (n_next == n) && (a_next == (a + 1)) && (t_next == (t + 2)) && (su_next == (su + t_next)));
}

static inline _Bool c_post_f(long long n, long long a, long long su, long long t) {
    return ((su <= n) || (su == ((a + 1) * (a + 1))));
}

static inline _Bool c_inv_f(long long n, long long a, long long su, long long t) {
    return ((0 <= a) && (1 <= su) && (t == ((2 * a) + 1)) && (su == ((a * a) + (a * 2) + 1)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long n = nondet_long();
    long long a = nondet_long();
    long long su = nondet_long();
    long long t = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_f(n, a, su, t)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, a, su, t);
      @ loop assigns n, a, su, t;
      @*/
    while (1) {
        long long n_next = nondet_long();
        long long a_next = nondet_long();
        long long su_next = nondet_long();
        long long t_next = nondet_long();

        if (!c_trans_f(n, a, su, t, n_next, a_next, su_next, t_next)) break;

        // State updates
        n = n_next;
        a = a_next;
        su = su_next;
        t = t_next;
    }

    // 4. Post-condition assertion
    assert(c_post_f(n, a, su, t));
    /*@ assert post_f(n, a, su, t); */

    return 0;
}
