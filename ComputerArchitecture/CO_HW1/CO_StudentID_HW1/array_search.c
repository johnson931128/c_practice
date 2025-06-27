#include <stdio.h>

int arraySearch(int *p_a, int arr_size, int target)
{
    int result = -1;

    asm volatile(
	"li t0, 0\n"
	"mv t4, %[arr_size]\n"
	"find_target_loop%=:\n"
	"bge t0, t4, no_found%=\n"
	"slli t1, t0, 2\n"
	"add t2, %[arr], t1\n"
	"lw t3, 0(t2)\n"
	"beq t3, %[target], found%=\n"
	"addi t0, t0, 1\n"
	"j find_target_loop%=\n"

	// if found
	"found%=:\n"
	"mv %[result], t0\n"
	"j end%=\n"

	// no found
	"no_found%=:\n"
	"li %[result], -1\n"

	// data&end
	"end%=:\n"
	: [result] "=r" (result)
	: [arr] "r" (p_a), [arr_size] "r" (arr_size), [target] "r" (target)
	: "t0", "t1", "t2", "t3","t4",  "memory"
    );

    return result;
}

// Main function to test the implementation
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

    // Read integers from input file into the array
    for (int i = 0; i < arr_size; i++) {
        int data;
        fscanf(input, "%d", &data);
        arr[i] = data;
    }
    int target;
    fscanf(input, "%d", &target);
    fclose(input);

    int *p_a = &arr[0];

    int index = arraySearch(p_a, arr_size, target);

    // Print the result
    printf("%d ", index);
    printf("\n");

    return 0;
}
