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
    printf("===== Question 2-1 =====\n");
    printf("array size = %d\n", arr_size);
    printf("student id = %d\n", (int)(student_id));
    arraymul_baseline();
    return 0;
}

void arraymul_baseline(){
    float *p_h = h;
    float *p_x = x;
    float *p_y = y;
    float id = student_id;// id = your_student_id % 100;
    int arr_length = arr_size;
    /* original C code
    for (int i = 0; i < arr_size; i++){
	    p_y[i] = p_h[i] * p_x[i] + id;
    }
    */
    asm volatile(
        #include "arraymul_baseline.c"
    : [h] "+r"(p_h), [x] "+r"(p_x), [y] "+r"(p_y), [add_cnt] "+r"(add_cnt), [mul_cnt] "+r"(mul_cnt), [fadd_cnt] "+r"(fadd_cnt), [fmul_cnt] "+r"(fmul_cnt), [flw_cnt] "+r"(flw_cnt), [fsw_cnt] "+r"(fsw_cnt), [lw_cnt] "+r"(lw_cnt), [sw_cnt] "+r"(sw_cnt), [others_cnt] "+r"(others_cnt), [arr_size] "+r"(arr_length)
    : [id] "f"(id)
    : "f0", "f1"
    );

    printf("output: ");
    for (int i = 0; i < arr_size; i++){
        printf(" %.6f ", y[i]);
    }
       
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
    
    macro_calc_arraymul_baseline_ratio
    
    if(arraymul_baseline_ratio > 0.5)
        printf("This program is a CPU bound task.\n");
    else
        printf("This program is a Memory bound task.\n");
    
    //record the cpu time
    FILE *fp;
    fp = fopen("arraymul_baseline_cpu_time.txt", "w");
    fprintf(fp, "%f", arraymul_baseline_cpu_time);
    fclose(fp);
}


void init(){
    add_cnt = 0;
    sub_cnt = 0;
    mul_cnt = 0;
    div_cnt = 0;
    lw_cnt = 0;
    sw_cnt = 0;
    others_cnt = 0;
    
    float temp = arr_size;
    while(temp != 1 && temp > 1 )
    {
        temp = temp / 2;
    }
    if (temp != 1)
    {
        printf("log2(arr_size) must be an integer !!!\n");
        exit(0);
    }
    
    h = calloc(arr_size, sizeof(float));
    x = calloc(arr_size, sizeof(float));
    y = calloc(arr_size, sizeof(float));
}

void input(){

	int fd;
	char *buf = (char *)calloc(3000, sizeof(char));
	
	fd = open("./arraymul_input.txt", O_RDONLY);
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