#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);

    struct Node* merged = NULL;
    struct Node* current = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            if (merged == NULL) {
                merged = current = temp1;
            } else {
                current->next = temp1;
                current = current->next;
            }
            temp1 = temp1->next;
        } else {
            if (merged == NULL) {
                merged = current = temp2;
            } else {
                current->next = temp2;
                current = current->next;
            }
            temp2 = temp2->next;
        }
    }

    if (temp1 != NULL) {
        current->next = temp1;
    } else {
        current->next = temp2;
    }

    printf("Merged list: ");
    printList(merged);

    free(head1);
    free(head2);

    return 0;
}
