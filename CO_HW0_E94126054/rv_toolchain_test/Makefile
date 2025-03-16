.PHONY: clean all

CC:=riscv64-unknown-linux-gnu-gcc
CFLAGS:= -static -march=rv64gcv
PK:=$(RISCV)/riscv64-unknown-linux-gnu/bin/pk
SPIKE:=spike
SPIKE_FLAG:=--isa=RV64GCV

all: clean check_hello check_vadd

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $^

vadd: vadd.c
	$(CC) $(CFLAGS) -o $@ vadd.c

check_hello: hello
	$(SPIKE) $(SPIKE_FLAG) $(PK) $^

check_vadd: vadd
	$(SPIKE) $(SPIKE_FLAG) $(PK) $^

clean:
	@- rm hello vadd >/dev/null 2>&1
