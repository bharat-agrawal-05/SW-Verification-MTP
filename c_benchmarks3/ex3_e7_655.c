/*
 * Generated C verification file from: ex3_e7_655.sl
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
  predicate __node_init_COUNTER_0(integer COUNTER_usr_init_a_0, integer COUNTER_usr_incr_a_0, boolean COUNTER_usr_X_a_0, boolean COUNTER_usr_reset_a_0, integer COUNTER_usr_C_a_0, boolean COUNTER_res_init_flag_a_0) =
    ((COUNTER_usr_C_a_0 == ((COUNTER_usr_reset_a_0) ? (COUNTER_usr_init_a_0) : (((COUNTER_usr_X_a_0) ? ((COUNTER_usr_init_a_0 + COUNTER_usr_incr_a_0)) : (COUNTER_usr_init_a_0))))) && COUNTER_res_init_flag_a_0);

  predicate __node_trans_COUNTER_0(integer COUNTER_usr_init_a_1, integer COUNTER_usr_incr_a_1, boolean COUNTER_usr_X_a_1, boolean COUNTER_usr_reset_a_1, integer COUNTER_usr_C_a_1, boolean COUNTER_res_init_flag_a_1, integer COUNTER_usr_init_a_0, integer COUNTER_usr_incr_a_0, boolean COUNTER_usr_X_a_0, boolean COUNTER_usr_reset_a_0, integer COUNTER_usr_C_a_0, boolean COUNTER_res_init_flag_a_0) =
    ((COUNTER_usr_C_a_1 == ((COUNTER_usr_reset_a_1) ? (COUNTER_usr_init_a_1) : (((COUNTER_usr_X_a_1) ? ((COUNTER_usr_C_a_0 + COUNTER_usr_incr_a_1)) : (COUNTER_usr_C_a_0))))) && !(COUNTER_res_init_flag_a_1));

  predicate __node_init_speed_0(boolean speed_usr_beacon_a_0, boolean speed_usr_second_a_0, boolean speed_usr_late_a_0, boolean speed_usr_early_a_0, boolean speed_res_init_flag_a_0, integer speed_impl_usr_incr_a_0, integer speed_res_abs_0_a_0, boolean speed_res_abs_1_a_0, boolean speed_res_abs_2_a_0, integer speed_res_abs_3_a_0, boolean speed_res_inst_0_a_0) =
    ((speed_usr_late_a_0 == \false) && (speed_res_abs_2_a_0 == \false) && (speed_res_abs_1_a_0 == (speed_usr_beacon_a_0 || speed_usr_second_a_0)) && (speed_res_abs_0_a_0 == 0) && (speed_impl_usr_incr_a_0 == (((speed_usr_beacon_a_0 || !(speed_usr_second_a_0))) ? (1) : ((((speed_usr_second_a_0 && !(speed_usr_beacon_a_0))) ? (2) : (0))))) && ((speed_usr_early_a_0 == \false) && __node_init_COUNTER_0(speed_res_abs_0_a_0, speed_impl_usr_incr_a_0, speed_res_abs_1_a_0, speed_res_abs_2_a_0, speed_res_abs_3_a_0, speed_res_inst_0_a_0) && ((0 <= speed_res_abs_0_a_0) && (speed_res_abs_0_a_0 <= 0)) && ((0 <= speed_impl_usr_incr_a_0) && (speed_impl_usr_incr_a_0 <= 2)) && speed_res_init_flag_a_0));

  predicate __node_trans_speed_0(boolean speed_usr_beacon_a_1, boolean speed_usr_second_a_1, boolean speed_usr_late_a_1, boolean speed_usr_early_a_1, boolean speed_res_init_flag_a_1, integer speed_impl_usr_incr_a_1, integer speed_res_abs_0_a_1, boolean speed_res_abs_1_a_1, boolean speed_res_abs_2_a_1, integer speed_res_abs_3_a_1, boolean speed_res_inst_0_a_1, boolean speed_usr_beacon_a_0, boolean speed_usr_second_a_0, boolean speed_usr_late_a_0, boolean speed_usr_early_a_0, boolean speed_res_init_flag_a_0, integer speed_impl_usr_incr_a_0, integer speed_res_abs_0_a_0, boolean speed_res_abs_1_a_0, boolean speed_res_abs_2_a_0, integer speed_res_abs_3_a_0, boolean speed_res_inst_0_a_0) =
    ((speed_res_abs_2_a_1 == \false) && (speed_res_abs_1_a_1 == (speed_usr_beacon_a_1 || speed_usr_second_a_1)) && (speed_res_abs_0_a_1 == 0) && (speed_impl_usr_incr_a_1 == (((speed_usr_beacon_a_1 || !(speed_usr_second_a_1))) ? (1) : ((((speed_usr_second_a_1 && !(speed_usr_beacon_a_1))) ? (2) : (0))))) && ((speed_usr_late_a_1 == ((speed_usr_late_a_0) ? ((speed_res_abs_3_a_1 < 0)) : ((speed_res_abs_3_a_1 <= -10)))) && (speed_usr_early_a_1 == ((speed_usr_early_a_0) ? ((speed_res_abs_3_a_1 > 0)) : ((speed_res_abs_3_a_1 >= 10)))) && __node_trans_COUNTER_0(speed_res_abs_0_a_1, speed_impl_usr_incr_a_1, speed_res_abs_1_a_1, speed_res_abs_2_a_1, speed_res_abs_3_a_1, speed_res_inst_0_a_1, speed_res_abs_0_a_0, speed_impl_usr_incr_a_0, speed_res_abs_1_a_0, speed_res_abs_2_a_0, speed_res_abs_3_a_0, speed_res_inst_0_a_0) && ((0 <= speed_res_abs_0_a_1) && (speed_res_abs_0_a_1 <= 0)) && ((0 <= speed_impl_usr_incr_a_1) && (speed_impl_usr_incr_a_1 <= 2)) && !(speed_res_init_flag_a_1)));

  predicate __node_init_top_0(boolean top_usr_beacon_a_0, boolean top_usr_second_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, boolean top_impl_usr_early_a_0, boolean top_res_abs_0_a_0, boolean top_res_abs_1_a_0, boolean top_res_inst_6_a_0, integer top_res_inst_5_a_0, integer top_res_inst_4_a_0, boolean top_res_inst_3_a_0, boolean top_res_inst_2_a_0, integer top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_usr_OK_a_0 == \true) && ((top_impl_usr_early_a_0 == top_res_abs_1_a_0) && __node_init_speed_0(top_usr_beacon_a_0, top_usr_second_a_0, top_res_abs_0_a_0, top_res_abs_1_a_0, top_res_inst_6_a_0, top_res_inst_5_a_0, top_res_inst_4_a_0, top_res_inst_3_a_0, top_res_inst_2_a_0, top_res_inst_1_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));

  predicate __node_trans_top_0(boolean top_usr_beacon_a_1, boolean top_usr_second_a_1, boolean top_usr_OK_a_1, boolean top_res_init_flag_a_1, boolean top_impl_usr_early_a_1, boolean top_res_abs_0_a_1, boolean top_res_abs_1_a_1, boolean top_res_inst_6_a_1, integer top_res_inst_5_a_1, integer top_res_inst_4_a_1, boolean top_res_inst_3_a_1, boolean top_res_inst_2_a_1, integer top_res_inst_1_a_1, boolean top_res_inst_0_a_1, boolean top_usr_beacon_a_0, boolean top_usr_second_a_0, boolean top_usr_OK_a_0, boolean top_res_init_flag_a_0, boolean top_impl_usr_early_a_0, boolean top_res_abs_0_a_0, boolean top_res_abs_1_a_0, boolean top_res_inst_6_a_0, integer top_res_inst_5_a_0, integer top_res_inst_4_a_0, boolean top_res_inst_3_a_0, boolean top_res_inst_2_a_0, integer top_res_inst_1_a_0, boolean top_res_inst_0_a_0) =
    ((top_usr_OK_a_1 == (!(top_impl_usr_early_a_0) || !(top_res_abs_0_a_1))) && (top_impl_usr_early_a_1 == top_res_abs_1_a_1) && __node_trans_speed_0(top_usr_beacon_a_1, top_usr_second_a_1, top_res_abs_0_a_1, top_res_abs_1_a_1, top_res_inst_6_a_1, top_res_inst_5_a_1, top_res_inst_4_a_1, top_res_inst_3_a_1, top_res_inst_2_a_1, top_res_inst_1_a_1, top_res_inst_0_a_1, top_usr_beacon_a_0, top_usr_second_a_0, top_res_abs_0_a_0, top_res_abs_1_a_0, top_res_inst_6_a_0, top_res_inst_5_a_0, top_res_inst_4_a_0, top_res_inst_3_a_0, top_res_inst_2_a_0, top_res_inst_1_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1));

  predicate init(boolean top_usr_beacon, boolean top_usr_second, boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_early, boolean top_res_abs_0, boolean top_res_abs_1, boolean top_res_inst_6, integer top_res_inst_5, integer top_res_inst_4, boolean top_res_inst_3, boolean top_res_inst_2, integer top_res_inst_1, boolean top_res_inst_0) =
    ((top_usr_OK == \true) && ((top_impl_usr_early == top_res_abs_1) && __node_init_speed_0(top_usr_beacon, top_usr_second, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0) && top_res_init_flag));

  predicate trans(boolean top_usr_beacon, boolean top_usr_second, boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_early, boolean top_res_abs_0, boolean top_res_abs_1, boolean top_res_inst_6, integer top_res_inst_5, integer top_res_inst_4, boolean top_res_inst_3, boolean top_res_inst_2, integer top_res_inst_1, boolean top_res_inst_0, boolean top_usr_beacon_next, boolean top_usr_second_next, boolean top_usr_OK_next, boolean top_res_init_flag_next, boolean top_impl_usr_early_next, boolean top_res_abs_0_next, boolean top_res_abs_1_next, boolean top_res_inst_6_next, integer top_res_inst_5_next, integer top_res_inst_4_next, boolean top_res_inst_3_next, boolean top_res_inst_2_next, integer top_res_inst_1_next, boolean top_res_inst_0_next) =
    ((top_usr_OK_next == (!(top_impl_usr_early) || !(top_res_abs_0_next))) && (top_impl_usr_early_next == top_res_abs_1_next) && __node_trans_speed_0(top_usr_beacon_next, top_usr_second_next, top_res_abs_0_next, top_res_abs_1_next, top_res_inst_6_next, top_res_inst_5_next, top_res_inst_4_next, top_res_inst_3_next, top_res_inst_2_next, top_res_inst_1_next, top_res_inst_0_next, top_usr_beacon, top_usr_second, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0) && !(top_res_init_flag_next));

  predicate prop(boolean top_usr_beacon, boolean top_usr_second, boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_early, boolean top_res_abs_0, boolean top_res_abs_1, boolean top_res_inst_6, integer top_res_inst_5, integer top_res_inst_4, boolean top_res_inst_3, boolean top_res_inst_2, integer top_res_inst_1, boolean top_res_inst_0) =
    top_usr_OK;

  predicate str_invariant(boolean top_usr_beacon, boolean top_usr_second, boolean top_usr_OK, boolean top_res_init_flag, boolean top_impl_usr_early, boolean top_res_abs_0, boolean top_res_abs_1, boolean top_res_inst_6, integer top_res_inst_5, integer top_res_inst_4, boolean top_res_inst_3, boolean top_res_inst_2, integer top_res_inst_1, boolean top_res_inst_0) =
    (top_usr_OK && (!(top_impl_usr_early) || (top_res_inst_1 >= 2)) && (!(top_res_abs_1) || (top_res_inst_1 >= 2)));

  @*/

