/*
 * Generated C verification file from: sorin04.desugared.sl
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
  predicate inv_f(integer i, integer a, integer c) =
    ((i >= 0) && (i <= 10) && (a == (i * (i + 1) * 0.5)) && (c == (i * (i * i))));
  @*/

static inline _Bool c_inv_f(long long i, long long a, long long c) {
    return ((i >= 0) && (i <= 10) && (a == (i * (i + 1) * 0.5)) && (c == (i * (i * i))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long a;
    long long c;

    // 2. Pre-condition initialization
    i = 0;
    a = 0;
    c = 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, a, c);
      @ loop assigns c, a, i;
      @*/
    while ((i < 10)) {
        long long _old_a = a;
        long long _old_i = i;
        c = (c + (1 + (6 * _old_a)));
        a = (_old_a + (_old_i + 1));
        i = (_old_i + 1);
    }

    // 4. Post-condition assertion
    assert(((i < 10) || (c == (i * (i * i)))));
    /*@ assert ((i < 10) || (c == (i * (i * i)))); */

    return 0;
}
