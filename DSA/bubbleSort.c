#include<stdio.h>

void bubbleSort(int arr[], int size) {
    int i;
    for ( i = 0; i < size - 1; i++) {
        int j;
        for (j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, size);
    printf("\nSorted Array: ");
    printArray(arr, size);
    return 0;
}