#include <stdint.h>
#include <stdio.h>

int main()
{
    int32_t a[10] = {0}, b[10] = {0}, c[10] = {0};
    int32_t i, arr_size = 10;
    FILE *input = fopen("../testcases/input/2.txt", "r");
    for (i = 0; i < arr_size; i++)
        fscanf(input, "%d", &a[i]);
    for (i = 0; i < arr_size; i++)
        fscanf(input, "%d", &b[i]);
    fclose(input);
    int32_t *p_a = a;
    int32_t *p_b = b;
    int32_t *p_c = c;
    /* Original C code segment
    for (int32_t i = arr_size; i != 0; i--)
        *p_c++ = *p_a++ - *p_b++;
    */
    asm volatile("add  t0, %[cnt], x0 \n\t" /* t0 = arr_size */
                 "loop:               \n\t"
                 "lw   t1, 0(%[A])    \n\t" /* t1 = *A */
                 "lw   t2, 0(%[B])    \n\t" /* t2 = *B */
                 "sub  t1, t1, t2     \n\t" /* t1 = t1 - t2 */
                 "sw   t1, 0(%[C])    \n\t" /* *C = t1 */
                 "addi t0, t0, -1     \n\t" /* t0-- */
                 "addi %[A], %[A], 4  \n\t" /* A++ */
                 "addi %[B], %[B], 4  \n\t" /* B++ */
                 "addi %[C], %[C], 4  \n\t" /* C++ */
                 "bnez t0, loop       \n\t" /* if (t0 != 0) goto loop */
                 : [A] "+r"(p_a), [B] "+r"(p_b), [C] "+r"(p_c)
                 : [cnt] "r"(arr_size)
                 : "t0", "t1", "t2");
    p_c = c;
    for (int32_t i = 0; i < arr_size; i++)
        printf("%d ", *p_c++);
    printf("\n");
    return 0;
}
