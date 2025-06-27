"addi t1, zero, 1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f1, t1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"addi t1, zero, 3\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f2, t1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"


"fsub.s %[pi], %[pi], %[pi]\n\t"
"addi %[fsub_cnt], %[fsub_cnt], 1\n\t"


"addi t1, zero, 0\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"addi t2, %[N], 0\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"


"pi_loop:\n\t"

"addi %[others_cnt], %[others_cnt], 1\n\t"
"bge t1, t2, pi_done\n\t"

"addi %[others_cnt], %[others_cnt], 1\n\t"
"slli t3, t1, 2\n\t"

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t4, t3, 1\n\t"

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t3, t3, 3\n\t"

"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f2, t4\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"addi t4, zero, 1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f1, t4\n\t"
"addi %[fdiv_cnt], %[fdiv_cnt], 1\n\t"
"fdiv.s f2, f1, f2\n\t"
"addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
"fadd.s %[pi], %[pi], f2\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f2, t3\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"addi t4, zero, 1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f1, t4\n\t"
"addi %[fdiv_cnt], %[fdiv_cnt], 1\n\t"
"fdiv.s f2, f1, f2\n\t"
"addi %[fsub_cnt], %[fsub_cnt], 1\n\t"
"fsub.s %[pi], %[pi], f2\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, t1, 1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"jal zero, pi_loop\n\t"
"pi_done:\n\t"
