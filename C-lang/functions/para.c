#include<stdio.h>

int addition(int a, int b) {  // parameter

    int c = a + b;
    // printf("The addition = %d", c);
    return c;  //   return functions


}

int main() {

    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);

    printf("Enter the 2st number: ");
    scanf("%d", &num2);

    printf("The Addition = %d", addition(num1, num2));  // argument 
}