#include <stdio.h>

/* Simple calculator functions that take two integers as input. */

void addition(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void subtraction(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

void multiplication(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

void division(int a, int b) {
    if (b == 0) {
        printf("Error: division by zero (%d / %d)\n", a, b);
        return;
    }
    printf("%d / %d = %d\n", a, b, a / b);
}

int main(void) {
    /* Example calls */
    addition(2, 5);
    subtraction(2, 5);
    multiplication(2, 5);
    division(2, 5);
    division(2, 0); /* demonstrate safe handling */

    return 0;
}