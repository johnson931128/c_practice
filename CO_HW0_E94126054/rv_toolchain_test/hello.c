#ifdef __riscv
#include <stdio.h>
int main()
{
    printf("Hello World from RISC-V!\n");
    return 0;
}
#else
#error Please make sure you are compiling with riscv64-unknown-linux-gnu-gcc, abort.
#endif
