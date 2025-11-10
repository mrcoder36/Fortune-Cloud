#include <stdio.h>

void main()
{
    int arr[6] = {2, 3, 4, 5, 6};

    int i;
    int ele = 1;
    

    for(i = 5; i >= 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = ele;

    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}