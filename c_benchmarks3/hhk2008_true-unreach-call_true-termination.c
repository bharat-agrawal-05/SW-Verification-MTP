/*
 * Generated C verification file from: hhk2008_true-unreach-call_true-termination.sl
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
  predicate inv_fun(integer a, integer b, integer res, integer cnt) =
    (((res <= (a + b)) && (a <= 1000000) && (0 <= b) && (b <= 1000000) && (cnt >= 0) && ((res + cnt) == (a + b))) || ((a <= 1000000) && (0 <= b) && (b <= 1000000) && (res == a) && (cnt == b)));
  @*/

static inline _Bool c_inv_fun(long long a, long long b, long long res, long long cnt) {
    return (((res <= (a + b)) && (a <= 1000000) && (0 <= b) && (b <= 1000000) && (cnt >= 0) && ((res + cnt) == (a + b))) || ((a <= 1000000) && (0 <= b) && (b <= 1000000) && (res == a) && (cnt == b)));
}

int main(void) {
    // 1. Variable declarations
    long long a;
    long long b;
    long long res;
    long long cnt;

    // 2. Pre-condition initialization
    a = nondet_long();
    b = nondet_long();
    res = a;
    cnt = b;
    if (!((a <= 1000000))) return 0;
    if (!((0 <= b))) return 0;
    if (!((b <= 1000000))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(a, b, res, cnt);
      @ loop assigns cnt, res;
      @*/
    while ((cnt > 0)) {
        cnt = (cnt - 1);
        res = (res + 1);
    }

    // 4. Post-condition assertion
    assert(((cnt > 0) || (res == (a + b))));
    /*@ assert ((cnt > 0) || (res == (a + b))); */

    return 0;
}
