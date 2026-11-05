/*
 * Generated C verification file from: 67.c.sl
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
  // ACSL Logic Invariant Predicate (using mathematical integers)
  predicate inv_f(integer n, integer x, integer y) =
    (((x == x) && (y == y) && (x <= n) && (y <= n) && (x <= (x + 1)) && (y <= (n - x)) && (n == n)) || !(((n == n) && (x == x) && (y == y) && !((x <= n)) && (n > 0) && !((y >= 0)))));
  @*/

static inline _Bool c_inv_f(long long n, long long x, long long y) {
    return (((x == x) && (y == y) && (x <= n) && (y <= n) && (x <= (x + 1)) && (y <= (n - x)) && (n == n)) || !(((n == n) && (x == x) && (y == y) && !((x <= n)) && (n > 0) && !((y >= 0)))));
}

int main(void) {
    // 1. Variable declarations
    long long n;
    long long x;
    long long y;

    // 2. Pre-condition initialization
    n = nondet_long();
    x = 1;
    y = nondet_long();

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_f(n, x, y);
      @ loop assigns x, y;
      @*/
    while ((x <= n)) {
        long long _old_x = x;
        x = (_old_x + 1);
        y = (n - _old_x);
    }

    // 4. Post-condition assertion
    assert((!(((n == n) && (x == x) && (y == y))) || !((!((x <= n)) && (n > 0) && !((y >= 0))))));
    /*@ assert (!(((n == n) && (x == x) && (y == y))) || !((!((x <= n)) && (n > 0) && !((y >= 0))))); */

    return 0;
}
