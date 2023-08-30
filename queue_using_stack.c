#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

struct Stack* createStackNode(int data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack** top, int data) {
    struct Stack* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Stack* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

void enqueue(struct Queue* queue, int data) {
    push(&(queue->stack1), data);
}

int dequeue(struct Queue* queue) {
    if (queue->stack1 == NULL && queue->stack2 == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    if (queue->stack2 == NULL) {
        while (queue->stack1 != NULL) {
            int temp = pop(&(queue->stack1));
            push(&(queue->stack2), temp);
        }
    }

    return pop(&(queue->stack2));
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 4);

    printf("Dequeued: %d\n", dequeue(queue));

    return 0;
}
