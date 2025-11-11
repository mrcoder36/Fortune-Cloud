#include<stdio.h>

int main() {
    int count = 6;
    for (int i = 1; i <= count; i++) {

        for (int j = 1; j <= count-i; j++) {
            printf(" ");
        }

        for (int k = 1; k <= 2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = count -1; i >= 1; i--) {

        for (int j = 1; j <= count-i; j++) {
            printf(" ");
        }

        for (int k = 1; k <= 2*i-1; k++) {
            printf("*");
        }
        printf("\n");    
    }
}