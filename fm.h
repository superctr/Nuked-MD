#pragma once
#include <stdint.h>

enum {
    fm_flags_ym2612 = 1,
};

typedef struct {
    int phi;
    int ic;
} fm_prescaler_input_t;

typedef struct {
    fm_prescaler_input_t input, input_old;

    // clock
    int ic_latch[2]; // 12
    int ic_check_latch[2]; // 4
    int prescaler_latch[2]; // 6
    int phi1_latch[2];
    int phi2_latch[2];
} fm_prescaler_t;

typedef struct {
    int phi_phase;
    int ic;
    int rd;
    int wr;
    int cs;
    int address;
    int data;
    int test;
    int i_fsm_reset; // (chip->ic_check_latch[1] & 16) != 0;
} fm_input_t;

typedef struct {
    int flags;
    // input
    fm_input_t input_old, input;
    int i_phi1;
    int i_phi2;

    fm_prescaler_t prescaler;

    // output
    int dac_val;
    int out_l;
    int out_r;

    // io
    int write_addr_trig;
    int write_addr_trig_sync;
    int write_addr_dlatch;
    int write_addr_sr[2];
    int write_data_trig;
    int write_data_trig_sync;
    int write_data_dlatch;
    int write_data_sr[2];

    int data_latch;
    int bank_latch;

    int busy_cnt[2];
    int busy_latch[2];

    int io_ic_latch[2];

    int write_fm_address[2];
    int fm_address[2];
    int write_fm_data[2];
    int fm_data[2];
    int status_timer_a_dlatch;
    int status_timer_b_dlatch;

    // mode registers
    int write_mode_21[2];
    int write_mode_22[2];
    int write_mode_24[2];
    int write_mode_25[2];
    int write_mode_26[2];
    int write_mode_27[2];
    int write_mode_28[2];
    int write_mode_2a[2];
    int write_mode_2b[2];
    int write_mode_2c[2];

    int mode_test_21[2];
    int mode_lfo_en[2];
    int mode_lfo_freq[2];
    int mode_timer_a_reg[2];
    int mode_timer_b_reg[2];
    int mode_ch3[2];
    int mode_timer_a_load[2];
    int mode_timer_a_enable[2];
    int mode_timer_a_reset[2];
    int mode_timer_b_load[2];
    int mode_timer_b_enable[2];
    int mode_timer_b_reset[2];
    int mode_kon_operator[2];
    int mode_kon_channel[2];
    int mode_dac_data[2];
    int mode_dac_en[2];
    int mode_test_2c[2];

    int mode_kon[4][2];

    // operator registers
    int slot_multi[2][4][2];
    int slot_dt[2][3][2];
    int slot_tl[2][7][2];
    int slot_ar[2][5][2];
    int slot_ks[2][2][2];
    int slot_dr[2][5][2];
    int slot_am[2][1][2];
    int slot_sr[2][5][2];
    int slot_rr[2][4][2];
    int slot_sl[2][4][2];
    int slot_ssg_eg[2][4][2];
    // channel registers
    int chan_fnum[11][2];
    int chan_fnum_ch3[11][2];
    int chan_block[3][2];
    int chan_block_ch3[3][2];
    int chan_a4[2];
    int chan_ac[2];
    int chan_connect[3][2];
    int chan_fb[3][2];
    int chan_pms[3][2];
    int chan_ams[2][2];
    int chan_pan[2][2];

    int reg_cnt1[2];
    int reg_cnt2[2];

    // lfo

    int lfo_cnt1[2];
    int lfo_cnt2[2];

    int lfo_dlatch;
    int lfo_dlatch_load;
    int lfo_inc_latch[2];

    // pg
    int pg_fnum[2][2];
    int pg_kcode[2][2];
    int pg_fnum_lfo1;
    int pg_fnum_lfo2;
    int pg_lfo_shift;
    int pg_lfo_sign;
    int pg_lfo;
    int pg_freq1;
    int pg_freq2;
    int pg_freq3;
    int pg_freq4;
    int pg_freq5[2];
    int pg_freq6;
    int pg_freq_m1;
    int pg_block;
    int pg_dt[2];
    int pg_detune[2];
    int pg_multi[2][2];
    int pg_multi2;
    int pg_inc[2];
    int pg_inc_mask[2];
    int pg_phase[20][2];
    int pg_reset_latch[2];
    int pg_debug[2];
    int pg_reset[2];

    // eg
    int eg_prescaler[2];
    int eg_prescaler_clock_l[2];
    int eg_prescaler_l;
    int eg_clock_delay[2];
    int eg_step[2];
    int eg_timer_load;
    int eg_timer[2];
    int eg_timer_carry[2];
    int eg_timer_mask[2];
    int eg_timer_masked[2];
    int eg_timer_low_lock;
    int eg_shift_lock;
    int eg_level[10][2];
    int eg_level_latch[2];
    int eg_level_latch_inv;
    int eg_state[2][2];
    int eg_ssg_dir[2];
    int eg_ssg_inv[2];
    int eg_ssg_holdup[2];
    int eg_ssg_enable[2];
    int eg_ssg_pgreset[2];
    int eg_ssg_pgrepeat[2];
    int eg_key[2];
    int eg_rate_nonzero[2];
    int eg_rate;
    int eg_ksv;
    int eg_rate2;
    int eg_inc1;
    int eg_inc2;
    int eg_rate12;
    int eg_rate13;
    int eg_rate14;
    int eg_rate15;
    int eg_maxrate[2];
    int eg_incsh0;
    int eg_incsh1;
    int eg_incsh2;
    int eg_incsh3;
    int eg_incsh_nonzero[2];
    int eg_inc_total;
    int eg_level_ssg[2];
    int eg_sl[2][2];
    int eg_nextlevel[2];
    int eg_kon_csm[2];
    int eg_kon_latch[2];
    int eg_tl[2][2];
    int eg_ams;
    int eg_lfo[2];
    int eg_ch3_latch[2];
    int eg_out;
    int eg_out_tl;
    int eg_out_total;
    int eg_debug[2];

    // op
    int op_mod[10][2];
    int op_phase[2];
    int op_logsin_base[2];
    int op_logsin_delta[2];
    int op_logsin_add_delta[2];
    int op_atten[2];
    int op_env[2];
    int op_pow_base[2];
    int op_pow_delta[2];
    int op_pow_add_delta[2];
    int op_shift[2];
    int op_sign[2];
    int op_output[2];
    int op_op1[2][14][2];
    int op_op2[14][2];
    int op_mod_sum[2];
    int op_dofeedback[2];

    // accumulator

    int ch_accm[9][2];
    int ch_out[9][2];
    int ch_out_dlatch;
    int ch_out_pan_dlatch;
    int ch_dac_load;
    int ch_out_debug[2];

    // timers
    int timer_dlatch;
    int timer_a_cnt[2];
    int timer_a_load_latch[2];
    int timer_a_load_old[2];
    int timer_a_load_dlatch;
    int timer_a_of[2];
    int timer_a_status[2];
    int timer_b_subcnt[2];
    int timer_b_subcnt_of[2];
    int timer_b_cnt[2];
    int timer_b_load_latch[2];
    int timer_b_load_old[2];
    int timer_b_load_dlatch;
    int timer_b_of[2];
    int timer_b_status[2];
    int timer_csm_key_dlatch;

    // fm algorithm
    int alg_mod_op1_0;
    int alg_mod_op1_1;
    int alg_mod_op2;
    int alg_mod_prev_0;
    int alg_mod_prev_1;
    int alg_output;
    int alg_mod_op1_0_l;
    int alg_mod_op1_1_l;
    int alg_mod_op2_l;
    int alg_mod_prev_0_l;
    int alg_mod_prev_1_l;
    int alg_output_l;

    // fsm
    int fsm_cnt1[2];
    int fsm_cnt2[2];
    // fsm table output
    int fsm_clock_eg;
    int fsm_clock_timers1;
    int fsm_clock_timers;
    int fsm_op4_sel;
    int fsm_op1_sel;
    int fsm_op2_sel;
    int fsm_op3_sel;
    int fsm_sel2;
    int fsm_sel23;
    int fsm_ch3_sel;
    int fsm_dac_load;
    int fsm_dac_out_sel;
    int fsm_dac_ch6;
    // ym2612 FSM
    int fsm_out[26];
    int fsm_op4_sel_l;
    int fsm_op1_sel_l;
    int fsm_op2_sel_l;
    int fsm_op3_sel_l;
    int fsm_clock_eg_l;
    int fsm_clock_timers1_l;
    int fsm_clock_timers_l;
    int fsm_sel23_l;
    int fsm_ch3_sel_l;
    int fsm_dac_ch6_l;
    int fsm_dac_load_l;
    int fsm_dac_out_sel_l;

    int status_time;
    int last_status;
} fm_t;


int FM_ReadStatus(fm_t *chip);

void FM_Prescaler2(fm_prescaler_t *chip, int clk);
void FM_Clock2(fm_t *chip, int phi1, int phi2);
