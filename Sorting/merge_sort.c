//Merge Sort Technique
#include<stdio.h>
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int NL = middle - left + 1;
    int NR = right - middle;
    int L[NL], R[NR];

    for (i = 0; i < NL; i++)
        L[i] = arr[left + i];
    for (j = 0; j < NR; j++)
        R[j] = arr[middle + 1 + j];

    i = 0; j = 0; k = left;
    while (i < NL && j < NR) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < NL)
        arr[k++] = L[i++];
    while (j < NR)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
