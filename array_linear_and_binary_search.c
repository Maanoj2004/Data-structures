#include <stdio.h>

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Linear search
    int linearIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            linearIndex = i;
            break;
        }
    }
    if (linearIndex != -1) {
        printf("Linear search: Element %d found at index %d.\n", target, linearIndex);
    } else {
        printf("Linear search: Element %d not found.\n", target);
    }

    // Binary search
    int binaryIndex = -1;
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            binaryIndex = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (binaryIndex != -1) {
        printf("Binary search: Element %d found at index %d.\n", target, binaryIndex);
    } else {
        printf("Binary search: Element %d not found.\n", target);
    }

    return 0;
}
