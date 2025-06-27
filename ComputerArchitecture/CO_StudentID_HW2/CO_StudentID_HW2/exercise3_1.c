#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "arraymul.h"
#include "macro_define.h"

int main(int argc, char *argv[]){
    init();
    input();
    arraymul_float();

    printf("===== Question 3-1 =====\n");
    printf("array size = %d\n", arr_size);

    printf("output:  %.6f", single_floating_result);
    printf("\n\n");

    printf("add counter used: %d\n", add_cnt);
    printf("sub counter used: %d\n", sub_cnt);
    printf("mul counter used: %d\n", mul_cnt);
    printf("div counter used: %d\n", div_cnt);
    printf("lw counter used: %d\n", lw_cnt);
    printf("sw counter used: %d\n", sw_cnt);
    printf("fadd counter used: %d\n", fadd_cnt);
    printf("fsub counter used: %d\n", fsub_cnt);
    printf("fmul counter used: %d\n", fmul_cnt);
    printf("fdiv counter used: %d\n", fdiv_cnt);
    printf("flw counter used: %d\n", flw_cnt);
    printf("fsw counter used: %d\n", fsw_cnt);
    printf("others counter used: %d\n", others_cnt);
    
    macro_arraymul_baseline_cycle_count
    printf("The total cycle count in this program: %.0f\n", arraymul_baseline_cycle_count);

    macro_arraymul_baseline_cpu_time
    printf("CPU time = %f us\n", arraymul_baseline_cpu_time);
    
    //record the cpu time
    FILE *fp;
    fp = fopen("float_cpu_time.txt", "w");
    fprintf(fp, "%f", arraymul_baseline_cpu_time);
    fclose(fp);

    FILE *fp2;
    fp2 = fopen("float_result.txt", "w");
    fprintf(fp2, "%f", single_floating_result);
    fclose(fp2);

    return 0;
}

void arraymul_float(){
    float *p_h = h;
    float *p_x = x;
    int arr_length = arr_size;
    /* original C code
    for (int i = 0; i < arr_size; i++){
    	single_floating_result = single_floating_result * p_h[i] * p_x[i];
    }
    */
    asm volatile(
        #include "arraymul_float.c"
        : [h] "+r"(p_h), [x] "+r"(p_x), [result] "+f"(single_floating_result), [add_cnt] "+r"(add_cnt), [fadd_cnt] "+r"(fadd_cnt), [fmul_cnt] "+r"(fmul_cnt), [flw_cnt] "+r"(flw_cnt), [fsw_cnt] "+r"(fsw_cnt), [others_cnt] "+r"(others_cnt), [arr_size] "+r"(arr_length)
        : 
        : "t0", "f0", "f1", "f2", "f3"
    );
}

void init(){
    add_cnt = 0;
    sub_cnt = 0;
    mul_cnt = 0;
    div_cnt = 0;
    lw_cnt = 0;
    sw_cnt = 0;
    fadd_cnt = 0;
    fsub_cnt = 0;
    fmul_cnt = 0;
    fdiv_cnt = 0;
    flw_cnt = 0;
    fsw_cnt = 0;
    others_cnt = 0;
    
    float temp = arr_size;
    while(temp != 1 && temp > 1 )
    {
        temp = temp / 2;
        count += 1;
    }
    if (temp != 1)
    {
        printf("log2(arr_size) must be an integer !!!\n");
        exit(0);
    }
    
    h = calloc(arr_size, sizeof(float));
    x = calloc(arr_size, sizeof(float));
}

void input(){

    int fd;
    char *buf = (char *)calloc(3000, sizeof(char));
    
    fd = open("./arraymul_input2.txt", O_RDONLY);
    if(fd < 0)
        exit(EXIT_FAILURE);
    if(read(fd, buf, 3000) < 0)
        exit(EXIT_FAILURE);

    char *token;
        token = strtok(buf, " ");
    int count = 0;
    
    for(int i = 0; i < arr_size*2; ++i){
        if(i < arr_size)
        {
            h[i] = atof(token);
        }
        else
        {
            x[i-arr_size] = atof(token);
        }
        
        token = strtok(NULL, " ");	
    }
}
