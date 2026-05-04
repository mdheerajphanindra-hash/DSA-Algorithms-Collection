#include <stdio.h>

int binarySearch(int array[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == key) {
            return mid;
        }
        else if (array[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements in ascending order: ");
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = binarySearch(array, n, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
