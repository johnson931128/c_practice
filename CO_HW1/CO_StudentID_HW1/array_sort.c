#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }
    int arr_size;
    fscanf(input, "%d", &arr_size);
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++) {
        fscanf(input, "%d", &arr[i]);
    }
    fclose(input);

    int *p_a = &arr[0];

    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            int *addr = p_a + j;
            asm volatile(
                "lw t0, 0(%[addr])\n"
                "lw t1, 4(%[addr])\n"
                "blt t1, t0, swap%=\n"
                "j continue%=\n"
                "swap%=:\n"
                "sw t1, 0(%[addr])\n"
                "sw t0, 4(%[addr])\n"
                "continue%=:\n"
                :
                : [addr] "r" (addr)
                : "t0", "t1", "memory"
            );
        }
    }

    p_a = &arr[0];
    for (int i = 0; i < arr_size; i++)
        printf("%d ", *p_a++);
    printf("\n");
    return 0;
}
