#include <stdio.h>

int main() {

    int r, c;

    for (r = 1; r < 7; r++) {
        for (c = 1; c < 6; c++) {
            if(r==1 || r==4) {
                printf("1");
            } else if(r==2 || r==5) {
                printf("2");
            } else if (r==3 || r==6) {
                printf("3");
            }
        }
        printf("\n");
    } 

}