// Pure C helper functions (using 64-bit long long)
static inline _Bool c___node_init_COUNTER_0(long long COUNTER_usr_init_a_0, long long COUNTER_usr_incr_a_0, _Bool COUNTER_usr_X_a_0, _Bool COUNTER_usr_reset_a_0, long long COUNTER_usr_C_a_0, _Bool COUNTER_res_init_flag_a_0) {
    return ((COUNTER_usr_C_a_0 == ((COUNTER_usr_reset_a_0) ? (COUNTER_usr_init_a_0) : (((COUNTER_usr_X_a_0) ? ((COUNTER_usr_init_a_0 + COUNTER_usr_incr_a_0)) : (COUNTER_usr_init_a_0))))) && COUNTER_res_init_flag_a_0);
}

static inline _Bool c___node_trans_COUNTER_0(long long COUNTER_usr_init_a_1, long long COUNTER_usr_incr_a_1, _Bool COUNTER_usr_X_a_1, _Bool COUNTER_usr_reset_a_1, long long COUNTER_usr_C_a_1, _Bool COUNTER_res_init_flag_a_1, long long COUNTER_usr_init_a_0, long long COUNTER_usr_incr_a_0, _Bool COUNTER_usr_X_a_0, _Bool COUNTER_usr_reset_a_0, long long COUNTER_usr_C_a_0, _Bool COUNTER_res_init_flag_a_0) {
    return ((COUNTER_usr_C_a_1 == ((COUNTER_usr_reset_a_1) ? (COUNTER_usr_init_a_1) : (((COUNTER_usr_X_a_1) ? ((COUNTER_usr_C_a_0 + COUNTER_usr_incr_a_1)) : (COUNTER_usr_C_a_0))))) && !(COUNTER_res_init_flag_a_1));
}

