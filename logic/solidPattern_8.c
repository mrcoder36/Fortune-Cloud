#include<stdio.h>

int main() {
    int r, c;
    int count = 0;
    for (r = 1; r < 4; r++) {
        for (c = 1; c < 5; c++) {
            if (r==1 || r==3 || c==1 || c==4) {
                count++;
                printf("%d",count);
            } else {
                printf(" ");
            }
            
        }
        printf("\n");
        
    }
    
}