/*
Q1. print 
    ****
    ****
    ****

Q2. print even no. 1 to 100

Q3. print 
    *
    **
    ***
*/

#include<stdio.h>

int main() {

    /*
    int n = 3;
    int m = 4;
    
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) {
            printf("* ");
        }
        printf(" \n");
    }
    */
    
    // Q2  

    /*
    int n = 100;
    for(int i = 0; i <= n; i++) {
        if (i%2 == 0)
        {
            printf("%d\n", i);
        } 
        
    }
    */


    // Q3

    int r, c, s;
    for (int r = 1; r <= 3; r++){
        for (int s = 3; s >= r; s--) {
            printf(" ");
        }
        for (int c = 1; c <= r; c++) {
            printf("* ");
        }
        printf("\n");
        
    }
    
    
    
    
}