#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
int numCities;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == (1 << numCities) - 1) {
        return graph[pos][0];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < numCities; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = graph[pos][city] + tsp(mask | (1 << city), city);
            minCost = min(minCost, newCost);
        }
    }

    return minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int minTourCost = tsp(1, 0);  // Start from city 0
    printf("Minimum tour cost: %d\n", minTourCost);

    return 0;
}
