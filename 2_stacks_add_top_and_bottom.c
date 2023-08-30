#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to print the bottom-most and top-most elements of a stack
void printBottomTop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Bottom-most element: %d\n", stack->items[0]);
    printf("Top-most element: %d\n", stack->items[stack->top]);
}

int main() {
    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    // Push elements onto stack1
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    // Push elements onto stack2
    push(&stack2, 100);
    push(&stack2, 200);
    push(&stack2, 300);

    // Print bottom-most and top-most elements of stack1
    printf("Stack 1:\n");
    printBottomTop(&stack1);

    // Print bottom-most and top-most elements of stack2
    printf("Stack 2:\n");
    printBottomTop(&stack2);

    return 0;
}
