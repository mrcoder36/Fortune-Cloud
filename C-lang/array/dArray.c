#include <stdio.h>

int main() {
    int arr[5];
    arr[0] = 11;
    arr[1] = 22;
    arr[2] = 33;
    arr[3] = 44;
    arr[4] = 55;

    // printf("%d", arr[0]);
    // printf("%d", arr[1]);
    // printf("%d", arr[2]);
    // printf("%d", arr[3]);
    // printf("%d", arr[4]);

    for (int i = 0; i <= 4; i++) {
        printf("%d\n", arr[i]);
    }
    


}