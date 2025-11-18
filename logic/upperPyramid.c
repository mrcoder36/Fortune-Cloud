#include<stdio.h>

void main() {
    int r, c, s;
    // Upper Pyramid
    for(r = 0; r < 5; r++) {
        for(s = 1; s <= 5-r; s++) {
            printf(" ");
        }
        for(c = 1; c <= (2*r-1); c++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower Pyramid
    for(r = 5; r >= 1; r--) {
        for(s = 1; s <= 5-r; s++) {
            printf(" ");
        }
        for(c = 1; c <= (2*r-1); c++) {
            printf("*");
        }
        printf("\n");
    }
    
}