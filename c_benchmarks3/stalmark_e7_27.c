/*
 * Generated C verification file from: stalmark_e7_27.sl
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
  predicate __node_init_top_0(boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, boolean top_impl_usr_a_a_0, boolean top_impl_usr_b_a_0, boolean top_impl_usr_c_a_0) =
    ((top_impl_usr_c_a_0 == \false) && (top_impl_usr_b_a_0 == \false) && (top_impl_usr_a_a_0 == \true) && (top_usr_OK_a_0 == (((((!(top_impl_usr_a_a_0) || (!(top_impl_usr_b_a_0) && top_impl_usr_c_a_0)) || ((!(top_impl_usr_a_a_0) && top_impl_usr_b_a_0) && !(top_impl_usr_c_a_0))) || ((top_impl_usr_a_a_0 && !(top_impl_usr_b_a_0)) && !(top_impl_usr_c_a_0))) || ((top_impl_usr_a_a_0 && top_impl_usr_b_a_0) && top_impl_usr_c_a_0)) && !(((top_impl_usr_a_a_0 && top_impl_usr_b_a_0) && top_impl_usr_c_a_0)))) && top_res_init_flag_a_0);

  predicate __node_trans_top_0(boolean top_usr_OK_a_1, boolean top_res_init_flag_a_1, boolean top_impl_usr_a_a_1, boolean top_impl_usr_b_a_1, boolean top_impl_usr_c_a_1, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, boolean top_impl_usr_a_a_0, boolean top_impl_usr_b_a_0, boolean top_impl_usr_c_a_0) =
    ((top_impl_usr_c_a_1 == top_impl_usr_b_a_0) && (top_impl_usr_b_a_1 == top_impl_usr_a_a_0) && (top_impl_usr_a_a_1 == top_impl_usr_c_a_0) && (top_usr_OK_a_1 == (((((!(top_impl_usr_a_a_1) || (!(top_impl_usr_b_a_1) && top_impl_usr_c_a_1)) || ((!(top_impl_usr_a_a_1) && top_impl_usr_b_a_1) && !(top_impl_usr_c_a_1))) || ((top_impl_usr_a_a_1 && !(top_impl_usr_b_a_1)) && !(top_impl_usr_c_a_1))) || ((top_impl_usr_a_a_1 && top_impl_usr_b_a_1) && top_impl_usr_c_a_1)) && !(((top_impl_usr_a_a_1 && top_impl_usr_b_a_1) && top_impl_usr_c_a_1)))) && !(top_res_init_flag_a_1));

  predicate init(boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_a, boolean top_impl_usr_b, boolean top_impl_usr_c) =
    ((top_impl_usr_c == \false) && (top_impl_usr_b == \false) && (top_impl_usr_a == \true) && (top_usr_OK == (((((!(top_impl_usr_a) || (!(top_impl_usr_b) && top_impl_usr_c)) || ((!(top_impl_usr_a) && top_impl_usr_b) && !(top_impl_usr_c))) || ((top_impl_usr_a && !(top_impl_usr_b)) && !(top_impl_usr_c))) || ((top_impl_usr_a && top_impl_usr_b) && top_impl_usr_c)) && !(((top_impl_usr_a && top_impl_usr_b) && top_impl_usr_c)))) && top_res_init_flag);

  predicate trans(boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_a, boolean top_impl_usr_b, boolean top_impl_usr_c, boolean top_usr_OK_next, boolean top_res_init_flag_next, boolean top_impl_usr_a_next, boolean top_impl_usr_b_next, boolean top_impl_usr_c_next) =
    ((top_impl_usr_c_next == top_impl_usr_b) && (top_impl_usr_b_next == top_impl_usr_a) && (top_impl_usr_a_next == top_impl_usr_c) && (top_usr_OK_next == (((((!(top_impl_usr_a_next) || (!(top_impl_usr_b_next) && top_impl_usr_c_next)) || ((!(top_impl_usr_a_next) && top_impl_usr_b_next) && !(top_impl_usr_c_next))) || ((top_impl_usr_a_next && !(top_impl_usr_b_next)) && !(top_impl_usr_c_next))) || ((top_impl_usr_a_next && top_impl_usr_b_next) && top_impl_usr_c_next)) && !(((top_impl_usr_a_next && top_impl_usr_b_next) && top_impl_usr_c_next)))) && !(top_res_init_flag_next));

  predicate prop(boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_a, boolean top_impl_usr_b, boolean top_impl_usr_c) =
    top_usr_OK;

  predicate str_invariant(boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_a, boolean top_impl_usr_b, boolean top_impl_usr_c) =
    (((top_impl_usr_a && !(top_impl_usr_b) && !(top_impl_usr_c)) || (!(top_impl_usr_a) && top_impl_usr_b && !(top_impl_usr_c)) || (!(top_impl_usr_a) && !(top_impl_usr_b) && top_impl_usr_c)) && !((top_impl_usr_a && top_impl_usr_b && top_impl_usr_c)) && (top_usr_OK == !((top_impl_usr_a && top_impl_usr_b && top_impl_usr_c))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c___node_init_top_0(_Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, _Bool top_impl_usr_a_a_0, _Bool top_impl_usr_b_a_0, _Bool top_impl_usr_c_a_0) {
    return ((top_impl_usr_c_a_0 == false) && (top_impl_usr_b_a_0 == false) && (top_impl_usr_a_a_0 == true) && (top_usr_OK_a_0 == (((((!(top_impl_usr_a_a_0) || (!(top_impl_usr_b_a_0) && top_impl_usr_c_a_0)) || ((!(top_impl_usr_a_a_0) && top_impl_usr_b_a_0) && !(top_impl_usr_c_a_0))) || ((top_impl_usr_a_a_0 && !(top_impl_usr_b_a_0)) && !(top_impl_usr_c_a_0))) || ((top_impl_usr_a_a_0 && top_impl_usr_b_a_0) && top_impl_usr_c_a_0)) && !(((top_impl_usr_a_a_0 && top_impl_usr_b_a_0) && top_impl_usr_c_a_0)))) && top_res_init_flag_a_0);
}

static inline _Bool c___node_trans_top_0(_Bool top_usr_OK_a_1, _Bool top_res_init_flag_a_1, _Bool top_impl_usr_a_a_1, _Bool top_impl_usr_b_a_1, _Bool top_impl_usr_c_a_1, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, _Bool top_impl_usr_a_a_0, _Bool top_impl_usr_b_a_0, _Bool top_impl_usr_c_a_0) {
    return ((top_impl_usr_c_a_1 == top_impl_usr_b_a_0) && (top_impl_usr_b_a_1 == top_impl_usr_a_a_0) && (top_impl_usr_a_a_1 == top_impl_usr_c_a_0) && (top_usr_OK_a_1 == (((((!(top_impl_usr_a_a_1) || (!(top_impl_usr_b_a_1) && top_impl_usr_c_a_1)) || ((!(top_impl_usr_a_a_1) && top_impl_usr_b_a_1) && !(top_impl_usr_c_a_1))) || ((top_impl_usr_a_a_1 && !(top_impl_usr_b_a_1)) && !(top_impl_usr_c_a_1))) || ((top_impl_usr_a_a_1 && top_impl_usr_b_a_1) && top_impl_usr_c_a_1)) && !(((top_impl_usr_a_a_1 && top_impl_usr_b_a_1) && top_impl_usr_c_a_1)))) && !(top_res_init_flag_a_1));
}

static inline _Bool c_init(_Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_a, _Bool top_impl_usr_b, _Bool top_impl_usr_c) {
    return ((top_impl_usr_c == false) && (top_impl_usr_b == false) && (top_impl_usr_a == true) && (top_usr_OK == (((((!(top_impl_usr_a) || (!(top_impl_usr_b) && top_impl_usr_c)) || ((!(top_impl_usr_a) && top_impl_usr_b) && !(top_impl_usr_c))) || ((top_impl_usr_a && !(top_impl_usr_b)) && !(top_impl_usr_c))) || ((top_impl_usr_a && top_impl_usr_b) && top_impl_usr_c)) && !(((top_impl_usr_a && top_impl_usr_b) && top_impl_usr_c)))) && top_res_init_flag);
}

static inline _Bool c_trans(_Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_a, _Bool top_impl_usr_b, _Bool top_impl_usr_c, _Bool top_usr_OK_next, _Bool top_res_init_flag_next, _Bool top_impl_usr_a_next, _Bool top_impl_usr_b_next, _Bool top_impl_usr_c_next) {
    return ((top_impl_usr_c_next == top_impl_usr_b) && (top_impl_usr_b_next == top_impl_usr_a) && (top_impl_usr_a_next == top_impl_usr_c) && (top_usr_OK_next == (((((!(top_impl_usr_a_next) || (!(top_impl_usr_b_next) && top_impl_usr_c_next)) || ((!(top_impl_usr_a_next) && top_impl_usr_b_next) && !(top_impl_usr_c_next))) || ((top_impl_usr_a_next && !(top_impl_usr_b_next)) && !(top_impl_usr_c_next))) || ((top_impl_usr_a_next && top_impl_usr_b_next) && top_impl_usr_c_next)) && !(((top_impl_usr_a_next && top_impl_usr_b_next) && top_impl_usr_c_next)))) && !(top_res_init_flag_next));
}

static inline _Bool c_prop(_Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_a, _Bool top_impl_usr_b, _Bool top_impl_usr_c) {
    return top_usr_OK;
}

static inline _Bool c_str_invariant(_Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_a, _Bool top_impl_usr_b, _Bool top_impl_usr_c) {
    return (((top_impl_usr_a && !(top_impl_usr_b) && !(top_impl_usr_c)) || (!(top_impl_usr_a) && top_impl_usr_b && !(top_impl_usr_c)) || (!(top_impl_usr_a) && !(top_impl_usr_b) && top_impl_usr_c)) && !((top_impl_usr_a && top_impl_usr_b && top_impl_usr_c)) && (top_usr_OK == !((top_impl_usr_a && top_impl_usr_b && top_impl_usr_c))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    _Bool top_usr_OK = nondet_bool();
    _Bool top_res_init_flag = nondet_bool();
    _Bool top_impl_usr_a = nondet_bool();
    _Bool top_impl_usr_b = nondet_bool();
    _Bool top_impl_usr_c = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_init(top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant str_invariant(top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c);
      @ loop assigns top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c;
      @*/
    while (1) {
        _Bool top_usr_OK_next = nondet_bool();
        _Bool top_res_init_flag_next = nondet_bool();
        _Bool top_impl_usr_a_next = nondet_bool();
        _Bool top_impl_usr_b_next = nondet_bool();
        _Bool top_impl_usr_c_next = nondet_bool();

        if (!c_trans(top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c, top_usr_OK_next, top_res_init_flag_next, top_impl_usr_a_next, top_impl_usr_b_next, top_impl_usr_c_next)) break;

        // State updates
        top_usr_OK = top_usr_OK_next;
        top_res_init_flag = top_res_init_flag_next;
        top_impl_usr_a = top_impl_usr_a_next;
        top_impl_usr_b = top_impl_usr_b_next;
        top_impl_usr_c = top_impl_usr_c_next;
    }

    // 4. Post-condition assertion
    assert(c_prop(top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c));
    /*@ assert prop(top_usr_OK, top_res_init_flag, top_impl_usr_a, top_impl_usr_b, top_impl_usr_c); */

    return 0;
}
