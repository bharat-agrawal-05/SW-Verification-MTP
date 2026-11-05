/*
 * Generated C verification file from: sorin03.desugared.sl
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
  // ACSL Logic Invariant Predicate (using mathematical integers)
  predicate inv_f(integer n, integer s, integer i, integer j) =
    ((1 <= n) && (n <= 1000) && (1 <= i) && (i <= (n + 1)) && (0 <= j) && ((2 * s) == (i * (i + -1))));
  @*/

static inline _Bool c_inv_f(long long n, long long s, long long i, long long j) {
    return ((1 <= n) && (n <= 1000) && (1 <= i) && (i <= (n + 1)) && (0 <= j) && ((2 * s) == (i * (i + -1))));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long s;
    long long i;
    long long j;

    // 2. Pre-condition initialization
    n = nondet_long();
    s = 0;
    i = 1;
    j = 0;
    if (!((1 <= n))) return 0;
    if (!((n <= 1000))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, s, i, j);
      @ loop assigns s, j, i;
      @*/
    while ((i <= n)) {
        long long _old_i = i;
        s = (s + _old_i);
        j = _old_i;
        i = (_old_i + 1);
    }

    // 4. Post-condition assertion
    assert(((i <= n) || ((2 * s) == (n * (n + 1)))));
    /*@ assert ((i <= n) || ((2 * s) == (n * (n + 1)))); */

    return 0;
}
