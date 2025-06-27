#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include "arraymul.h"
#include "macro_define.h"
int main(int argc, char *argv[]){
    init();
    input();
    arraymul_double();
    printf("===== Question 3-2 =====\n");

    printf("array size = %d\n", arr_size);


    printf("output:  %.15f", double_floating_result);

    printf("\n\n");

    printf("add counter used: %d\n", add_cnt);
    printf("sub counter used: %d\n", sub_cnt);
    printf("mul counter used: %d\n", mul_cnt);
    printf("div counter used: %d\n", div_cnt);
    printf("lw counter used: %d\n", lw_cnt);
    printf("sw counter used: %d\n", sw_cnt);
    printf("dadd counter used: %d\n", dadd_cnt);
    printf("dsub counter used: %d\n", dsub_cnt);
    printf("dmul counter used: %d\n", dmul_cnt);
    printf("ddiv counter used: %d\n", ddiv_cnt);
    printf("dlw counter used: %d\n", dlw_cnt);
    printf("dsw counter used: %d\n", dsw_cnt);
    printf("others counter used: %d\n", others_cnt);
	
    macro_arraymul_double_cycle_count
    printf("The total cycle count in this program: %.0f\n", arraymul_double_cycle_count);

    macro_arraymul_double_cpu_time
    printf("CPU time = %f us\n", arraymul_double_cpu_time);
    
    float speedup = 0.0;
    
    FILE *fp_2;
    fp_2 = fopen("float_cpu_time.txt", "r");
    fscanf(fp_2, "%f", &speedup);
    fclose(fp_2);
    speedup = arraymul_double_cpu_time / speedup;
    printf("double floating-point calculation is %f times slower than single floating-point calculation\n", speedup);
    
    float float_result = 0.0;
    double relative_error = 0.0;
    FILE *fp3;
    fp3 = fopen("float_result.txt", "r");
    fscanf(fp3, "%f", &float_result);
    fclose(fp3);
    relative_error = (fabs(float_result - double_floating_result) / double_floating_result);
    printf("error between float and double is %.15f\n", relative_error);
    return 0;
}

void arraymul_double(){
    double *p_h = u;
    double *p_x = v;
    int arr_length = arr_size;
    /* original C code
    for (int i = 0; i < arr_size; i++){
    	double_floating_result = double_floating_result * p_h[i] * p_x[i];
    }
    */
   asm volatile(
    #include "arraymul_double.c"
    : [h] "+r"(p_h), [x] "+r"(p_x), [result] "+f"(double_floating_result), [add_cnt] "+r"(add_cnt), [dadd_cnt] "+r"(dadd_cnt), [dmul_cnt] "+r"(dmul_cnt), [dlw_cnt] "+r"(dlw_cnt), [dsw_cnt] "+r"(dsw_cnt), [others_cnt] "+r"(others_cnt), [arr_size] "+r"(arr_length)
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
    dadd_cnt = 0;
    dsub_cnt = 0;
    dmul_cnt = 0;
    ddiv_cnt = 0;
    dlw_cnt = 0;
    dsw_cnt = 0;
    others_cnt = 0;
    
    double temp = arr_size;
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
    
    
    u = calloc(arr_size, sizeof(double));
    v = calloc(arr_size, sizeof(double));
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
            u[i] = atof(token);
        }
		else
        {
            v[i-arr_size] = atof(token);
        }
		
		token = strtok(NULL, " ");	
    }
}
