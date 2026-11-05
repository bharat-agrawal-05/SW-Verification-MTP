/*
 * Generated C verification file from: for_bounded_loop1_false-unreach-call_true-termination.sl
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
  predicate PreF(integer i, integer x, integer y, integer n) =
    ((i == 0) && (x == 0) && (y == 0) && (n > 0));

  predicate TransF(integer i, integer x, integer y, integer n, integer i_next, integer x_next, integer y_next, integer n_next) =
    ((i < n) && (x_next == (x + y_next)) && !((y_next == 0)) && (i_next == i) && (n_next == n));

  predicate PostF(integer i, integer x, integer y, integer n) =
    ((i < n) || (x == 0));

  predicate InvF(integer i, integer x, integer y, integer n) =
    ((i < n) || (x == 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long i, long long x, long long y, long long n) {
    return ((i == 0) && (x == 0) && (y == 0) && (n > 0));
}

static inline _Bool c_TransF(long long i, long long x, long long y, long long n, long long i_next, long long x_next, long long y_next, long long n_next) {
    return ((i < n) && (x_next == (x + y_next)) && !((y_next == 0)) && (i_next == i) && (n_next == n));
}

static inline _Bool c_PostF(long long i, long long x, long long y, long long n) {
    return ((i < n) || (x == 0));
}

static inline _Bool c_InvF(long long i, long long x, long long y, long long n) {
    return ((i < n) || (x == 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long i = nondet_long();
    long long x = nondet_long();
    long long y = nondet_long();
    long long n = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(i, x, y, n)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(i, x, y, n);
      @ loop assigns i, x, y, n;
      @*/
    while (1) {
        long long i_next = nondet_long();
        long long x_next = nondet_long();
        long long y_next = nondet_long();
        long long n_next = nondet_long();

        if (!c_TransF(i, x, y, n, i_next, x_next, y_next, n_next)) break;

        // State updates
        i = i_next;
        x = x_next;
        y = y_next;
        n = n_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(i, x, y, n));
    /*@ assert PostF(i, x, y, n); */

    return 0;
}