static inline _Bool c___node_init_speed_0(_Bool speed_usr_beacon_a_0, _Bool speed_usr_second_a_0, _Bool speed_usr_late_a_0, _Bool speed_usr_early_a_0, _Bool speed_res_init_flag_a_0, long long speed_impl_usr_incr_a_0, long long speed_res_abs_0_a_0, _Bool speed_res_abs_1_a_0, _Bool speed_res_abs_2_a_0, long long speed_res_abs_3_a_0, _Bool speed_res_inst_0_a_0) {
    return ((speed_usr_late_a_0 == false) && (speed_res_abs_2_a_0 == false) && (speed_res_abs_1_a_0 == (speed_usr_beacon_a_0 || speed_usr_second_a_0)) && (speed_res_abs_0_a_0 == 0) && (speed_impl_usr_incr_a_0 == (((speed_usr_beacon_a_0 || !(speed_usr_second_a_0))) ? (1) : ((((speed_usr_second_a_0 && !(speed_usr_beacon_a_0))) ? (2) : (0))))) && ((speed_usr_early_a_0 == false) && c___node_init_COUNTER_0(speed_res_abs_0_a_0, speed_impl_usr_incr_a_0, speed_res_abs_1_a_0, speed_res_abs_2_a_0, speed_res_abs_3_a_0, speed_res_inst_0_a_0) && ((0 <= speed_res_abs_0_a_0) && (speed_res_abs_0_a_0 <= 0)) && ((0 <= speed_impl_usr_incr_a_0) && (speed_impl_usr_incr_a_0 <= 2)) && speed_res_init_flag_a_0));
}

