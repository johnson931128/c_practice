#ifdef __riscv
#include <stdint.h>
#include <stdio.h>

#define SIZE 8
#define PRINT_ARR(arr)                                                         \
    do {                                                                       \
        size_t size = SIZE;                                                    \
        printf("" #arr ": ");                                                  \
        while (size--)                                                         \
            printf("%u, ", *arr++);                                            \
        putchar('\n');                                                         \
    } while (0);

static uint16_t A[SIZE] __attribute__((aligned(16))) = {1, 1, 1, 1, 1, 1, 1, 1};
static uint16_t B[SIZE] __attribute__((aligned(16))) = {0, 1, 2, 3, 4, 5, 6, 7};
static uint16_t C[SIZE] __attribute__((aligned(16))) = {0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
    uint16_t *p_a = A, *p_b = B, *p_c = C;
    asm volatile("vsetivli t0, 8, e16  \n\t"
                 "vle16.v v0, (%[p_a]) \n\t"
                 "vle16.v v1, (%[p_b]) \n\t"
                 "vadd.vv v2, v0, v1   \n\t"
                 "vse16.v v2, (%[p_c]) \n\t"
                 :
                 : [p_a] "r"(p_a), [p_b] "r"(p_b), [p_c] "r"(p_c)
                 : "t0", "v0", "v1", "v2");
    PRINT_ARR(p_a);
    PRINT_ARR(p_b);
    PRINT_ARR(p_c);
}
#else
#error Please make sure you are compiling with riscv64-unknown-linux-gnu-gcc, abort.
#endif
