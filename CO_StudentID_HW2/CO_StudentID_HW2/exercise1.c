#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "fft.h"
#include "macro_define.h"

typedef struct {
    float Re;
    float Im;
} Complex;


Complex complex_add(Complex a, Complex b)
{
    Complex result;
    //result.Re = a.Re + b.Re;
    //result.Im = a.Im + b.Im;
    asm volatile(
        #include "complex_add.c"
        :[C_Re] "=f"(result.Re), [C_Im] "=f"(result.Im), [fadd_cnt] "+r"(fadd_cnt)
        :[A_Re] "f"(a.Re), [B_Re] "f"(b.Re), [A_Im] "f"(a.Im), [B_Im] "f"(b.Im));
    return result;
}

Complex complex_sub(Complex a, Complex b)
{
    Complex result;
    //result.Re = a.Re - b.Re;
    //result.Im = a.Im - b.Im;
    asm volatile(
        #include "complex_sub.c"
        :[C_Re] "=f"(result.Re), [C_Im] "=f"(result.Im), [fsub_cnt] "+r"(fsub_cnt)
        :[A_Re] "f"(a.Re), [B_Re] "f"(b.Re), [A_Im] "f"(a.Im), [B_Im] "f"(b.Im));
    return result;
}

Complex complex_mul(Complex a, Complex b)
{
    Complex result;
    asm volatile(
        #include "complex_mul.c"
        : [C_Re] "=f"(result.Re), [C_Im] "=f"(result.Im), [fmul_cnt] "+r"(fmul_cnt), [fsub_cnt] "+r"(fsub_cnt), [fadd_cnt] "+r"(fadd_cnt)
        : [A_Re] "f"(a.Re), [B_Re] "f"(b.Re),
        [A_Im] "f"(a.Im), [B_Im] "f"(b.Im)
        : "f1", "f2", "f3", "f4"
    );
    return result;
}

uint32_t Log2(uint32_t N)
{
    uint32_t log = 0;
    asm volatile(
        #include "log2.c"
        : [log] "+r"(log), [N] "+r"(N), [add_cnt] "+r"(add_cnt), [others_cnt] "+r"(others_cnt) 
        :
        : "t0", "t1"
    );
    return log;
}

float PI(void)
{
    /* description: Gregory-Leibniz series
    * 
    *    we use Leibniz formula to approximate Pi
    * 
    *    pi/4 = (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
    *    pi   = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
    * 
    */
    asm volatile(
        #include "pi.c"
        : [add_cnt] "+r"(add_cnt), [fadd_cnt] "+r"(fadd_cnt), [sub_cnt] "+r"(sub_cnt), [fsub_cnt] "+r"(fsub_cnt), [mul_cnt] "+r"(mul_cnt), [div_cnt] "+r"(div_cnt), [fdiv_cnt] "+r"(fdiv_cnt), [lw_cnt] "+r"(lw_cnt), [sw_cnt] "+r"(sw_cnt), [others_cnt] "+r"(others_cnt), [pi] "+f"(pi)
        : [N] "r"(iter)
        : "f1", "f2", "t1", "t2", "t3", "t4"
    );
    pi = 4 * pi;
    return pi;
}

uint32_t bit_reverse(uint32_t b, uint32_t m)
{
    asm volatile (
        #include "bit_reverse.c"
        : [b] "+r"(b), [lw_cnt] "+r"(lw_cnt), [add_cnt] "+r"(add_cnt), [sub_cnt] "+r"(sub_cnt), [sw_cnt] "+r"(sw_cnt), [others_cnt] "+r"(others_cnt)
        : [m] "r"(m)
        : "t0", "t1", "t2"
    );
    return b;
}

void fft(Complex *x, uint32_t N)
{
    uint32_t k = N, n;
    pi = PI();
    float thetaT = pi / N;
    Complex phiT = {cos(thetaT), -sin(thetaT)}; // Twiddle Factor
    Complex T, temp;
    
    while (k > 1) { // Butterfly Computation
        n = k;
        k >>= 1;
        phiT = complex_mul(phiT, phiT);
        T.Re = 1.0;
        T.Im = 0.0;
        
        for (uint32_t l = 0; l < k; l++)
        {
            for (uint32_t a = l; a < N; a += n)
            {
                uint32_t b = a + k;
                temp = complex_sub(x[a], x[b]);
                x[a] = complex_add(x[a], x[b]);
                x[b] = complex_mul(temp, T);
            }
            T = complex_mul(T, phiT);
        }
    }

    // Bit-reverse
    uint32_t m = Log2(N);
    for (uint32_t a = 0; a < N; a++)
    {
        uint32_t b = a;
        b = bit_reverse(b, m);
        if (b > a) {
            temp = x[a];
            x[a] = x[b];
            x[b] = temp;
        }
    }
}

void print_fft(Complex *x, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("X[%d] = %.6f + %.6fj\n", i, x[i].Re, x[i].Im);
    }
}

int main() {

    FILE *fp = fopen("fft_input.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    Complex *data = malloc(N * sizeof(Complex));
    if (data == NULL) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%f %f", &data[i].Re, &data[i].Im);
    }

    fft(data, N);

    printf("===== Question 1-1 =====\n");

    printf("FFT result:\n");
    print_fft(data, N);
    printf("\n");

    printf("PI = %.6f\n", pi);
    printf("\n");

    printf("add counter used: %d\n", add_cnt);
    printf("sub counter used: %d\n", sub_cnt);
    printf("mul counter used: %d\n", mul_cnt);
    printf("div counter used: %d\n", div_cnt);
    printf("fadd counter used: %d\n", fadd_cnt);
    printf("fsub counter used: %d\n", fsub_cnt);
    printf("fmul counter used: %d\n", fmul_cnt);
    printf("fdiv counter used: %d\n", fdiv_cnt);
    printf("lw counter used: %d\n", lw_cnt);
    printf("sw counter used: %d\n", sw_cnt);
    printf("others counter used: %d\n", others_cnt);
	
    macro_fft_cycle_count
    printf("The total cycle count in this program: %.0f\n", fft_cycle_count);

    macro_fft_cpu_time
    printf("CPU time = %f us\n", fft_cpu_time);
    
    macro_calc_fft_ratio
    
    if(fft_ratio > 0.5){
        printf("This program is a CPU bound task.\n");
        }
    else{
        printf("This program is a Memory bound task.\n");
        }

    return 0;
}
