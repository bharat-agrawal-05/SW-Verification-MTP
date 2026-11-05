/*
 * Generated C verification file from: traffic.sl
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
  predicate __node_init_Sofar_0(boolean Sofar_usr_X_a_0, boolean Sofar_usr_Y_a_0, boolean Sofar_res_init_flag_a_0) =
    ((Sofar_usr_Y_a_0 == Sofar_usr_X_a_0) && Sofar_res_init_flag_a_0);

  predicate __node_trans_Sofar_0(boolean Sofar_usr_X_a_1, boolean Sofar_usr_Y_a_1, boolean Sofar_res_init_flag_a_1, boolean Sofar_usr_X_a_0, boolean Sofar_usr_Y_a_0, boolean Sofar_res_init_flag_a_0) =
    ((Sofar_usr_Y_a_1 == (Sofar_usr_Y_a_0 && Sofar_usr_X_a_1)) && !(Sofar_res_init_flag_a_1));

  predicate __node_init_Store_0(integer Store_usr_Delta_a_0, integer Store_usr_Total_a_0, boolean Store_res_init_flag_a_0) =
    ((Store_usr_Total_a_0 == ((((Store_usr_Delta_a_0 < 0) && (0 > 0))) ? ((0 + Store_usr_Delta_a_0)) : (((((Store_usr_Delta_a_0 > 0) && (0 < 10))) ? ((0 + Store_usr_Delta_a_0)) : (0))))) && Store_res_init_flag_a_0);

  predicate __node_trans_Store_0(integer Store_usr_Delta_a_1, integer Store_usr_Total_a_1, boolean Store_res_init_flag_a_1, integer Store_usr_Delta_a_0, integer Store_usr_Total_a_0, boolean Store_res_init_flag_a_0) =
    ((Store_usr_Total_a_1 == ((((Store_usr_Delta_a_1 < 0) && (Store_usr_Total_a_0 > 0))) ? ((Store_usr_Total_a_0 + Store_usr_Delta_a_1)) : (((((Store_usr_Delta_a_1 > 0) && (Store_usr_Total_a_0 < 10))) ? ((Store_usr_Total_a_0 + Store_usr_Delta_a_1)) : (Store_usr_Total_a_0))))) && !(Store_res_init_flag_a_1));

  predicate __node_init_top_0(integer top_usr_Delta_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, integer top_res_abs_0_a_0, boolean top_res_abs_1_a_0, boolean top_res_abs_2_a_0, boolean top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_res_abs_1_a_0 == ((-1 <= top_usr_Delta_a_0) && (top_usr_Delta_a_0 <= 1))) && ((top_usr_OK_a_0 == (top_res_abs_2_a_0 ==> ((0 <= top_res_abs_0_a_0) && (top_res_abs_0_a_0 <= 20)))) && __node_init_Store_0(top_usr_Delta_a_0, top_res_abs_0_a_0, top_res_inst_1_a_0) && __node_init_Sofar_0(top_res_abs_1_a_0, top_res_abs_2_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));

  predicate __node_trans_top_0(integer top_usr_Delta_a_1, boolean top_usr_OK_a_1, boolean top_res_init_flag_a_1, integer top_res_abs_0_a_1, boolean top_res_abs_1_a_1, boolean top_res_abs_2_a_1, boolean top_res_inst_1_a_1, boolean top_res_inst_0_a_1, integer top_usr_Delta_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, integer top_res_abs_0_a_0, boolean top_res_abs_1_a_0, boolean top_res_abs_2_a_0, boolean top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_res_abs_1_a_1 == ((-1 <= top_usr_Delta_a_1) && (top_usr_Delta_a_1 <= 1))) && ((top_usr_OK_a_1 == (top_res_abs_2_a_1 ==> ((0 <= top_res_abs_0_a_1) && (top_res_abs_0_a_1 <= 20)))) && __node_trans_Store_0(top_usr_Delta_a_1, top_res_abs_0_a_1, top_res_inst_1_a_1, top_usr_Delta_a_0, top_res_abs_0_a_0, top_res_inst_1_a_0) && __node_trans_Sofar_0(top_res_abs_1_a_1, top_res_abs_2_a_1, top_res_inst_0_a_1, top_res_abs_1_a_0, top_res_abs_2_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1)));

  predicate init(integer top_usr_Delta, boolean top_usr_OK, boolean top_res_init_flag, integer top_res_abs_0, boolean top_res_abs_1, boolean top_res_abs_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    ((top_res_abs_1 == ((-1 <= top_usr_Delta) && (top_usr_Delta <= 1))) && ((top_usr_OK == (top_res_abs_2 ==> ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20)))) && __node_init_Store_0(top_usr_Delta, top_res_abs_0, top_res_inst_1) && __node_init_Sofar_0(top_res_abs_1, top_res_abs_2, top_res_inst_0) && top_res_init_flag));

  predicate trans(integer top_usr_Delta, boolean top_usr_OK, boolean top_res_init_flag, integer top_res_abs_0, boolean top_res_abs_1, boolean top_res_abs_2, boolean top_res_inst_1, boolean top_res_inst_0, integer top_usr_Delta_next, boolean top_usr_OK_next, boolean top_res_init_flag_next, integer top_res_abs_0_next, boolean top_res_abs_1_next, boolean top_res_abs_2_next, boolean top_res_inst_1_next, boolean top_res_inst_0_next) =
    ((top_res_abs_1_next == ((-1 <= top_usr_Delta_next) && (top_usr_Delta_next <= 1))) && ((top_usr_OK_next == (top_res_abs_2_next ==> ((0 <= top_res_abs_0_next) && (top_res_abs_0_next <= 20)))) && __node_trans_Store_0(top_usr_Delta_next, top_res_abs_0_next, top_res_inst_1_next, top_usr_Delta, top_res_abs_0, top_res_inst_1) && __node_trans_Sofar_0(top_res_abs_1_next, top_res_abs_2_next, top_res_inst_0_next, top_res_abs_1, top_res_abs_2, top_res_inst_0) && !(top_res_init_flag_next)));

  predicate prop(integer top_usr_Delta, boolean top_usr_OK, boolean top_res_init_flag, integer top_res_abs_0, boolean top_res_abs_1, boolean top_res_abs_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    top_usr_OK;

  predicate str_invariant(integer top_usr_Delta, boolean top_usr_OK, boolean top_res_init_flag, integer top_res_abs_0, boolean top_res_abs_1, boolean top_res_abs_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    ((top_res_abs_2 ==> ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20))) && (top_res_abs_1 == ((-1 <= top_usr_Delta) && (top_usr_Delta <= 1))) && (top_usr_OK == (top_res_abs_2 ==> ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20)))));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c___node_init_Sofar_0(_Bool Sofar_usr_X_a_0, _Bool Sofar_usr_Y_a_0, _Bool Sofar_res_init_flag_a_0) {
    return ((Sofar_usr_Y_a_0 == Sofar_usr_X_a_0) && Sofar_res_init_flag_a_0);
}

static inline _Bool c___node_trans_Sofar_0(_Bool Sofar_usr_X_a_1, _Bool Sofar_usr_Y_a_1, _Bool Sofar_res_init_flag_a_1, _Bool Sofar_usr_X_a_0, _Bool Sofar_usr_Y_a_0, _Bool Sofar_res_init_flag_a_0) {
    return ((Sofar_usr_Y_a_1 == (Sofar_usr_Y_a_0 && Sofar_usr_X_a_1)) && !(Sofar_res_init_flag_a_1));
}

static inline _Bool c___node_init_Store_0(long long Store_usr_Delta_a_0, long long Store_usr_Total_a_0, _Bool Store_res_init_flag_a_0) {
    return ((Store_usr_Total_a_0 == ((((Store_usr_Delta_a_0 < 0) && (0 > 0))) ? ((0 + Store_usr_Delta_a_0)) : (((((Store_usr_Delta_a_0 > 0) && (0 < 10))) ? ((0 + Store_usr_Delta_a_0)) : (0))))) && Store_res_init_flag_a_0);
}

static inline _Bool c___node_trans_Store_0(long long Store_usr_Delta_a_1, long long Store_usr_Total_a_1, _Bool Store_res_init_flag_a_1, long long Store_usr_Delta_a_0, long long Store_usr_Total_a_0, _Bool Store_res_init_flag_a_0) {
    return ((Store_usr_Total_a_1 == ((((Store_usr_Delta_a_1 < 0) && (Store_usr_Total_a_0 > 0))) ? ((Store_usr_Total_a_0 + Store_usr_Delta_a_1)) : (((((Store_usr_Delta_a_1 > 0) && (Store_usr_Total_a_0 < 10))) ? ((Store_usr_Total_a_0 + Store_usr_Delta_a_1)) : (Store_usr_Total_a_0))))) && !(Store_res_init_flag_a_1));
}

static inline _Bool c___node_init_top_0(long long top_usr_Delta_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, long long top_res_abs_0_a_0, _Bool top_res_abs_1_a_0, _Bool top_res_abs_2_a_0, _Bool top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_res_abs_1_a_0 == ((-1 <= top_usr_Delta_a_0) && (top_usr_Delta_a_0 <= 1))) && ((top_usr_OK_a_0 == (!(top_res_abs_2_a_0) || ((0 <= top_res_abs_0_a_0) && (top_res_abs_0_a_0 <= 20)))) && c___node_init_Store_0(top_usr_Delta_a_0, top_res_abs_0_a_0, top_res_inst_1_a_0) && c___node_init_Sofar_0(top_res_abs_1_a_0, top_res_abs_2_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));
}

static inline _Bool c___node_trans_top_0(long long top_usr_Delta_a_1, _Bool top_usr_OK_a_1, _Bool top_res_init_flag_a_1, long long top_res_abs_0_a_1, _Bool top_res_abs_1_a_1, _Bool top_res_abs_2_a_1, _Bool top_res_inst_1_a_1, _Bool top_res_inst_0_a_1, long long top_usr_Delta_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, long long top_res_abs_0_a_0, _Bool top_res_abs_1_a_0, _Bool top_res_abs_2_a_0, _Bool top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_res_abs_1_a_1 == ((-1 <= top_usr_Delta_a_1) && (top_usr_Delta_a_1 <= 1))) && ((top_usr_OK_a_1 == (!(top_res_abs_2_a_1) || ((0 <= top_res_abs_0_a_1) && (top_res_abs_0_a_1 <= 20)))) && c___node_trans_Store_0(top_usr_Delta_a_1, top_res_abs_0_a_1, top_res_inst_1_a_1, top_usr_Delta_a_0, top_res_abs_0_a_0, top_res_inst_1_a_0) && c___node_trans_Sofar_0(top_res_abs_1_a_1, top_res_abs_2_a_1, top_res_inst_0_a_1, top_res_abs_1_a_0, top_res_abs_2_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1)));
}

static inline _Bool c_init(long long top_usr_Delta, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return ((top_res_abs_1 == ((-1 <= top_usr_Delta) && (top_usr_Delta <= 1))) && ((top_usr_OK == (!(top_res_abs_2) || ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20)))) && c___node_init_Store_0(top_usr_Delta, top_res_abs_0, top_res_inst_1) && c___node_init_Sofar_0(top_res_abs_1, top_res_abs_2, top_res_inst_0) && top_res_init_flag));
}

static inline _Bool c_trans(long long top_usr_Delta, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_inst_1, _Bool top_res_inst_0, long long top_usr_Delta_next, _Bool top_usr_OK_next, _Bool top_res_init_flag_next, long long top_res_abs_0_next, _Bool top_res_abs_1_next, _Bool top_res_abs_2_next, _Bool top_res_inst_1_next, _Bool top_res_inst_0_next) {
    return ((top_res_abs_1_next == ((-1 <= top_usr_Delta_next) && (top_usr_Delta_next <= 1))) && ((top_usr_OK_next == (!(top_res_abs_2_next) || ((0 <= top_res_abs_0_next) && (top_res_abs_0_next <= 20)))) && c___node_trans_Store_0(top_usr_Delta_next, top_res_abs_0_next, top_res_inst_1_next, top_usr_Delta, top_res_abs_0, top_res_inst_1) && c___node_trans_Sofar_0(top_res_abs_1_next, top_res_abs_2_next, top_res_inst_0_next, top_res_abs_1, top_res_abs_2, top_res_inst_0) && !(top_res_init_flag_next)));
}

static inline _Bool c_prop(long long top_usr_Delta, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return top_usr_OK;
}

static inline _Bool c_str_invariant(long long top_usr_Delta, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return ((!(top_res_abs_2) || ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20))) && (top_res_abs_1 == ((-1 <= top_usr_Delta) && (top_usr_Delta <= 1))) && (top_usr_OK == (!(top_res_abs_2) || ((0 <= top_res_abs_0) && (top_res_abs_0 <= 20)))));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long top_usr_Delta = nondet_long();
    _Bool top_usr_OK = nondet_bool();
    _Bool top_res_init_flag = nondet_bool();
    long long top_res_abs_0 = nondet_long();
    _Bool top_res_abs_1 = nondet_bool();
    _Bool top_res_abs_2 = nondet_bool();
    _Bool top_res_inst_1 = nondet_bool();
    _Bool top_res_inst_0 = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_init(top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant str_invariant(top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0);
      @ loop assigns top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0;
      @*/
    while (1) {
        long long top_usr_Delta_next = nondet_long();
        _Bool top_usr_OK_next = nondet_bool();
        _Bool top_res_init_flag_next = nondet_bool();
        long long top_res_abs_0_next = nondet_long();
        _Bool top_res_abs_1_next = nondet_bool();
        _Bool top_res_abs_2_next = nondet_bool();
        _Bool top_res_inst_1_next = nondet_bool();
        _Bool top_res_inst_0_next = nondet_bool();

        if (!c_trans(top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0, top_usr_Delta_next, top_usr_OK_next, top_res_init_flag_next, top_res_abs_0_next, top_res_abs_1_next, top_res_abs_2_next, top_res_inst_1_next, top_res_inst_0_next)) break;

        // State updates
        top_usr_Delta = top_usr_Delta_next;
        top_usr_OK = top_usr_OK_next;
        top_res_init_flag = top_res_init_flag_next;
        top_res_abs_0 = top_res_abs_0_next;
        top_res_abs_1 = top_res_abs_1_next;
        top_res_abs_2 = top_res_abs_2_next;
        top_res_inst_1 = top_res_inst_1_next;
        top_res_inst_0 = top_res_inst_0_next;
    }

    // 4. Post-condition assertion
    assert(c_prop(top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0));
    /*@ assert prop(top_usr_Delta, top_usr_OK, top_res_init_flag, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_inst_1, top_res_inst_0); */

    return 0;
}
