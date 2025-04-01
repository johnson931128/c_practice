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
	"mv t1, %[head]\n"

	"splitLoop%=:\n"
	"beq t1, zero, finish%=\n"
	"lw t1, 4(t1)\n"
	"beq t1, zero, finish%=\n"
	"lw t1, 4(t1)\n"

	"lw t0, 4(t0)"
	"j splitLoop%=\n"

	"finish%=:\n"
	"lw t2, 4(t0)\n"
	"sw zero, 4(t0)\n"
	"mv %[firstHalf], %[he	ad]\n"
	"mv %[secondHalf], t2\n"
	:
	: [head] "r" (head), [firstHalf] "r" (*firstHalf), [secondHalf] "r" (*secondHalf)
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
        "merge_loop%=:\n"
	"beq %[a], zero, merge_done%=\n"
	"beq %[b], zero, merge_done%=\n"
	// initialize a and b to t0 and t1
	"lw t0, 0(%[a])\n"
	"lw t1, 0(%[b])\n"
	// if t1<t0 go to choose b else a
	"blt t1, t0, choose_b%=\n"
	"j choose_a%=\n"
	// choose who will be first
	"choose_a%=:\n"
	"beq %[result], zero, first_a%=\n"
	"sw %[a], 4(%[tail])\n"
	"j update_tail_a%=\n"

	"choose_b%=:\n"
	"beq %[result], zero, first_b%=\n"
	"sw %[b], 4(%[tail]\n"
	"j update_tail_b%=\n"

	// let a or b be the head
	// let result = a, taile = a
	"first_a%=:\n"
	"mv %[result], %[a]\n"
	"mv %[tail], %[a]\n"
	"j merge_loop%=\n"
	// choose b
	"first_b%=:\n"
	"mv %[result], %[b]\n"
	"mv %[tail], %[b]\n"
	"j update_tail_b%=\n"

	// update tail and let t0 = a->next & t1 = b->next
	"update_tail_a%=:\n"
	"lw %[a], 4(%[a]\n"
	"j merge_loop%=\n"

	"update_tail_b%=:\n"
	"lw %[b] 4(%[b]\n"
	"j merge_loop%=\n"

	// if finsish (end)
	// split to cheak a or b who finish
	"merge_done%=:\n"
	"beq %[a], zero, check_b%=\n"
	"sw %[a], 4(%[tail])\n"
	"j end%=\n"

	"cheack_b%=:\n"
	// if b -> next = null both end
	"beq %[b], zero, end%=\n"
	"sw %[b], 4(%[tail])\n"

	"end%=:\n"
	: [result] "+r" (result), [tail] "+r" (tail), [a] "+r" (a), [b] "+r" (b)
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
            "");
    }
    printf("\n");
    return 0;
}

