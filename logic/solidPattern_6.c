#include<stdio.h>

int main() {
    int r, c;
    int num;
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 5; c++) {
            if (r==0 || r==3 || c==0 || c==4) {
                if (r%2==0) {
                    printf("1");
                } else {
                    printf("0");
                }
            } else {
                printf(" ");
            }
            
        }
        printf("\n");
        
    }
    
}