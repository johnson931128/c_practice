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
    asm volatile(/* Your Code */);

    p_c = c;
    for (int32_t i = 0; i < arr_size; i++)
        printf("%d ", *p_c++);
    printf("\n");
    return 0;
}
