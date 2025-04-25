#define macro_fft_cycle_count \
	 fft_cycle_count = ( (long long)add_cnt * add_CPI + \
				(long long)sub_cnt * sub_CPI + \
				(long long)mul_cnt * mul_CPI + \
				(long long)div_cnt * div_CPI + \
				(long long)lw_cnt  * lw_CPI  + \
				(long long)sw_cnt * sw_CPI + \
                     		(long long)fadd_cnt * fadd_CPI + \
                      		(long long)fsub_cnt * fsub_CPI + \
                      		(long long)fmul_cnt * fmul_CPI + \
                      		(long long)fdiv_cnt * fdiv_CPI + \
                      		(long long)others_cnt * others_CPI )

#define macro_fft_cpu_time \
	fft_cpu_time = ( (double)fft_cycle_count * cycle_time / 1000.0)

#define macro_calc_fft_ratio \
	fft_ratio = ( (fft_cycle_count > 0) ? \
			( (double)fft_cycle_count - \
				( (long long)lw_cnt * lw_CPI + \
				(long long)sw_cnt * sw_CPI + \
				/ fft_cycle_count) \
				:0.0)

#define macro_arraymul_vector_cycle_count arraymul_vector_cycle_count = 0;

#define macro_arraymul_vector_cpu_time arraymul_vector_cpu_time = 0;

#define macro_arraymul_baseline_cycle_count arraymul_baseline_cycle_count = 0;

#define macro_arraymul_baseline_cpu_time arraymul_baseline_cpu_time = 0;

#define macro_calc_arraymul_baseline_ratio arraymul_baseline_ratio = 0;

#define macro_calc_arraymul_double_ratio arraymul_baseline_ratio = 0;

#define macro_arraymul_double_cycle_count arraymul_double_cycle_count = 0;

#define macro_arraymul_double_cpu_time arraymul_double_cpu_time = 0;

