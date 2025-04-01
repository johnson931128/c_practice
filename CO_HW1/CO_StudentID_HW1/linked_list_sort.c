#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Split the linked list into two parts
void splitList(Node *head, Node **firstHalf, Node **secondHalf)
{
    asm volatile(
        /*
        Block A (splitList), which splits the linked list into two halves
        */
	"mv t0, %[head]\n"
	"lw t1, 4(%[head])\n"

	"splitLoop%=:\n"
	"lw t1, 4(t1)\n"
	"beq t1, zero, finish%=\n"
	"lw t1, 4(t1)\n"

	"lw t0, 4(t0)\n"
	"bne t1, zero, splitLoop%=\n"

	"finish%=:\n"
	"lw t2, 4(t0)\n"
	"sw zero, 4(t0)\n"

	"sd %[head], 0(%[fh_ptr_addr])\n"
	"sd t2, 0(%[sh_ptr_addr])\n"
	:
	: [head] "r" (head), [fh_ptr_addr] "r" (firstHalf), [sh_ptr_addr] "r" (secondHalf)
	: "t0", "t1", "t2", "memory"
	);
}

// Merge two sorted linked lists
Node *mergeSortedLists(Node *a, Node *b)
{
    Node *result = NULL;
    Node *tail = NULL;

    asm volatile(
        /*
        Block B (mergeSortedList), which merges two sorted lists into one
        */
	// end logic
	"beq %[a], zero, check_b_null%=\n"
	"beq %[b], zero, a_is_result%=\n"
	"j determine_first_node%=\n"

	"check_b_null%=:\n"
	"mv %[result], %[b]\n"
	"j end%=\n"

	"a_is_result%=:\n"
	"mv %[result], %[a]\n"
	"j end%=\n"

	"determine_first_node%=:\n"
	"lw t0, 0(%[a])\n"
	"lw t1, 0(%[b])\n"
	"ble t0, t1, first_is_a%=\n"

	"first_is_b%=:\n"
	"mv %[result], %[b]\n"
	"mv %[tail], %[b]\n"
	"lw %[b], 4(%[b])\n"
	"j merge_loop_start%=\n"

	"first_is_a%=:\n"
	"mv %[result], %[a]\n"
	"mv %[tail], %[a]\n"
	"lw %[a], 4(%[a])\n"

	"merge_loop_start%=:\n"
	"beq %[a], zero, append_b_%= \n"
	"beq %[b], zero, append_a_%= \n"
	// initialize a and b to t0 and t1
	"lw t0, 0(%[a])\n"
	"lw t1, 0(%[b])\n"
	// if t1<t0 go to choose b else a
	"blt t1, t0, choose_a_loop%=\n"
	// choose who will be first
	"choose_b_loop%=:\n"
	"sw %[b], 4(%[tail])\n"
	"mv %[tail], %[b]\n"
	"lw %[b], 4(%[b])\n"
	"j merge_loop_start%=\n"

	"choose_a_loop%=:\n"
	"sw %[a], 4(%[tail])\n"
	"mv %[tail], %[a]\n"
	"lw %[a], 4(%[a])\n"
	"j merge_loop_start%=\n"

	"append_b_%=:\n"
	"sw %[b], 4(%[tail])\n"
	"j end%=\n"
	// let a or b be the head
	// let result = a, taile = a
	"append_a_%=:\n"
	"sw %[a], 4(%[tail])\n"
	"j end%=\n"

	"end%=:\n"
	:[result] "+r" (result), [tail] "+r" (tail), [a] "+r" (a), [b] "+r" (b)
	:
	: "t0", "t1", "memory"
	);

    return result;
}

// Merge Sort function for linked list
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head; // Return directly if there is only one node

    Node *firstHalf, *secondHalf;
    splitList(head, &firstHalf,
              &secondHalf); // Split the list into two sublists

    firstHalf = mergeSort(firstHalf);   // Recursively sort the left half
    secondHalf = mergeSort(secondHalf); // Recursively sort the right half

    return mergeSortedLists(firstHalf, secondHalf); // Merge the sorted sublists
}

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
    int list_size;
    fscanf(input, "%d", &list_size);
    Node *head = (list_size > 0) ? (Node *)malloc(sizeof(Node)) : NULL;
    Node *cur = head;
    for (int i = 0; i < list_size; i++) {
        fscanf(input, "%d", &(cur->data));
        if (i + 1 < list_size)
            cur->next = (Node *)malloc(sizeof(Node));
        cur = cur->next;
    }
    fclose(input);

    // Linked list sort
    head = mergeSort(head);

    cur = head;
    while (cur) {
        printf("%d ", cur->data);
        asm volatile(
            /*
            Block C (Move to the next node), which updates the pointer to
            traverse the linked list
            */
	/*
	            Equivalent C: cur = cur->next;
            Assumes 'cur' holds the pointer to the current Node.
            Assumes 'next' is at offset 4 bytes from the start of the Node.

	*/
        "lw %[cur_ptr], 4(%[cur_ptr])\n"
	: [cur_ptr] "+r" (cur)
	:
	: "memory"
	);
    }
    printf("\n");


    cur = head;
    while(cur != NULL){
	Node *temp = cur;
	cur = cur -> next;
	free(temp);
    }
    return 0;
}

