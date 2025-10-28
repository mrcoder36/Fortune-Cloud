// Compound Interest Calculator
// ci = p * pow((1 + r / n), (n * t));

#include <stdio.h>
#include <math.h>

int main()
{

    float p, r, t, n, CI, A;

    printf("Enter the principle amount: ");
    scanf("%f", &p);

    printf("Enter the rate: ");
    scanf("%f", &r);
    r = r / 100; // to decimal

    printf("Enter the time: ");
    scanf("%f", &t);

    printf("Enter the number of time compounded annually: ");
    scanf("%f", &n);

    A = p * pow((1 + r / n), (n * t));

    CI = A - p;

    printf("The Final Amount is %.2f\n", A);
    printf("The Compound Interest is %.2f\n", CI);

    return 0;
}