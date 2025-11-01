

#include <stdio.h>

void main()
{

    int count = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            count++;
            printf("%d  ",count);
        }
        printf("\n");
    }
}