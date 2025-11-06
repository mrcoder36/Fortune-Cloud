// Area of Square
// formula = area = a*a;

#include <stdio.h>

int main() {

    int side;
    float area;

    printf("Enter the side of Square: ");
    scanf("%d", &side);

    area = side * side;

    printf("The area of square is %.2f", area);

    return 0;
}