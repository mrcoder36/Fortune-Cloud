// Area of TriAngle
// formula = 0.5 * height * base
#include <stdio.h>


int calculateArea(int height, int base) {

    return 0.5 * height * base;

}

int main() {

    int height, base;
    float triangleArea;

    printf("Enter the height of Triangle: ");
    scanf("%d", &height);

    printf("Enter the base of Triangle: ");
    scanf("%d", &base);

    triangleArea = calculateArea(height, base);
    printf("The Area of triangle is %.2f\n", triangleArea);

    return 0;
}

