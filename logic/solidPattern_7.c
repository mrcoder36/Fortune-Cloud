#include<stdio.h>

int main() {
    int r, c;
    
    for (r = 1; r < 5; r++) {
        for (c = 1; c < 6; c++) {
            if (r==1 || r==4 || c==1 || c==5) {
                if (r%2==0) {
                    printf("A");
                } else {
                    printf("B");
                }
            } else {
                printf(" ");
            }
            
        }
        printf("\n");
        
    }
    
}