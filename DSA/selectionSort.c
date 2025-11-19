#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


int main () {
    int arr[] = {3,5,2,7,9,6};

    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    selectionSort(arr, size);
    printf("\nSorted Array: ");
    printArray(arr, size);
    return 0;
}