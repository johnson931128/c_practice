# Computer Organization HW0 - Environmental Setup and Introduction to RISC-V assembly

## Directory Structure
```
CompOrg2025_HW0/
├── answer                      # Reference answer of programming exercises
│   ├── arith.c
│   └── array_arith.c
├── CO_StudentID_HW0            # Programming exercises (To be completed by students)
│   ├── arith.c
│   ├── array_arith.c
│   ├── judge1.conf
│   ├── judge2.conf
│   └── Makefile
├── README.md                   # This file!
├── rv_toolchain_test           # RISC-V toolchain test suite
│   ├── hello.c
│   ├── Makefile
│   └── vadd.c
└── testcases
    ├── expected                # Expected correct outputs
    └── input                   # Input data of testcases
```

## RISC-V toolchains verification
After building the tools or importing the virtual machine image, you can verify your installation with the provided test suite.
To start with, clone this repository:
```shell
$ git clone https://github.com/ASRLabCourses/CompOrg2025_HW0
```
Navigate to `rv_toolchain_test` and run the test suite:
```shell
$ cd CompOrg2025_HW0/rv_toolchain_test
$ make all 
```
The output should resemble following:
```text
make: [Makefile:24: clean] Error 1 (ignored)
riscv64-unknown-linux-gnu-gcc -static -march=rv64gcv -o hello hello.c
spike --isa=RV64GCV /opt/riscv/riscv64-unknown-linux-gnu/bin/pk hello
Hello World from RISC-V!
riscv64-unknown-linux-gnu-gcc -static -march=rv64gcv -o vadd vadd.c
spike --isa=RV64GCV /opt/riscv/riscv64-unknown-linux-gnu/bin/pk vadd
p_a: 1, 1, 1, 1, 1, 1, 1, 1,
p_b: 0, 1, 2, 3, 4, 5, 6, 7,
p_c: 1, 2, 3, 4, 5, 6, 7, 8,
```

## Programming Exercises
The programming exercises in Homework 0 are designed to familiarize students with RISC-V assembly language.

### Instructions
* Complete the code in the `CO_StudentID_HW0` directory using only inline assembly.
* Refer to the homework document for detailed instructions.
* Reference answers provided by TAs can be found in the `answer` directory.

