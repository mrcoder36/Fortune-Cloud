#include<stdio.h>

void main() {
    int r, c, s;
    int n;
    
    for(r=0; r<5; r++) {
        for(s=0; s<2*2-r; s++) {
            printf(" ");
        }
        for(c=0; c<2*r+1; c++) {
            printf("*");
        }
        printf("\n");
    }
    
}