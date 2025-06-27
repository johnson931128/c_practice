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
    printf("===== Question 2-2 =====\n");
    printf("array size = %d\n", arr_size);
    printf("student id = %d\n", (int)(student_id));
    printf("output: ");
    improved_version();
    return 0;
}

void improved_version(){
    float *p_h = h;
    float *p_x = x;
    float *p_y = y;
    float id = student_id;// id = your_student_id % 100;
    /* original C code
    for (int i = 0; i < arr_size; i++){
    	p_y[i] = p_h[i] * p_x[i] + id;
    }
    */
    int arr_length = arr_size;
    asm volatile(
        #include "arraymul_improved.c"
        : [h] "+r"(p_h), [x] "+r"(p_x), [y] "+r"(p_y), [add_cnt] "+r"(add_cnt), [sub_cnt] "+r"(sub_cnt), [mul_cnt] "+r"(mul_cnt), [div_cnt] "+r"(div_cnt), [lw_cnt] "+r"(lw_cnt), [sw_cnt] "+r"(sw_cnt), [fadd_cnt] "+r"(fadd_cnt), [fmul_cnt] "+r"(fmul_cnt), [others_cnt] "+r"(others_cnt), [arr_size] "+r"(arr_length)
        : [id] "f"(id)
        : "t0", "v0", "v1", "v2"
    );

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
    macro_arraymul_vector_cycle_count
    printf("The total cycle count in this program: %.0f\n", arraymul_vector_cycle_count);


    macro_arraymul_vector_cpu_time
    printf("CPU time = %f us\n", arraymul_vector_cpu_time);
    FILE *fp_1;
    fp_1 = fopen("arraymul_vector_cpu_time.txt", "w");
    fprintf(fp_1, "%f", arraymul_vector_cpu_time);
    fclose(fp_1);
    
    float speedup = 0.0;
    
    FILE *fp_2;
    fp_2 = fopen("arraymul_baseline_cpu_time.txt", "r");
    fscanf(fp_2, "%f", &speedup);
    fclose(fp_2);
    speedup = speedup / arraymul_vector_cpu_time;
    printf("V extension ISA faster %f times than baseline ISA\n", speedup);
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
		    h[i] = atof(token);
		else
		    x[i-arr_size] = atof(token);
		
		token = strtok(NULL, " ");	
    }
}
