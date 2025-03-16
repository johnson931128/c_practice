#include <stdint.h>
#include <stdio.h>

int main()
{
    int32_t a, b;
    FILE *input = fopen("../testcases/input/1.txt", "r");
    fscanf(input, "%d %d", &a, &b);
    fclose(input);
    asm volatile("sub %[A], %[A], %[B]\n\t" : [A] "+r"(a) : [B] "r"(b));
    printf("%d\n", a);
    return 0;
}
