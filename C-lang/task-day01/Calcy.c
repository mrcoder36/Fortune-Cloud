#include<stdio.h>

int main() {
    int x, y;
    
    char choice;

    printf("Enter the first number: ");
    scanf("%d", &x);

    printf("Enter the choice (+, -, *, /) : ");
    scanf(" %c", &choice);

    printf("Enter the second number: ");
    scanf("%d", &y);

    switch (choice)
    {
    case '+' :
        printf("%d + %d = %d\n", x, y, x+y);
        break;

    case '-' :
        printf("%d - %d = %d\n", x, y, x-y);
        break;

    case '*' :
        printf("%d * %d = %d\n", x, y, x*y);
        break;

    case '/' :
        printf("%d / %d = %d\n", x, y, x/y);
        break;
    
    default:
        printf("Invalid input!!");
        break;
    }
}