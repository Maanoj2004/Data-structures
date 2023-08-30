#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjacencyList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    // Assuming the graph is undirected
    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void shortestPath(Node* adjacencyList[], int numVertices, int startVertex) {
    int distances[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
    }

    Queue* queue = createQueue(numVertices);
    distances[startVertex] = 0;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        Node* temp = adjacencyList[currentVertex];

        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = distances[currentVertex] + 1;
                enqueue(queue, neighbor);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    Node* adjacencyList[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = NULL;
    }

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjacencyList, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    shortestPath(adjacencyList, numVertices, startVertex);

    return 0;
}
