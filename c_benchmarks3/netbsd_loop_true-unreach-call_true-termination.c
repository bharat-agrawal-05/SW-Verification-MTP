/*
 * Generated C verification file from: netbsd_loop_true-unreach-call_true-termination.sl
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
  predicate InvF(integer MAXPATHLEN, integer pathbuf_off, integer bound_off, integer glob2_p_off, integer glob2_pathbuf_off, integer glob2_pathlim_off) =
    ((MAXPATHLEN > 0) && (MAXPATHLEN < 2147483647) && (pathbuf_off == 0) && (bound_off == ((pathbuf_off + (MAXPATHLEN + 1)) - 1)) && (0 <= glob2_p_off) && (glob2_p_off <= (MAXPATHLEN + 1)) && (glob2_p_off <= glob2_pathlim_off) && (glob2_pathlim_off <= bound_off) && (glob2_pathbuf_off == pathbuf_off) && (glob2_p_off == glob2_pathbuf_off) && (glob2_pathlim_off == ((pathbuf_off + (MAXPATHLEN + 1)) - 1)));
  @*/

static inline _Bool c_InvF(long long MAXPATHLEN, long long pathbuf_off, long long bound_off, long long glob2_p_off, long long glob2_pathbuf_off, long long glob2_pathlim_off) {
    return ((MAXPATHLEN > 0) && (MAXPATHLEN < 2147483647) && (pathbuf_off == 0) && (bound_off == ((pathbuf_off + (MAXPATHLEN + 1)) - 1)) && (0 <= glob2_p_off) && (glob2_p_off <= (MAXPATHLEN + 1)) && (glob2_p_off <= glob2_pathlim_off) && (glob2_pathlim_off <= bound_off) && (glob2_pathbuf_off == pathbuf_off) && (glob2_p_off == glob2_pathbuf_off) && (glob2_pathlim_off == ((pathbuf_off + (MAXPATHLEN + 1)) - 1)));
}

int main(void) {
    // 1. Variable declarations
    long long MAXPATHLEN;
    long long pathbuf_off;
    long long bound_off;
    long long glob2_p_off;
    long long glob2_pathbuf_off;
    long long glob2_pathlim_off;

    // 2. Pre-condition initialization
    MAXPATHLEN = nondet_long();
    pathbuf_off = 0;
    bound_off = ((0 + (MAXPATHLEN + 1)) - 1);
    glob2_p_off = 0;
    glob2_pathbuf_off = 0;
    glob2_pathlim_off = ((0 + (MAXPATHLEN + 1)) - 1);
    if (!((MAXPATHLEN > 0))) return 0;
    if (!((MAXPATHLEN < 2147483647))) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant InvF(MAXPATHLEN, pathbuf_off, bound_off, glob2_p_off, glob2_pathbuf_off, glob2_pathlim_off);
      @ loop assigns MAXPATHLEN, pathbuf_off, bound_off, glob2_p_off, glob2_pathbuf_off, glob2_pathlim_off;
      @*/
    while (((glob2_p_off + 1) <= glob2_pathlim_off)) {
    }

    // 4. Post-condition assertion
    assert((!((glob2_p_off <= glob2_pathlim_off)) || ((glob2_p_off <= 0) && (glob2_p_off < (MAXPATHLEN + 1)))));
    /*@ assert (!((glob2_p_off <= glob2_pathlim_off)) || ((glob2_p_off <= 0) && (glob2_p_off < (MAXPATHLEN + 1)))); */

    return 0;
}
