#include <stdint.h>
#include <stdio.h>

int main()
{
    int32_t a, b;
    FILE *input = fopen("../testcases/input/1.txt", "r");
    fscanf(input, "%d %d", &a, &b);
    fclose(input);
    /* a = a - b */
    asm volatile(/* Your Code */);
    printf("%d\n", a);
    return 0;
}
