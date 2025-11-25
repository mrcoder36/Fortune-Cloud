#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j;
    for (j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        } 
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
    
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
}

int main() {
    int arr[] = {12,34,79,48,2,5,100,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");

    printArray(arr, n);

    printf("\n");
    
    quickSort(arr, 0, n - 1); // for dividing the array using 0, n-1

    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}