static inline _Bool c___node_trans_speed_0(_Bool speed_usr_beacon_a_1, _Bool speed_usr_second_a_1, _Bool speed_usr_late_a_1, _Bool speed_usr_early_a_1, _Bool speed_res_init_flag_a_1, long long speed_impl_usr_incr_a_1, long long speed_res_abs_0_a_1, _Bool speed_res_abs_1_a_1, _Bool speed_res_abs_2_a_1, long long speed_res_abs_3_a_1, _Bool speed_res_inst_0_a_1, _Bool speed_usr_beacon_a_0, _Bool speed_usr_second_a_0, _Bool speed_usr_late_a_0, _Bool speed_usr_early_a_0, _Bool speed_res_init_flag_a_0, long long speed_impl_usr_incr_a_0, long long speed_res_abs_0_a_0, _Bool speed_res_abs_1_a_0, _Bool speed_res_abs_2_a_0, long long speed_res_abs_3_a_0, _Bool speed_res_inst_0_a_0) {
    return ((speed_res_abs_2_a_1 == false) && (speed_res_abs_1_a_1 == (speed_usr_beacon_a_1 || speed_usr_second_a_1)) && (speed_res_abs_0_a_1 == 0) && (speed_impl_usr_incr_a_1 == (((speed_usr_beacon_a_1 || !(speed_usr_second_a_1))) ? (1) : ((((speed_usr_second_a_1 && !(speed_usr_beacon_a_1))) ? (2) : (0))))) && ((speed_usr_late_a_1 == ((speed_usr_late_a_0) ? ((speed_res_abs_3_a_1 < 0)) : ((speed_res_abs_3_a_1 <= -10)))) && (speed_usr_early_a_1 == ((speed_usr_early_a_0) ? ((speed_res_abs_3_a_1 > 0)) : ((speed_res_abs_3_a_1 >= 10)))) && c___node_trans_COUNTER_0(speed_res_abs_0_a_1, speed_impl_usr_incr_a_1, speed_res_abs_1_a_1, speed_res_abs_2_a_1, speed_res_abs_3_a_1, speed_res_inst_0_a_1, speed_res_abs_0_a_0, speed_impl_usr_incr_a_0, speed_res_abs_1_a_0, speed_res_abs_2_a_0, speed_res_abs_3_a_0, speed_res_inst_0_a_0) && ((0 <= speed_res_abs_0_a_1) && (speed_res_abs_0_a_1 <= 0)) && ((0 <= speed_impl_usr_incr_a_1) && (speed_impl_usr_incr_a_1 <= 2)) && !(speed_res_init_flag_a_1)));
}

