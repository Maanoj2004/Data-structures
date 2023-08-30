#include <stdio.h>
#include <stdbool.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    bool missingFound = false;
    printf("Missing elements in the range %d to %d:\n", min, max);
    for (int i = min; i <= max; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            printf("%d\n", i);
            missingFound = true;
        }
    }

    if (!missingFound) {
        printf("No missing elements.\n");
    }

    return 0;
}
