#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct GraphNode {
    int data;
    struct GraphNode* next;
};

struct Graph {
    int numNodes;
    struct GraphNode* adjacencyList[MAX_NODES];
};

struct GraphNode* createNode(int data) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void printPathsDFS(struct Graph* graph, int currentNode, int destination, bool visited[], int path[], int pathLength) {
    visited[currentNode] = true;
    path[pathLength] = currentNode;
    pathLength++;

    if (currentNode == destination) 
    {
        for (int i = 0; i < pathLength; i++) 
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    } 
    else 
    {
        struct GraphNode* currentNeighbor = graph->adjacencyList[currentNode];
        while (currentNeighbor != NULL) 
        {
            if (!visited[currentNeighbor->data]) 
            {
                printPathsDFS(graph, currentNeighbor->data, destination, visited, path, pathLength);
            }
            currentNeighbor = currentNeighbor->next;
        }
    }

    visited[currentNode] = false;
}

int main() 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = 5;

    for (int i = 0; i < graph->numNodes; i++) 
    {
        graph->adjacencyList[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int startNode, endNode;
    printf("Enter the starting node: ");
    scanf("%d",&startNode);
    printf("Enter the ending node: ");
    scanf("%d",&endNode);

    bool visited[MAX_NODES] = {false};
    int path[MAX_NODES];
    int pathLength = 0;

    printf("Valid paths between %d and %d:\n", startNode, endNode);
    printPathsDFS(graph, startNode, endNode, visited, path, pathLength);

    return 0;
}