static inline _Bool c___node_init_top_0(_Bool top_usr_beacon_a_0, _Bool top_usr_second_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, _Bool top_impl_usr_early_a_0, _Bool top_res_abs_0_a_0, _Bool top_res_abs_1_a_0, _Bool top_res_inst_6_a_0, long long top_res_inst_5_a_0, long long top_res_inst_4_a_0, _Bool top_res_inst_3_a_0, _Bool top_res_inst_2_a_0, long long top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_usr_OK_a_0 == true) && ((top_impl_usr_early_a_0 == top_res_abs_1_a_0) && c___node_init_speed_0(top_usr_beacon_a_0, top_usr_second_a_0, top_res_abs_0_a_0, top_res_abs_1_a_0, top_res_inst_6_a_0, top_res_inst_5_a_0, top_res_inst_4_a_0, top_res_inst_3_a_0, top_res_inst_2_a_0, top_res_inst_1_a_0, top_res_inst_0_a_0) && top_res_init_flag_a_0));
}

static inline _Bool c___node_trans_top_0(_Bool top_usr_beacon_a_1, _Bool top_usr_second_a_1, _Bool top_usr_OK_a_1, _Bool top_res_init_flag_a_1, _Bool top_impl_usr_early_a_1, _Bool top_res_abs_0_a_1, _Bool top_res_abs_1_a_1, _Bool top_res_inst_6_a_1, long long top_res_inst_5_a_1, long long top_res_inst_4_a_1, _Bool top_res_inst_3_a_1, _Bool top_res_inst_2_a_1, long long top_res_inst_1_a_1, _Bool top_res_inst_0_a_1, _Bool top_usr_beacon_a_0, _Bool top_usr_second_a_0, _Bool top_usr_OK_a_0, _Bool top_res_init_flag_a_0, _Bool top_impl_usr_early_a_0, _Bool top_res_abs_0_a_0, _Bool top_res_abs_1_a_0, _Bool top_res_inst_6_a_0, long long top_res_inst_5_a_0, long long top_res_inst_4_a_0, _Bool top_res_inst_3_a_0, _Bool top_res_inst_2_a_0, long long top_res_inst_1_a_0, _Bool top_res_inst_0_a_0) {
    return ((top_usr_OK_a_1 == (!(top_impl_usr_early_a_0) || !(top_res_abs_0_a_1))) && (top_impl_usr_early_a_1 == top_res_abs_1_a_1) && c___node_trans_speed_0(top_usr_beacon_a_1, top_usr_second_a_1, top_res_abs_0_a_1, top_res_abs_1_a_1, top_res_inst_6_a_1, top_res_inst_5_a_1, top_res_inst_4_a_1, top_res_inst_3_a_1, top_res_inst_2_a_1, top_res_inst_1_a_1, top_res_inst_0_a_1, top_usr_beacon_a_0, top_usr_second_a_0, top_res_abs_0_a_0, top_res_abs_1_a_0, top_res_inst_6_a_0, top_res_inst_5_a_0, top_res_inst_4_a_0, top_res_inst_3_a_0, top_res_inst_2_a_0, top_res_inst_1_a_0, top_res_inst_0_a_0) && !(top_res_init_flag_a_1));
}

