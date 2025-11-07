#include<stdio.h>

void main() {
    int arr[5] = {1,2,3,4,5};
    int i;
    arr[5] = 6;
    for (i=0; i<6; i++) {
        printf("%d ", arr[i]);
    }
    
    
}