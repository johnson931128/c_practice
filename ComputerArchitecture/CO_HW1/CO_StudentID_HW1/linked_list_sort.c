#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
// pointer in C is 8 bytes
// Split the linked list into two parts
void splitList(Node *head, Node **firstHalf, Node **secondHalf)
{
    asm volatile(
        /*
        Block A (splitList), which splits the linked list into two halves
        */
        "beqz %[head], end_split%=\n"          // If head is NULL, exit
        
        "mv t0, %[head]\n"                     // slow = head
        "mv t1, %[head]\n"                     // fast = head
        "mv t2, zero\n"                        // prev = NULL
        
        "find_middle%=:\n"
        "ld t3, 8(t1)\n"                       // t3 = fast->next
        "beqz t3, break_middle%=\n"            // if fast->next == NULL, break
        "ld t4, 8(t3)\n"                       // t4 = fast->next->next
        "beqz t4, break_middle%=\n"            // if fast->next->next == NULL, break
        
        "mv t2, t0\n"                          // prev = slow
        "ld t0, 8(t0)\n"                       // slow = slow->next
        "mv t1, t4\n"                          // fast = fast->next->next
        "j find_middle%=\n"
        
        "break_middle%=:\n"
        "beqz t0, end_split%=\n"               // If slow is NULL, exit
        "ld t3, 8(t0)\n"                       // t3 = slow->next
        
        "sd %[head], 0(%[fh_ptr_addr])\n"      // *firstHalf = head
        "sd t3, 0(%[sh_ptr_addr])\n"           // *secondHalf = slow->next

        "li t4, 0\n"                           // t4 = NULL
        "sd t4, 8(t0)\n"                       // slow->next = NULL
        "j end_split%=\n"
        "end_split%=:\n"
        :
        : [head] "r" (head), [fh_ptr_addr] "r" (firstHalf), [sh_ptr_addr] "r" (secondHalf)
        : "t0", "t1", "t2", "t3", "t4", "memory"
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
        // Check if either list is NULL
        "beqz %[a], a_is_null%=\n"
        "beqz %[b], b_is_null%=\n"
        
        // Compare first nodes
        "lw t0, 0(%[a])\n"                     // t0 = a->data
        "lw t1, 0(%[b])\n"                     // t1 = b->data
        "ble t0, t1, choose_a_first%=\n"       // if a->data <= b->data, choose a
        "j choose_b_first%=\n"
        
        "a_is_null%=:\n"
        "mv %[result], %[b]\n"                 // result = b
        "j end_merge%=\n"
        
        "b_is_null%=:\n"
        "mv %[result], %[a]\n"                 // result = a
        "j end_merge%=\n"
        
        "choose_a_first%=:\n"
        "mv %[result], %[a]\n"                 // result = a
        "mv %[tail], %[a]\n"                   // tail = a
        "ld %[a], 8(%[a])\n"                   // a = a->next
        "j merge_loop%=\n"
        
        "choose_b_first%=:\n"
        "mv %[result], %[b]\n"                 // result = b
        "mv %[tail], %[b]\n"                   // tail = b
        "ld %[b], 8(%[b])\n"                   // b = b->next
        "j merge_loop%=\n"
        
        "merge_loop%=:\n"
        "beqz %[a], attach_b%=\n"              // if a is NULL, attach b
        "beqz %[b], attach_a%=\n"              // if b is NULL, attach a
        
        "lw t0, 0(%[a])\n"                     // t0 = a->data
        "lw t1, 0(%[b])\n"                     // t1 = b->data
        "ble t0, t1, attach_next_a%=\n"        // if a->data <= b->data, attach a
        
        "sd %[b], 8(%[tail])\n"                // tail->next = b
        "mv %[tail], %[b]\n"                   // tail = b
        "ld %[b], 8(%[b])\n"                   // b = b->next
        "j merge_loop%=\n"
        
        "attach_next_a%=:\n"
        "sd %[a], 8(%[tail])\n"                // tail->next = a
        "mv %[tail], %[a]\n"                   // tail = a
        "ld %[a], 8(%[a])\n"                   // a = a->next
        "j merge_loop%=\n"
        
        "attach_a%=:\n"
        "sd %[a], 8(%[tail])\n"                // tail->next = a
        "j end_merge%=\n"
        
        "attach_b%=:\n"
        "sd %[b], 8(%[tail])\n"                // tail->next = b
        "j end_merge%=\n"
        
        "end_merge%=:\n"
        : [result] "+r" (result), [tail] "+r" (tail), [a] "+r" (a), [b] "+r" (b)
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
    Node *head = NULL;
    Node *tail = NULL;
    
    for (int i = 0; i < list_size; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (!new_node) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        
        fscanf(input, "%d", &(new_node->data));
        new_node->next = NULL;
        
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    fclose(input);

    // Print original list for debugging
    /*
    printf("Original list: ");
    Node *debug = head;
    while (debug) {
        printf("%d ", debug->data);
        debug = debug->next;
    }
    printf("\n");
    */

    // Linked list sort
    head = mergeSort(head);

    // Print sorted list
    Node *cur = head;
    while (cur) {
        printf("%d ", cur->data);
        asm volatile(
            /*
            Block C (Move to the next node), which updates the pointer to
            traverse the linked list
            */
            "ld %[cur_ptr], 8(%[cur_ptr])\n"
            : [cur_ptr] "+r" (cur)
            :
            : "memory"
        );
    }
    printf("\n");

    // Free memory
    cur = head;
    while (cur) {
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }
    
    return 0;
}
