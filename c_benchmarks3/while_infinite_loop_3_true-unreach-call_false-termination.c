/*
 * Generated C verification file from: while_infinite_loop_3_true-unreach-call_false-termination.sl
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
  predicate PreF(integer x) =
    (x == 0);

  predicate TransF(integer x, integer x_next) =
    (x_next == 0);

  predicate PostF(integer x) =
    (x == 0);

  predicate InvF(integer x) =
    ((x >= 0) && (x == 0));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_PreF(long long x) {
    return (x == 0);
}

static inline _Bool c_TransF(long long x, long long x_next) {
    return (x_next == 0);
}

static inline _Bool c_PostF(long long x) {
    return (x == 0);
}

static inline _Bool c_InvF(long long x) {
    return ((x >= 0) && (x == 0));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long x = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_PreF(x)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(x);
      @ loop assigns x;
      @*/
    while (1) {
        long long x_next = nondet_long();

        if (!c_TransF(x, x_next)) break;

        // State updates
        x = x_next;
    }

    // 4. Post-condition assertion
    assert(c_PostF(x));
    /*@ assert PostF(x); */

    return 0;
}
