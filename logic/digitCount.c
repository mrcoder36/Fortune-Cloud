#include<stdio.h>

int main() {
    int num = 12346;
    int count = 0;
    while (num != 0) {
        int rem = num % 10;
        count++;
        num = num / 10;
    }
    printf("The number of digit is %d",count);
    
}