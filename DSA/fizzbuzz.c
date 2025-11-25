#include <stdio.h>
int main() {

    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("\n%d FizzBuzz", i);
        } else if (i % 3 == 0) {
            printf("\n%d Fizz", i);
        } else if (i % 5 == 0) {
            printf("\n%d Buzz", i);
        } else {
            printf("\n%d", i);
        }
    }
}
