#include <stdio.h>


void display() {
    int a = 10;
    static int b = 10;

    a = a+1;
    b = b+1;
    printf("\n%d, %d", a, b);
}

void main(){

    display();
    display();
    display();
    return 0;
}