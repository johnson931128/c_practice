MAKEFLAGS += --no-print-directory

PK_PATH = /opt/riscv/riscv64-unknown-linux-gnu/bin/pk

ARR_SIZE ?= 16

test_exercise1:
	@./judge_exercise1
	
test_exercise2_1:
	@./judge_exercise2_1

test_exercise2_2:
	@./judge_exercise2_2

test_exercise3_1:
	@./judge_exercise3_1

test_exercise3_2:
	@./judge_exercise3_2
	
	
run_exercise1: exercise1
	@spike --isa=RV64GCV $(PK_PATH) exercise1

run_exercise2_1: exercise2_1
	@spike --isa=RV64GCV $(PK_PATH) exercise2_1

run_exercise2_2: exercise2_2
	@spike --isa=RV64GCV $(PK_PATH) exercise2_2

run_exercise3_1: exercise3_1
	@spike --isa=RV64GCV $(PK_PATH) exercise3_1	

run_exercise3_2: exercise3_2
	@spike --isa=RV64GCV $(PK_PATH) exercise3_2	

exercise1: exercise1.c macro_define.h fft.h pi.c complex_add.c complex_sub.c complex_mul.c log2.c bit_reverse.c
	@riscv64-unknown-linux-gnu-gcc -march=rv64gcv -static -o exercise1 exercise1.c -lm
	
exercise2_1: exercise2_1.c macro_define.h arraymul.h arraymul_baseline.c
	@riscv64-unknown-linux-gnu-gcc -march=rv64gcv -static -DARR_SIZE=$(ARR_SIZE) -o exercise2_1 exercise2_1.c

exercise2_2: exercise2_2.c macro_define.h arraymul.h arraymul_improved.c
	@riscv64-unknown-linux-gnu-gcc -march=rv64gcv -static -DARR_SIZE=$(ARR_SIZE) -o exercise2_2 exercise2_2.c

exercise3_1: exercise3_1.c macro_define.h arraymul.h arraymul_float.c
	@riscv64-unknown-linux-gnu-gcc -march=rv64gcv -static -DARR_SIZE=$(ARR_SIZE) -o exercise3_1 exercise3_1.c

exercise3_2: exercise3_2.c macro_define.h arraymul.h arraymul_double.c
	@riscv64-unknown-linux-gnu-gcc -march=rv64gcv -static -DARR_SIZE=$(ARR_SIZE) -o exercise3_2 exercise3_2.c


clean:
	@rm -f exercise1 exercise2_1 exercise2_2 exercise3_1 exercise3_2
