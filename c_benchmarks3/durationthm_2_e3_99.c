/*
 * Generated C verification file from: durationthm_2_e3_99.sl
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
  predicate __node_init_Age_0(boolean Age_usr_p_a_0, integer Age_usr_age_of_p_a_0, boolean Age_res_init_flag_a_0) =
    ((Age_usr_age_of_p_a_0 == 0) && Age_res_init_flag_a_0);

  predicate __node_trans_Age_0(boolean Age_usr_p_a_1, integer Age_usr_age_of_p_a_1, boolean Age_res_init_flag_a_1, boolean Age_usr_p_a_0, integer Age_usr_age_of_p_a_0, boolean Age_res_init_flag_a_0) =
    ((Age_usr_age_of_p_a_1 == ((Age_usr_p_a_0) ? ((Age_usr_age_of_p_a_0 - 1)) : (0))) && !(Age_res_init_flag_a_1));

  predicate __node_init_Sofar_0(boolean Sofar_usr_X_a_0, boolean Sofar_usr_Sofar_a_0, boolean Sofar_res_init_flag_a_0) =
    ((Sofar_usr_Sofar_a_0 == Sofar_usr_X_a_0) && Sofar_res_init_flag_a_0);

  predicate __node_trans_Sofar_0(boolean Sofar_usr_X_a_1, boolean Sofar_usr_Sofar_a_1, boolean Sofar_res_init_flag_a_1, boolean Sofar_usr_X_a_0, boolean Sofar_usr_Sofar_a_0, boolean Sofar_res_init_flag_a_0) =
    ((Sofar_usr_Sofar_a_1 == (Sofar_usr_X_a_1 && Sofar_usr_Sofar_a_0)) && !(Sofar_res_init_flag_a_1));

  predicate __node_init_top_0(integer top_usr_k0_a_0, boolean top_usr_p_a_0, boolean top_usr_q_a_0, boolean top_usr_r_a_0, boolean top_usr_t_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, integer top_impl_usr_k_a_0, integer top_res_abs_0_a_0, integer top_res_abs_1_a_0, boolean top_res_abs_2_a_0, boolean top_res_abs_3_a_0, boolean top_res_abs_4_a_0, integer top_res_abs_5_a_0, boolean top_res_inst_3_a_0, boolean top_res_inst_2_a_0, boolean top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_impl_usr_k_a_0 == top_usr_k0_a_0) && (top_res_abs_2_a_0 == (((top_impl_usr_k_a_0 >= 1) && ((top_res_abs_0_a_0 >= top_impl_usr_k_a_0) ==> top_usr_q_a_0)) && ((top_res_abs_1_a_0 >= top_impl_usr_k_a_0) ==> top_usr_t_a_0))) && ((top_usr_OK_a_0 == (top_res_abs_3_a_0 ==> ((top_res_abs_5_a_0 >= top_impl_usr_k_a_0) ==> (top_usr_q_a_0 && top_usr_t_a_0)))) && (top_res_abs_4_a_0 == (top_usr_p_a_0 && top_usr_r_a_0)) && __node_init_Sofar_0(top_res_abs_2_a_0, top_res_abs_3_a_0, top_res_inst_3_a_0) && __node_init_Age_0(top_usr_p_a_0, top_res_abs_0_a_0, top_res_inst_2_a_0) && __node_init_Age_0(top_usr_r_a_0, top_res_abs_1_a_0, top_res_inst_1_a_0) && __node_init_Age_0(top_res_abs_4_a_0, top_res_abs_5_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));

  predicate __node_trans_top_0(integer top_usr_k0_a_1, boolean top_usr_p_a_1, boolean top_usr_q_a_1, boolean top_usr_r_a_1, boolean top_usr_t_a_1, boolean top_usr_OK_a_1, boolean top_res_init_flag_a_1, integer top_impl_usr_k_a_1, integer top_res_abs_0_a_1, integer top_res_abs_1_a_1, boolean top_res_abs_2_a_1, boolean top_res_abs_3_a_1, boolean top_res_abs_4_a_1, integer top_res_abs_5_a_1, boolean top_res_inst_3_a_1, boolean top_res_inst_2_a_1, boolean top_res_inst_1_a_1, boolean top_res_inst_0_a_1, integer top_usr_k0_a_0, boolean top_usr_p_a_0, boolean top_usr_q_a_0, boolean top_usr_r_a_0, boolean top_usr_t_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, integer top_impl_usr_k_a_0, integer top_res_abs_0_a_0, integer top_res_abs_1_a_0, boolean top_res_abs_2_a_0, boolean top_res_abs_3_a_0, boolean top_res_abs_4_a_0, integer top_res_abs_5_a_0, boolean top_res_inst_3_a_0, boolean top_res_inst_2_a_0, boolean top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_impl_usr_k_a_1 == top_impl_usr_k_a_0) && (top_res_abs_2_a_1 == (((top_impl_usr_k_a_1 >= 1) && ((top_res_abs_0_a_1 >= top_impl_usr_k_a_1) ==> top_usr_q_a_1)) && ((top_res_abs_1_a_1 >= top_impl_usr_k_a_1) ==> top_usr_t_a_1))) && ((top_usr_OK_a_1 == (top_res_abs_3_a_1 ==> ((top_res_abs_5_a_1 >= top_impl_usr_k_a_1) ==> (top_usr_q_a_1 && top_usr_t_a_1)))) && (top_res_abs_4_a_1 == (top_usr_p_a_1 && top_usr_r_a_1)) && __node_trans_Sofar_0(top_res_abs_2_a_1, top_res_abs_3_a_1, top_res_inst_3_a_1, top_res_abs_2_a_0, top_res_abs_3_a_0, top_res_inst_3_a_0) && __node_trans_Age_0(top_usr_p_a_1, top_res_abs_0_a_1, top_res_inst_2_a_1, top_usr_p_a_0, top_res_abs_0_a_0, top_res_inst_2_a_0) && __node_trans_Age_0(top_usr_r_a_1, top_res_abs_1_a_1, top_res_inst_1_a_1, top_usr_r_a_0, top_res_abs_1_a_0, top_res_inst_1_a_0) && __node_trans_Age_0(top_res_abs_4_a_1, top_res_abs_5_a_1, top_res_inst_0_a_1, top_res_abs_4_a_0, top_res_abs_5_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1)));

  predicate init(integer top_usr_k0, boolean top_usr_p, boolean top_usr_q, boolean top_usr_r, boolean top_usr_t, boolean top_usr_OK, boolean top_res_init_flag, integer top_impl_usr_k, integer top_res_abs_0, integer top_res_abs_1, boolean top_res_abs_2, boolean top_res_abs_3, boolean top_res_abs_4, integer top_res_abs_5, boolean top_res_inst_3, boolean top_res_inst_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    ((top_impl_usr_k == top_usr_k0) && (top_res_abs_2 == (((top_impl_usr_k >= 1) && ((top_res_abs_0 >= top_impl_usr_k) ==> top_usr_q)) && ((top_res_abs_1 >= top_impl_usr_k) ==> top_usr_t))) && ((top_usr_OK == (top_res_abs_3 ==> ((top_res_abs_5 >= top_impl_usr_k) ==> (top_usr_q && top_usr_t)))) && (top_res_abs_4 == (top_usr_p && top_usr_r)) && __node_init_Sofar_0(top_res_abs_2, top_res_abs_3, top_res_inst_3) && __node_init_Age_0(top_usr_p, top_res_abs_0, top_res_inst_2) && __node_init_Age_0(top_usr_r, top_res_abs_1, top_res_inst_1) && __node_init_Age_0(top_res_abs_4, top_res_abs_5, top_res_inst_0) && top_res_init_flag));

  predicate trans(integer top_usr_k0, boolean top_usr_p, boolean top_usr_q, boolean top_usr_r, boolean top_usr_t, boolean top_usr_OK, boolean top_res_init_flag, integer top_impl_usr_k, integer top_res_abs_0, integer top_res_abs_1, boolean top_res_abs_2, boolean top_res_abs_3, boolean top_res_abs_4, integer top_res_abs_5, boolean top_res_inst_3, boolean top_res_inst_2, boolean top_res_inst_1, boolean top_res_inst_0, integer top_usr_k0_next, boolean top_usr_p_next, boolean top_usr_q_next, boolean top_usr_r_next, boolean top_usr_t_next, boolean top_usr_OK_next, boolean top_res_init_flag_next, integer top_impl_usr_k_next, integer top_res_abs_0_next, integer top_res_abs_1_next, boolean top_res_abs_2_next, boolean top_res_abs_3_next, boolean top_res_abs_4_next, integer top_res_abs_5_next, boolean top_res_inst_3_next, boolean top_res_inst_2_next, boolean top_res_inst_1_next, boolean top_res_inst_0_next) =
    ((top_impl_usr_k_next == top_impl_usr_k) && (top_res_abs_2_next == (((top_impl_usr_k_next >= 1) && ((top_res_abs_0_next >= top_impl_usr_k_next) ==> top_usr_q_next)) && ((top_res_abs_1_next >= top_impl_usr_k_next) ==> top_usr_t_next))) && ((top_usr_OK_next == (top_res_abs_3_next ==> ((top_res_abs_5_next >= top_impl_usr_k_next) ==> (top_usr_q_next && top_usr_t_next)))) && (top_res_abs_4_next == (top_usr_p_next && top_usr_r_next)) && __node_trans_Sofar_0(top_res_abs_2_next, top_res_abs_3_next, top_res_inst_3_next, top_res_abs_2, top_res_abs_3, top_res_inst_3) && __node_trans_Age_0(top_usr_p_next, top_res_abs_0_next, top_res_inst_2_next, top_usr_p, top_res_abs_0, top_res_inst_2) && __node_trans_Age_0(top_usr_r_next, top_res_abs_1_next, top_res_inst_1_next, top_usr_r, top_res_abs_1, top_res_inst_1) && __node_trans_Age_0(top_res_abs_4_next, top_res_abs_5_next, top_res_inst_0_next, top_res_abs_4, top_res_abs_5, top_res_inst_0) && !(top_res_init_flag_next)));

  predicate prop(integer top_usr_k0, boolean top_usr_p, boolean top_usr_q, boolean top_usr_r, boolean top_usr_t, boolean top_usr_OK, boolean top_res_init_flag, integer top_impl_usr_k, integer top_res_abs_0, integer top_res_abs_1, boolean top_res_abs_2, boolean top_res_abs_3, boolean top_res_abs_4, integer top_res_abs_5, boolean top_res_inst_3, boolean top_res_inst_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    top_usr_OK;

  predicate str_invariant(integer top_usr_k0, boolean top_usr_p, boolean top_usr_q, boolean top_usr_r, boolean top_usr_t, boolean top_usr_OK, boolean top_res_init_flag, integer top_impl_usr_k, integer top_res_abs_0, integer top_res_abs_1, boolean top_res_abs_2, boolean top_res_abs_3, boolean top_res_abs_4, integer top_res_abs_5, boolean top_res_inst_3, boolean top_res_inst_2, boolean top_res_inst_1, boolean top_res_inst_0) =
    (top_usr_OK && (1 >= top_res_abs_5));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c___node_init_Age_0(_Bool Age_usr_p_a_0, long long Age_usr_age_of_p_a_0, _Bool Age_res_init_flag_a_0) {
    return ((Age_usr_age_of_p_a_0 == 0) && Age_res_init_flag_a_0);
}

static inline _Bool c___node_trans_Age_0(_Bool Age_usr_p_a_1, long long Age_usr_age_of_p_a_1, _Bool Age_res_init_flag_a_1, _Bool Age_usr_p_a_0, long long Age_usr_age_of_p_a_0, _Bool Age_res_init_flag_a_0) {
    return ((Age_usr_age_of_p_a_1 == ((Age_usr_p_a_0) ? ((Age_usr_age_of_p_a_0 - 1)) : (0))) && !(Age_res_init_flag_a_1));
}

static inline _Bool c___node_init_Sofar_0(_Bool Sofar_usr_X_a_0, _Bool Sofar_usr_Sofar_a_0, _Bool Sofar_res_init_flag_a_0) {
    return ((Sofar_usr_Sofar_a_0 == Sofar_usr_X_a_0) && Sofar_res_init_flag_a_0);
}

static inline _Bool c___node_trans_Sofar_0(_Bool Sofar_usr_X_a_1, _Bool Sofar_usr_Sofar_a_1, _Bool Sofar_res_init_flag_a_1, _Bool Sofar_usr_X_a_0, _Bool Sofar_usr_Sofar_a_0, _Bool Sofar_res_init_flag_a_0) {
    return ((Sofar_usr_Sofar_a_1 == (Sofar_usr_X_a_1 && Sofar_usr_Sofar_a_0)) && !(Sofar_res_init_flag_a_1));
}

static inline _Bool c___node_init_top_0(long long top_usr_k0_a_0, _Bool top_usr_p_a_0, _Bool top_usr_q_a_0, _Bool top_usr_r_a_0, _Bool top_usr_t_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, long long top_impl_usr_k_a_0, long long top_res_abs_0_a_0, long long top_res_abs_1_a_0, _Bool top_res_abs_2_a_0, _Bool top_res_abs_3_a_0, _Bool top_res_abs_4_a_0, long long top_res_abs_5_a_0, _Bool top_res_inst_3_a_0, _Bool top_res_inst_2_a_0, _Bool top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_impl_usr_k_a_0 == top_usr_k0_a_0) && (top_res_abs_2_a_0 == (((top_impl_usr_k_a_0 >= 1) && (!((top_res_abs_0_a_0 >= top_impl_usr_k_a_0)) || top_usr_q_a_0)) && (!((top_res_abs_1_a_0 >= top_impl_usr_k_a_0)) || top_usr_t_a_0))) && ((top_usr_OK_a_0 == (!(top_res_abs_3_a_0) || (!((top_res_abs_5_a_0 >= top_impl_usr_k_a_0)) || (top_usr_q_a_0 && top_usr_t_a_0)))) && (top_res_abs_4_a_0 == (top_usr_p_a_0 && top_usr_r_a_0)) && c___node_init_Sofar_0(top_res_abs_2_a_0, top_res_abs_3_a_0, top_res_inst_3_a_0) && c___node_init_Age_0(top_usr_p_a_0, top_res_abs_0_a_0, top_res_inst_2_a_0) && c___node_init_Age_0(top_usr_r_a_0, top_res_abs_1_a_0, top_res_inst_1_a_0) && c___node_init_Age_0(top_res_abs_4_a_0, top_res_abs_5_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));
}

static inline _Bool c___node_trans_top_0(long long top_usr_k0_a_1, _Bool top_usr_p_a_1, _Bool top_usr_q_a_1, _Bool top_usr_r_a_1, _Bool top_usr_t_a_1, _Bool top_usr_OK_a_1, _Bool top_res_init_flag_a_1, long long top_impl_usr_k_a_1, long long top_res_abs_0_a_1, long long top_res_abs_1_a_1, _Bool top_res_abs_2_a_1, _Bool top_res_abs_3_a_1, _Bool top_res_abs_4_a_1, long long top_res_abs_5_a_1, _Bool top_res_inst_3_a_1, _Bool top_res_inst_2_a_1, _Bool top_res_inst_1_a_1, _Bool top_res_inst_0_a_1, long long top_usr_k0_a_0, _Bool top_usr_p_a_0, _Bool top_usr_q_a_0, _Bool top_usr_r_a_0, _Bool top_usr_t_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, long long top_impl_usr_k_a_0, long long top_res_abs_0_a_0, long long top_res_abs_1_a_0, _Bool top_res_abs_2_a_0, _Bool top_res_abs_3_a_0, _Bool top_res_abs_4_a_0, long long top_res_abs_5_a_0, _Bool top_res_inst_3_a_0, _Bool top_res_inst_2_a_0, _Bool top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_impl_usr_k_a_1 == top_impl_usr_k_a_0) && (top_res_abs_2_a_1 == (((top_impl_usr_k_a_1 >= 1) && (!((top_res_abs_0_a_1 >= top_impl_usr_k_a_1)) || top_usr_q_a_1)) && (!((top_res_abs_1_a_1 >= top_impl_usr_k_a_1)) || top_usr_t_a_1))) && ((top_usr_OK_a_1 == (!(top_res_abs_3_a_1) || (!((top_res_abs_5_a_1 >= top_impl_usr_k_a_1)) || (top_usr_q_a_1 && top_usr_t_a_1)))) && (top_res_abs_4_a_1 == (top_usr_p_a_1 && top_usr_r_a_1)) && c___node_trans_Sofar_0(top_res_abs_2_a_1, top_res_abs_3_a_1, top_res_inst_3_a_1, top_res_abs_2_a_0, top_res_abs_3_a_0, top_res_inst_3_a_0) && c___node_trans_Age_0(top_usr_p_a_1, top_res_abs_0_a_1, top_res_inst_2_a_1, top_usr_p_a_0, top_res_abs_0_a_0, top_res_inst_2_a_0) && c___node_trans_Age_0(top_usr_r_a_1, top_res_abs_1_a_1, top_res_inst_1_a_1, top_usr_r_a_0, top_res_abs_1_a_0, top_res_inst_1_a_0) && c___node_trans_Age_0(top_res_abs_4_a_1, top_res_abs_5_a_1, top_res_inst_0_a_1, top_res_abs_4_a_0, top_res_abs_5_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1)));
}

static inline _Bool c_init(long long top_usr_k0, _Bool top_usr_p, _Bool top_usr_q, _Bool top_usr_r, _Bool top_usr_t, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_impl_usr_k, long long top_res_abs_0, long long top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_abs_3, _Bool top_res_abs_4, long long top_res_abs_5, _Bool top_res_inst_3, _Bool top_res_inst_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return ((top_impl_usr_k == top_usr_k0) && (top_res_abs_2 == (((top_impl_usr_k >= 1) && (!((top_res_abs_0 >= top_impl_usr_k)) || top_usr_q)) && (!((top_res_abs_1 >= top_impl_usr_k)) || top_usr_t))) && ((top_usr_OK == (!(top_res_abs_3) || (!((top_res_abs_5 >= top_impl_usr_k)) || (top_usr_q && top_usr_t)))) && (top_res_abs_4 == (top_usr_p && top_usr_r)) && c___node_init_Sofar_0(top_res_abs_2, top_res_abs_3, top_res_inst_3) && c___node_init_Age_0(top_usr_p, top_res_abs_0, top_res_inst_2) && c___node_init_Age_0(top_usr_r, top_res_abs_1, top_res_inst_1) && c___node_init_Age_0(top_res_abs_4, top_res_abs_5, top_res_inst_0) && top_res_init_flag));
}

static inline _Bool c_trans(long long top_usr_k0, _Bool top_usr_p, _Bool top_usr_q, _Bool top_usr_r, _Bool top_usr_t, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_impl_usr_k, long long top_res_abs_0, long long top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_abs_3, _Bool top_res_abs_4, long long top_res_abs_5, _Bool top_res_inst_3, _Bool top_res_inst_2, _Bool top_res_inst_1, _Bool top_res_inst_0, long long top_usr_k0_next, _Bool top_usr_p_next, _Bool top_usr_q_next, _Bool top_usr_r_next, _Bool top_usr_t_next, _Bool top_usr_OK_next, _Bool top_res_init_flag_next, long long top_impl_usr_k_next, long long top_res_abs_0_next, long long top_res_abs_1_next, _Bool top_res_abs_2_next, _Bool top_res_abs_3_next, _Bool top_res_abs_4_next, long long top_res_abs_5_next, _Bool top_res_inst_3_next, _Bool top_res_inst_2_next, _Bool top_res_inst_1_next, _Bool top_res_inst_0_next) {
    return ((top_impl_usr_k_next == top_impl_usr_k) && (top_res_abs_2_next == (((top_impl_usr_k_next >= 1) && (!((top_res_abs_0_next >= top_impl_usr_k_next)) || top_usr_q_next)) && (!((top_res_abs_1_next >= top_impl_usr_k_next)) || top_usr_t_next))) && ((top_usr_OK_next == (!(top_res_abs_3_next) || (!((top_res_abs_5_next >= top_impl_usr_k_next)) || (top_usr_q_next && top_usr_t_next)))) && (top_res_abs_4_next == (top_usr_p_next && top_usr_r_next)) && c___node_trans_Sofar_0(top_res_abs_2_next, top_res_abs_3_next, top_res_inst_3_next, top_res_abs_2, top_res_abs_3, top_res_inst_3) && c___node_trans_Age_0(top_usr_p_next, top_res_abs_0_next, top_res_inst_2_next, top_usr_p, top_res_abs_0, top_res_inst_2) && c___node_trans_Age_0(top_usr_r_next, top_res_abs_1_next, top_res_inst_1_next, top_usr_r, top_res_abs_1, top_res_inst_1) && c___node_trans_Age_0(top_res_abs_4_next, top_res_abs_5_next, top_res_inst_0_next, top_res_abs_4, top_res_abs_5, top_res_inst_0) && !(top_res_init_flag_next)));
}

static inline _Bool c_prop(long long top_usr_k0, _Bool top_usr_p, _Bool top_usr_q, _Bool top_usr_r, _Bool top_usr_t, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_impl_usr_k, long long top_res_abs_0, long long top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_abs_3, _Bool top_res_abs_4, long long top_res_abs_5, _Bool top_res_inst_3, _Bool top_res_inst_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return top_usr_OK;
}

static inline _Bool c_str_invariant(long long top_usr_k0, _Bool top_usr_p, _Bool top_usr_q, _Bool top_usr_r, _Bool top_usr_t, _Bool top_usr_OK, _Bool top_res_init_flag, long long top_impl_usr_k, long long top_res_abs_0, long long top_res_abs_1, _Bool top_res_abs_2, _Bool top_res_abs_3, _Bool top_res_abs_4, long long top_res_abs_5, _Bool top_res_inst_3, _Bool top_res_inst_2, _Bool top_res_inst_1, _Bool top_res_inst_0) {
    return (top_usr_OK && (1 >= top_res_abs_5));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    long long top_usr_k0 = nondet_long();
    _Bool top_usr_p = nondet_bool();
    _Bool top_usr_q = nondet_bool();
    _Bool top_usr_r = nondet_bool();
    _Bool top_usr_t = nondet_bool();
    _Bool top_usr_OK = nondet_bool();
    _Bool top_res_init_flag = nondet_bool();
    long long top_impl_usr_k = nondet_long();
    long long top_res_abs_0 = nondet_long();
    long long top_res_abs_1 = nondet_long();
    _Bool top_res_abs_2 = nondet_bool();
    _Bool top_res_abs_3 = nondet_bool();
    _Bool top_res_abs_4 = nondet_bool();
    long long top_res_abs_5 = nondet_long();
    _Bool top_res_inst_3 = nondet_bool();
    _Bool top_res_inst_2 = nondet_bool();
    _Bool top_res_inst_1 = nondet_bool();
    _Bool top_res_inst_0 = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_init(top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant str_invariant(top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0);
      @ loop assigns top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0;
      @*/
    while (1) {
        long long top_usr_k0_next = nondet_long();
        _Bool top_usr_p_next = nondet_bool();
        _Bool top_usr_q_next = nondet_bool();
        _Bool top_usr_r_next = nondet_bool();
        _Bool top_usr_t_next = nondet_bool();
        _Bool top_usr_OK_next = nondet_bool();
        _Bool top_res_init_flag_next = nondet_bool();
        long long top_impl_usr_k_next = nondet_long();
        long long top_res_abs_0_next = nondet_long();
        long long top_res_abs_1_next = nondet_long();
        _Bool top_res_abs_2_next = nondet_bool();
        _Bool top_res_abs_3_next = nondet_bool();
        _Bool top_res_abs_4_next = nondet_bool();
        long long top_res_abs_5_next = nondet_long();
        _Bool top_res_inst_3_next = nondet_bool();
        _Bool top_res_inst_2_next = nondet_bool();
        _Bool top_res_inst_1_next = nondet_bool();
        _Bool top_res_inst_0_next = nondet_bool();

        if (!c_trans(top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0, top_usr_k0_next, top_usr_p_next, top_usr_q_next, top_usr_r_next, top_usr_t_next, top_usr_OK_next, top_res_init_flag_next, top_impl_usr_k_next, top_res_abs_0_next, top_res_abs_1_next, top_res_abs_2_next, top_res_abs_3_next, top_res_abs_4_next, top_res_abs_5_next, top_res_inst_3_next, top_res_inst_2_next, top_res_inst_1_next, top_res_inst_0_next)) break;

        // State updates
        top_usr_k0 = top_usr_k0_next;
        top_usr_p = top_usr_p_next;
        top_usr_q = top_usr_q_next;
        top_usr_r = top_usr_r_next;
        top_usr_t = top_usr_t_next;
        top_usr_OK = top_usr_OK_next;
        top_res_init_flag = top_res_init_flag_next;
        top_impl_usr_k = top_impl_usr_k_next;
        top_res_abs_0 = top_res_abs_0_next;
        top_res_abs_1 = top_res_abs_1_next;
        top_res_abs_2 = top_res_abs_2_next;
        top_res_abs_3 = top_res_abs_3_next;
        top_res_abs_4 = top_res_abs_4_next;
        top_res_abs_5 = top_res_abs_5_next;
        top_res_inst_3 = top_res_inst_3_next;
        top_res_inst_2 = top_res_inst_2_next;
        top_res_inst_1 = top_res_inst_1_next;
        top_res_inst_0 = top_res_inst_0_next;
    }

    // 4. Post-condition assertion
    assert(c_prop(top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0));
    /*@ assert prop(top_usr_k0, top_usr_p, top_usr_q, top_usr_r, top_usr_t, top_usr_OK, top_res_init_flag, top_impl_usr_k, top_res_abs_0, top_res_abs_1, top_res_abs_2, top_res_abs_3, top_res_abs_4, top_res_abs_5, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0); */

    return 0;
}
