//  Simple Interest program  -----------
//  Formula SI = P*r*t/100
// where p = principle interest,  r = annual Interest rate, t = time
#include <stdio.h>

int main()
{

    int p, r, t;
    float SI;

    printf("Enter the principle amount: ");
    scanf("%d", &p);

    printf("Enter the rate amount: ");
    scanf("%d", &r);

    printf("Enter the time: ");
    scanf("%d", &t);

    SI = (p * r * t) / 100.0; 

    printf("The Simple Interest is %.2f", SI);

    return 0;
}