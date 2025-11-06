#include<stdio.h>

void main() {
    int r, c, s;
    for(r=0; r<4; r++) {
        for(s=0; s<2*2-r; s++) {
            printf(" ");
        }
        for (c=0; c<=r; c++) {
            printf("1");
            
        }
        printf("\n");
    }
}