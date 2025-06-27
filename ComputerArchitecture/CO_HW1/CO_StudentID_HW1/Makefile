CC := riscv64-unknown-linux-gnu-gcc
CFLAGS := -static
TARGET := 1 2 3
v := 0

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^
1: array_sort.c
	$(CC) $(CFLAGS) -o $@ $^
2: array_search.c
	$(CC) $(CFLAGS) -o $@ $^
3: linked_list_sort.c
	$(CC) $(CFLAGS) -o $@ $^

	
judge: all
	-judge -c judge1.conf  
	@printf "or \`judge -c judge1.conf -v 1\n\`"
	-judge -c judge2.conf
	@printf "or \`judge -c judge2.conf -v 1\n\`"
	-judge -c judge3.conf
	@printf "or \`judge -c judge3.conf -v 1\n\`"

clean:
	rm -f $(TARGET)
