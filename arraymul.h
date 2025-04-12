#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#ifndef ARR_SIZE
#define ARR_SIZE 4
#endif
int arr_size = ARR_SIZE;
int count = 0;
static float student_id = 0.0;//student_id = your_studnet_id % 100
static float *h;
static float *x;
static float *y;
static double *u;
static double *v;
static double *w;

// Given baseline counters in Question 1
int add_cnt = 0;
int sub_cnt = 0;
int mul_cnt = 0;
int div_cnt = 0;
int lw_cnt = 0;
int sw_cnt = 0;
int others_cnt = 0;

// Given Single floating-point
int fadd_cnt = 0;
int fsub_cnt = 0;
int fmul_cnt = 0;
int fdiv_cnt = 0;
int flw_cnt = 0;
int fsw_cnt = 0;

// Given Double floating-point
int dadd_cnt = 0;
int dsub_cnt = 0;
int dmul_cnt = 0;
int ddiv_cnt = 0;
int dlw_cnt = 0;
int dsw_cnt = 0;

// Given baseline CPI
const int add_CPI = 4;
const int sub_CPI = 4;
const int mul_CPI = 5;
const int div_CPI = 5;
const int lw_CPI = 20;
const int sw_CPI = 15;
const int others_CPI = 4;

// Given floating-point CPI
const int fadd_CPI = 6;
const int fsub_CPI = 6;
const int fmul_CPI = 7;
const int fdiv_CPI = 7;
const int flw_CPI = 20;
const int fsw_CPI = 15;

// Given double-floating-point CPI
const int dadd_CPI = 8;
const int dsub_CPI = 8;
const int dmul_CPI = 9;
const int ddiv_CPI = 9;
const int dlw_CPI = 20;
const int dsw_CPI = 15;

// Cycle count
float arraymul_baseline_cycle_count = 0.0;
float arraymul_vector_cycle_count = 0.0;
float arraymul_double_cycle_count = 0.0;

// ratio
float arraymul_baseline_ratio = 0.0;

// Given cycle time
const int cycle_time = 384; // us

// CPU time
float arraymul_baseline_cpu_time = 0.0;
float arraymul_vector_cpu_time = 0.0;
float arraymul_double_cpu_time = 0.0;

float single_floating_result = 1.0;
double double_floating_result = 1.0;

void init();
void arraymul_baseline();
void improved_version();
void arraymul_float();
void arraymul_double();
void input();

#endif
