#include<stdio.h>

int main() {
    // int n= 100;
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d\n",i);
    // }


    // while loops
    // Use when we dont know the count of loops

    // syntax:      initialization
    //              while(condition) {
    //                  statement
    //                  increment\decrement
    //              }

    // Print Happy Diwali 100 times using while loop
    // int i = 1;
    // while (i <= 100)
    // {
    //     printf("Happy Diwali...\n");
    // }
    
    
    // int n = 5;
    // for(int i =0; i<=5; i++){
    //     printf("* ");
    // }
    // Print Happy Diwali Using Do while loop
    // want to print statement atleast once if condition gets false
    /*syntax: init..
                do{
                    statement
                    increment/decrement
                    } while(condition)
    */
    int i = 1;
    do {
        printf("Happy Diwali..\n");
        i++;
    } while(i <= 100);
}