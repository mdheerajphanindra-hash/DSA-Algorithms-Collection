//Bucket Sort Technique
#include <stdio.h>
#include <stdlib.h>
struct Node {
    float data;
    struct Node* next;
};
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex] = insertSorted(buckets[bucketIndex], arr[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d elements (values between 0 and 1): ", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
