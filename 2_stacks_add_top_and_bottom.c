#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int maxSize;
    int top;
    int* array;
};

struct Stack* createStack(int maxSize) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = maxSize;
    stack->top = -1;
    stack->array = (int*)malloc(maxSize * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->maxSize - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    struct Stack* bottomStack = createStack(10);
    struct Stack* topStack = createStack(10);

    
    push(bottomStack, 5);
    push(bottomStack, 10);
    push(topStack, 15);
    push(topStack, 20);

    
    if (!isEmpty(bottomStack)) {
        printf("Bottom-most element: %d\n", bottomStack->array[0]);
    } else {
        printf("Bottom stack is empty.\n");
    }

    if (!isEmpty(topStack)) {
        printf("Top-most element: %d\n", topStack->array[topStack->top]);
    } else {
        printf("Top stack is empty.\n");
    }

    free(bottomStack->array);
    free(bottomStack);
    free(topStack->array);
    free(topStack);

    return 0;
}
