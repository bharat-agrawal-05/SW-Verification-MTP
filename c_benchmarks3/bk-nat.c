/*
 * Generated C verification file from: bk-nat.sl
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
  predicate pre_fun(integer invalid, integer unowned, integer nonexclusive, integer exclusive, integer RETURN) =
    ((((invalid >= 1)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((unowned == 0)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((nonexclusive == 0)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((exclusive == 0)) ? ((RETURN == 0)) : ((RETURN == 1))));

  predicate trans_fun(integer invalid, integer unowned, integer nonexclusive, integer exclusive, integer RETURN, integer invalid_next, integer unowned_next, integer nonexclusive_next, integer exclusive_next, integer RETURN_next) =
    ((((!((invalid >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == (nonexclusive + exclusive)) && (exclusive_next == 0) && (invalid_next == (invalid - 1)) && (unowned_next == (unowned + 1))) || (((!(((nonexclusive + unowned) >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == 0) && (exclusive_next == (exclusive + 1)) && (invalid_next == ((invalid + unowned + nonexclusive) - 1)) && (unowned_next == 0)) || (((!((invalid >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == 0) && (exclusive_next == 1) && (invalid_next == ((invalid + unowned_next + exclusive_next + nonexclusive_next) - 1)) && (unowned_next == 0)));

  predicate post_fun(integer invalid, integer unowned, integer nonexclusive, integer exclusive, integer RETURN) =
    ((RETURN == 0) ==> ((exclusive >= 0) && (nonexclusive >= 0) && (unowned >= 0) && (invalid >= 0) && ((invalid + unowned + exclusive) >= 1)));

  predicate inv_fun(integer invalid, integer unowned, integer nonexclusive, integer exclusive, integer RETURN) =
    (((unowned >= 0) && (nonexclusive >= 0) && (exclusive >= 0) && (invalid >= 0) && ((invalid + unowned + exclusive) >= 1) && (RETURN == 0)) || (RETURN == 1));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c_pre_fun(long long invalid, long long unowned, long long nonexclusive, long long exclusive, long long RETURN) {
    return ((((invalid >= 1)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((unowned == 0)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((nonexclusive == 0)) ? ((RETURN == 0)) : ((RETURN == 1))) && (((exclusive == 0)) ? ((RETURN == 0)) : ((RETURN == 1))));
}

static inline _Bool c_trans_fun(long long invalid, long long unowned, long long nonexclusive, long long exclusive, long long RETURN, long long invalid_next, long long unowned_next, long long nonexclusive_next, long long exclusive_next, long long RETURN_next) {
    return ((((!((invalid >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == (nonexclusive + exclusive)) && (exclusive_next == 0) && (invalid_next == (invalid - 1)) && (unowned_next == (unowned + 1))) || (((!(((nonexclusive + unowned) >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == 0) && (exclusive_next == (exclusive + 1)) && (invalid_next == ((invalid + unowned + nonexclusive) - 1)) && (unowned_next == 0)) || (((!((invalid >= 1))) ? ((RETURN_next == 1)) : ((RETURN_next == RETURN))) && (nonexclusive_next == 0) && (exclusive_next == 1) && (invalid_next == ((invalid + unowned_next + exclusive_next + nonexclusive_next) - 1)) && (unowned_next == 0)));
}

static inline _Bool c_post_fun(long long invalid, long long unowned, long long nonexclusive, long long exclusive, long long RETURN) {
    return (!((RETURN == 0)) || ((exclusive >= 0) && (nonexclusive >= 0) && (unowned >= 0) && (invalid >= 0) && ((invalid + unowned + exclusive) >= 1)));
}

static inline _Bool c_inv_fun(long long invalid, long long unowned, long long nonexclusive, long long exclusive, long long RETURN) {
    return (((unowned >= 0) && (nonexclusive >= 0) && (exclusive >= 0) && (invalid >= 0) && ((invalid + unowned + exclusive) >= 1) && (RETURN == 0)) || (RETURN == 1));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long invalid = nondet_long();
    long long unowned = nondet_long();
    long long nonexclusive = nondet_long();
    long long exclusive = nondet_long();
    long long RETURN = nondet_long();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_pre_fun(invalid, unowned, nonexclusive, exclusive, RETURN)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant inv_fun(invalid, unowned, nonexclusive, exclusive, RETURN);
      @ loop assigns invalid, unowned, nonexclusive, exclusive, RETURN;
      @*/
    while (1) {
        long long invalid_next = nondet_long();
        long long unowned_next = nondet_long();
        long long nonexclusive_next = nondet_long();
        long long exclusive_next = nondet_long();
        long long RETURN_next = nondet_long();

        if (!c_trans_fun(invalid, unowned, nonexclusive, exclusive, RETURN, invalid_next, unowned_next, nonexclusive_next, exclusive_next, RETURN_next)) break;

        // State updates
        invalid = invalid_next;
        unowned = unowned_next;
        nonexclusive = nonexclusive_next;
        exclusive = exclusive_next;
        RETURN = RETURN_next;
    }

    // 4. Post-condition assertion
    assert(c_post_fun(invalid, unowned, nonexclusive, exclusive, RETURN));
    /*@ assert post_fun(invalid, unowned, nonexclusive, exclusive, RETURN); */

    return 0;
}
