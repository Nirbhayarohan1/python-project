#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the last node in the circular linked list
struct Node* deleteLastNode(struct Node* last) {
    if (last == NULL) {
        // If the list is empty
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    struct Node* head = last->next;

    // If there is only one node in the list
    if (head == last) {
        free(last);
        last = NULL;
        return last;
    }
    // Traverse the list to find the second last node
    struct Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }
    // Update the second last node's next pointer to point to head
    curr->next = head;
    free(last);
    last = curr;

    return last;
}

void printList(struct Node* last) {
    if (last == NULL) return;

    struct Node* head = last->next;
    while (1) {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next) break;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node* first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node* last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Delete the last node
    last = deleteLastNode(last);

    printf("List after deleting last node: ");
    printList(last);

    return 0;
}
