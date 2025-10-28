#include <stdio.h>


int swap(int a, int b) {
    printf("\n After function calling a = %d and b = %d", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("\n After swapping a = %d", a, b);
}

int main() {
    int a = 10;
    int b = 20;
    printf("\n Before function calling a = %d and b = %d", a, b);
    swap(a, b);
    printf("\n After swapping a = %d", a, b);
    return 0;
}