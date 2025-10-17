//  recursion is a functions it calls itself and control by the condition.

#include <stdio.h>

// factorial---------------------------->

// long fact(int p ) {
//     if(p >= 1) {
//         return p*fact(p-1);
//     } else {
//         return 1;
//     }
// }

// Sum from n up to 10 (if n <= 10)
int sum(int n) {
    if (n <= 10) {
        return n + sum(n + 1); // add current n and recurse with n+1
    } else {
        printf("Reached base case with n = %d\n", n);
        return 0; // base case: if n exceeds 10, stop
    }
}

int main() {

    int n;
    printf("Enter the +ve number: ");
    scanf("%d", &n);

    // printf("The factorial of %d = %d", n, fact(n));  factorial

    printf("Sum from %d to 10 = %d\n", n, sum(n));

    return 0;
}