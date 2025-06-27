

"addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
"fmul.s f1, %[A_Re], %[B_Re]     \n\t"
"addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
"fmul.s f2, %[A_Im], %[B_Im]     \n\t"
"addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
"fmul.s f3, %[A_Re], %[B_Im]     \n\t"
"addi %[fmul_cnt], %[fmul_cnt], 1\n\t"
"fmul.s f4, %[A_Im], %[B_Re]     \n\t"
"addi %[fsub_cnt], %[fsub_cnt], 1\n\t"
"fsub.s %[C_Re], f1, f2          \n\t"
"addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
"fadd.s %[C_Im], f3, f4          \n\t"