static inline _Bool c_init(_Bool top_usr_beacon, _Bool top_usr_second, _Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_early, _Bool top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_inst_6, long long top_res_inst_5, long long top_res_inst_4, _Bool top_res_inst_3, _Bool top_res_inst_2, long long top_res_inst_1, _Bool top_res_inst_0) {
    return ((top_usr_OK == true) && ((top_impl_usr_early == top_res_abs_1) && c___node_init_speed_0(top_usr_beacon, top_usr_second, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0) && top_res_init_flag));
}

static inline _Bool c_trans(_Bool top_usr_beacon, _Bool top_usr_second, _Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_early, _Bool top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_inst_6, long long top_res_inst_5, long long top_res_inst_4, _Bool top_res_inst_3, _Bool top_res_inst_2, long long top_res_inst_1, _Bool top_res_inst_0, _Bool top_usr_beacon_next, _Bool top_usr_second_next, _Bool top_usr_OK_next, _Bool top_res_init_flag_next, _Bool top_impl_usr_early_next, _Bool top_res_abs_0_next, _Bool top_res_abs_1_next, _Bool top_res_inst_6_next, long long top_res_inst_5_next, long long top_res_inst_4_next, _Bool top_res_inst_3_next, _Bool top_res_inst_2_next, long long top_res_inst_1_next, _Bool top_res_inst_0_next) {
    return ((top_usr_OK_next == (!(top_impl_usr_early) || !(top_res_abs_0_next))) && (top_impl_usr_early_next == top_res_abs_1_next) && c___node_trans_speed_0(top_usr_beacon_next, top_usr_second_next, top_res_abs_0_next, top_res_abs_1_next, top_res_inst_6_next, top_res_inst_5_next, top_res_inst_4_next, top_res_inst_3_next, top_res_inst_2_next, top_res_inst_1_next, top_res_inst_0_next, top_usr_beacon, top_usr_second, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0) && !(top_res_init_flag_next));
}

static inline _Bool c_prop(_Bool top_usr_beacon, _Bool top_usr_second, _Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_early, _Bool top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_inst_6, long long top_res_inst_5, long long top_res_inst_4, _Bool top_res_inst_3, _Bool top_res_inst_2, long long top_res_inst_1, _Bool top_res_inst_0) {
    return top_usr_OK;
}

