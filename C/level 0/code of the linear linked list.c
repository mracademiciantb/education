#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Node structure for the linked list
struct Node {
    int data;           // Data held by the node
    struct Node *next;  // Pointer to the next node in the list
};

// Function to add a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); // Allocate memory for the new node
    new_node->data = new_data; // Set the data for the new node
    new_node->next = (*head_ref); // The new node points to the current head
    (*head_ref) = new_node; // The new node becomes the new head
}

// Function to print all elements in the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data); // Print the data of the current node
        node = node->next; // Move to the next node
    }
}

// Function to sort the linked list using bubble sort algorithm
void bubbleSort(struct Node** head_ref) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL; // Pointer to the last element after which sorting is complete

    // Check if the list is empty
    if (*head_ref == NULL) return;

    do {
        swapped = 0; // Reset swapped to 0
        ptr1 = *head_ref; // Start from the head

        // Traverse the list up to the last sorted element
        while (ptr1->next != lptr) {
            // If the current node's data is greater than the next node's data, swap their data
            if (ptr1->data > ptr1->next->data) { 
                int temp = ptr1->data; // Temporary variable for swapping
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1; // Set swapped to 1 to indicate that a swap occurred
            }
            ptr1 = ptr1->next; // Move to the next node
        }
        lptr = ptr1; // Update the last sorted element
    }
    while (swapped); // If no swaps occurred in the last pass, the list is sorted
}

void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head; 
        head = head->next;
        free(temp); 
    }
}


int main() {
    srand(time(NULL)); // Seed the random number generator
    struct Node* head = NULL; // Initialize head to NULL

    int ran = 1000; // Maximum random number
    int num = 100; // Number of elements to add

    // Add 'num' random elements to the list
    for (int t = 0; t < num; t++) {
        push(&head, rand() % ran); // Add a new node with random data
    }

    // Add numbers 0 to 9 to the list
    for(int i = 0; i < 10; i++){
        push(&head, i); // Add a new node with data 'i'
    }

    // Sort the linked list
    bubbleSort(&head);

    printf("Sorted linked list: ");
    printList(head); // Print the sorted list
    
    // Freeing the memory allocated for the linked list
    freeList(head);

    return 0;
}
