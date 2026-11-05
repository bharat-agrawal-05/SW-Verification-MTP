/*
 * Generated C verification file from: ccp16.sl
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
  predicate __node_init_top_0(boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0) =
    ((top_usr_OK_a_0 == \true) && top_res_init_flag_a_0);

  predicate __node_trans_top_0(boolean top_usr_OK_a_1, boolean top_res_init_flag_a_1, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0) =
    ((top_usr_OK_a_1 == \true) && !(top_res_init_flag_a_1));

  predicate init(boolean top_usr_OK, boolean top_res_init_flag) =
    ((top_usr_OK == \true) && top_res_init_flag);

  predicate trans(boolean top_usr_OK, boolean top_res_init_flag, boolean top_usr_OK_next, boolean top_res_init_flag_next) =
    ((top_usr_OK_next == \true) && !(top_res_init_flag_next));

  predicate prop(boolean top_usr_OK, boolean top_res_init_flag) =
    top_usr_OK;

  predicate str_invariant(boolean top_usr_OK, boolean top_res_init_flag) =
    (top_usr_OK && !((!(top_usr_OK) && top_res_init_flag)) && !((top_res_init_flag && !(top_usr_OK))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c___node_init_top_0(_Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0) {
    return ((top_usr_OK_a_0 == true) && top_res_init_flag_a_0);
}

static inline _Bool c___node_trans_top_0(_Bool top_usr_OK_a_1, _Bool top_res_init_flag_a_1, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0) {
    return ((top_usr_OK_a_1 == true) && !(top_res_init_flag_a_1));
}

static inline _Bool c_init(_Bool top_usr_OK, _Bool top_res_init_flag) {
    return ((top_usr_OK == true) && top_res_init_flag);
}

static inline _Bool c_trans(_Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_usr_OK_next, _Bool top_res_init_flag_next) {
    return ((top_usr_OK_next == true) && !(top_res_init_flag_next));
}

static inline _Bool c_prop(_Bool top_usr_OK, _Bool top_res_init_flag) {
    return top_usr_OK;
}

static inline _Bool c_str_invariant(_Bool top_usr_OK, _Bool top_res_init_flag) {
    return (top_usr_OK && !((!(top_usr_OK) && top_res_init_flag)) && !((top_res_init_flag && !(top_usr_OK))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    _Bool top_usr_OK = nondet_bool();
    _Bool top_res_init_flag = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_init(top_usr_OK, top_res_init_flag)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant str_invariant(top_usr_OK, top_res_init_flag);
      @ loop assigns top_usr_OK, top_res_init_flag;
      @*/
    while (1) {
        _Bool top_usr_OK_next = nondet_bool();
        _Bool top_res_init_flag_next = nondet_bool();

        if (!c_trans(top_usr_OK, top_res_init_flag, top_usr_OK_next, top_res_init_flag_next)) break;

        // State updates
        top_usr_OK = top_usr_OK_next;
        top_res_init_flag = top_res_init_flag_next;
    }

    // 4. Post-condition assertion
    assert(c_prop(top_usr_OK, top_res_init_flag));
    /*@ assert prop(top_usr_OK, top_res_init_flag); */

    return 0;
}
