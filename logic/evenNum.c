#include <stdio.h>

int main() {
    int num;
    printf("Enter an Integer: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("The Number is even...");
    } else {
        printf("The number is odd...");
    }
    
}