/*
 * Generated C verification file from: sendmail-close-angle_true-unreach-call_true-termination.sl
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
  predicate InvF(integer in, integer inlen, integer bufferlen, integer buf, integer buflim) =
    ((in >= 0) && (inlen >= 0) && (bufferlen >= 2) && (buflim == (bufferlen - 2)) && (buf <= buflim) && (0 <= buf) && (buf <= (inlen + bufferlen + buflim)));
  @*/

static inline _Bool c_InvF(long long in, long long inlen, long long bufferlen, long long buf, long long buflim) {
    return ((in >= 0) && (inlen >= 0) && (bufferlen >= 2) && (buflim == (bufferlen - 2)) && (buf <= buflim) && (0 <= buf) && (buf <= (inlen + bufferlen + buflim)));
}

int main(void) {
    // 1. Variable declarations
    long long in;
    long long inlen;
    long long bufferlen;
    long long buf;
    long long buflim;

    // 2. Pre-condition initialization
    in = 0;
    inlen = nondet_long();
    bufferlen = nondet_long();
    buf = 0;
    buflim = (bufferlen - 2);
    if (!((bufferlen > 1))) return 0;
    if (!((inlen > 0))) return 0;
    if (!((bufferlen < inlen))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(in, inlen, bufferlen, buf, buflim);
      @ loop assigns buf, in;
      @*/
    while (!((buf == buflim))) {
        buf = (buf + 1);
        in = (in + 1);
    }

    // 4. Post-condition assertion
    assert(((buf == buflim) || ((0 <= buf) && (buf < bufferlen))));
    /*@ assert ((buf == buflim) || ((0 <= buf) && (buf < bufferlen))); */

    return 0;
}
