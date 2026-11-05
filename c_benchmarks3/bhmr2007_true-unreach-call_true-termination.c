/*
 * Generated C verification file from: bhmr2007_true-unreach-call_true-termination.sl
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
  predicate PreF(integer i, integer n, integer a, integer b) =
    ((i == 0) && (a == 0) && (b == 0) && (n >= 0));

  predicate TransF(integer i, integer n, integer a, integer b, integer i_next, integer n_next, integer a_next, integer b_next) =
    ((i < n) && (((a_next == (a + 1)) && (b_next == (b + 2))) || ((a_next == (a + 2)) && (b_next == (b + 1)))) && (i_next == (i + 1)) && (n_next == n));

  predicate PostF(integer i, integer n, integer a, integer b) =
    ((i < n) || ((a + b) == (3 * n)));

  predicate InvF(integer i, integer n, integer a, integer b) =
    (((i <= n) && ((a + b) == (3 * i))) || ((n < i) && ((a + b) == (3 * n))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long i, long long n, long long a, long long b) {
    return ((i == 0) && (a == 0) && (b == 0) && (n >= 0));
}

static inline _Bool c_TransF(long long i, long long n, long long a, long long b, long long i_next, long long n_next, long long a_next, long long b_next) {
    return ((i < n) && (((a_next == (a + 1)) && (b_next == (b + 2))) || ((a_next == (a + 2)) && (b_next == (b + 1)))) && (i_next == (i + 1)) && (n_next == n));
}

static inline _Bool c_PostF(long long i, long long n, long long a, long long b) {
    return ((i < n) || ((a + b) == (3 * n)));
}

static inline _Bool c_InvF(long long i, long long n, long long a, long long b) {
    return (((i <= n) && ((a + b) == (3 * i))) || ((n < i) && ((a + b) == (3 * n))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long n = nondet_long();
    long long a = nondet_long();
    long long b = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(i, n, a, b)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, n, a, b);
      @ loop assigns i, n, a, b;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long n_next = nondet_long();
        long long a_next = nondet_long();
        long long b_next = nondet_long();

        if (!c_TransF(i, n, a, b, i_next, n_next, a_next, b_next)) break;

        // State updates
        i = i_next;
        n = n_next;
        a = a_next;
        b = b_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(i, n, a, b));
    /*@ assert PostF(i, n, a, b); */

    return 0;
}
