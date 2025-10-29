#include<stdio.h>

int main() {
    int num = 12934;
    int sum = 0;
    int rem = 0;

    
    while(num != 0) {
        rem = num % 10;
        sum = sum + rem;
        num = num / 10;
    }
    printf("Total sum %d", sum);
}