static inline _Bool c_str_invariant(_Bool top_usr_beacon, _Bool top_usr_second, _Bool top_usr_OK, _Bool top_res_init_flag, _Bool top_impl_usr_early, _Bool top_res_abs_0, _Bool top_res_abs_1, _Bool top_res_inst_6, long long top_res_inst_5, long long top_res_inst_4, _Bool top_res_inst_3, _Bool top_res_inst_2, long long top_res_inst_1, _Bool top_res_inst_0) {
    return (top_usr_OK && (!(top_impl_usr_early) || (top_res_inst_1 >= 2)) && (!(top_res_abs_1) || (top_res_inst_1 >= 2)));
}

int main(void) {
    // 1. Variable declarations & nondeterministic initialization
    _Bool top_usr_beacon = nondet_bool();
    _Bool top_usr_second = nondet_bool();
    _Bool top_usr_OK = nondet_bool();
    _Bool top_res_init_flag = nondet_bool();
    _Bool top_impl_usr_early = nondet_bool();
    _Bool top_res_abs_0 = nondet_bool();
    _Bool top_res_abs_1 = nondet_bool();
    _Bool top_res_inst_6 = nondet_bool();
    long long top_res_inst_5 = nondet_long();
    long long top_res_inst_4 = nondet_long();
    _Bool top_res_inst_3 = nondet_bool();
    _Bool top_res_inst_2 = nondet_bool();
    long long top_res_inst_1 = nondet_long();
    _Bool top_res_inst_0 = nondet_bool();

    // 2. Precondition check (safe C guard instead of /*@ assume */)
    if (!c_init(top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0)) return 0;

    // 3. Loop body with ACSL loop invariant
    /*@
      @ loop invariant str_invariant(top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0);
      @ loop assigns top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0;
      @*/
    while (1) {
        _Bool top_usr_beacon_next = nondet_bool();
        _Bool top_usr_second_next = nondet_bool();
        _Bool top_usr_OK_next = nondet_bool();
        _Bool top_res_init_flag_next = nondet_bool();
        _Bool top_impl_usr_early_next = nondet_bool();
        _Bool top_res_abs_0_next = nondet_bool();
        _Bool top_res_abs_1_next = nondet_bool();
        _Bool top_res_inst_6_next = nondet_bool();
        long long top_res_inst_5_next = nondet_long();
        long long top_res_inst_4_next = nondet_long();
        _Bool top_res_inst_3_next = nondet_bool();
        _Bool top_res_inst_2_next = nondet_bool();
        long long top_res_inst_1_next = nondet_long();
        _Bool top_res_inst_0_next = nondet_bool();

        if (!c_trans(top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0, top_usr_beacon_next, top_usr_second_next, top_usr_OK_next, top_res_init_flag_next, top_impl_usr_early_next, top_res_abs_0_next, top_res_abs_1_next, top_res_inst_6_next, top_res_inst_5_next, top_res_inst_4_next, top_res_inst_3_next, top_res_inst_2_next, top_res_inst_1_next, top_res_inst_0_next)) break;

        // State updates
        top_usr_beacon = top_usr_beacon_next;
        top_usr_second = top_usr_second_next;
        top_usr_OK = top_usr_OK_next;
        top_res_init_flag = top_res_init_flag_next;
        top_impl_usr_early = top_impl_usr_early_next;
        top_res_abs_0 = top_res_abs_0_next;
        top_res_abs_1 = top_res_abs_1_next;
        top_res_inst_6 = top_res_inst_6_next;
        top_res_inst_5 = top_res_inst_5_next;
        top_res_inst_4 = top_res_inst_4_next;
        top_res_inst_3 = top_res_inst_3_next;
        top_res_inst_2 = top_res_inst_2_next;
        top_res_inst_1 = top_res_inst_1_next;
        top_res_inst_0 = top_res_inst_0_next;
    }

    // 4. Post-condition assertion
    assert(c_prop(top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0));
    /*@ assert prop(top_usr_beacon, top_usr_second, top_usr_OK, top_res_init_flag, top_impl_usr_early, top_res_abs_0, top_res_abs_1, top_res_inst_6, top_res_inst_5, top_res_inst_4, top_res_inst_3, top_res_inst_2, top_res_inst_1, top_res_inst_0); */

    return 0;
}
