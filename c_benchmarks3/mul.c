/*
 * Generated C verification file from: mul.sl
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
  predicate inv_f(integer i, integer s, integer j, integer j0) =
    ((j >= 0) && (j <= j0) && (s == ((j * (-(i))) + (j0 * i))));
  @*/

static inline _Bool c_inv_f(long long i, long long s, long long j, long long j0) {
    return ((j >= 0) && (j <= j0) && (s == ((j * (-(i))) + (j0 * i))));
}

int main(void) {
    // 1. Variable declarations
    long long i;
    long long s;
    long long j;
    long long j0;

    // 2. Pre-condition initialization
    i = nondet_long();
    s = 0;
    j = j0;
    j0 = nondet_long();
    if (!((j0 >= 0))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(i, s, j, j0);
      @ loop assigns s, j;
      @*/
    while (!((0 == j))) {
        s = (s + i);
        j = (j - 1);
    }

    // 4. Post-condition assertion
    assert((!((0 == j)) || (s == (i * j0))));
    /*@ assert (!((0 == j)) || (s == (i * j0))); */

    return 0;
}
