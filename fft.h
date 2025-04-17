#ifndef _CONSTANT_H_
#define _CONSTANT_H_
int iter = 1000;
int N = 8;
float pi = 0.0;

// Given baseline counters in Question 1
int add_cnt = 0;
int sub_cnt = 0;
int mul_cnt = 0;
int div_cnt = 0;
int lw_cnt = 0;
int sw_cnt = 0;
int others_cnt = 0;

// Single floating point
int fadd_cnt = 0;
int fsub_cnt = 0;
int fmul_cnt = 0;
int fdiv_cnt = 0;

// Double floating point
int dadd_cnt = 0;
int dsub_cnt = 0;
int dmul_cnt = 0;
int ddiv_cnt = 0;

// Given baseline CPI
const int add_CPI = 4;
const int sub_CPI = 4;
const int mul_CPI = 5;
const int div_CPI = 5;
const int lw_CPI = 20;
const int sw_CPI = 15;
const int others_CPI = 4;

const int fadd_CPI = 6;
const int fsub_CPI = 6;
const int fmul_CPI = 7;
const int fdiv_CPI = 7;

// Cycle count
float fft_cycle_count = 0.0;

// ratio
float fft_ratio = 0.0;
// Given cycle time
const int cycle_time = 384; // us

// CPU time
float fft_cpu_time = 0.0;


#endif
