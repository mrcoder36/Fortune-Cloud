#include<stdio.h>
#include<stdlib.h>

int main() {
    int arr[5] = {10,20,30,40,50};

    int size = sizeof(arr)/sizeof(arr[0]);
    int lr = 0, up = 4, mid, element, f=0;

    printf("Enter Searching item: ");
    scanf("%d", &element);

    while(lr<=up) {
        mid = lr + (up -lr)/2;
        if(arr[mid] == element) {
            f = 1;
            break;
        }
        if(arr[mid] < element) {
            lr = mid + 1;
        } else {
            up = mid - 1;
        }
    }
    if(f == 1) {
        printf("Element found at %d", mid);
        exit(0);
    } else {
        printf("Item not found");
    }
    return 0;
}