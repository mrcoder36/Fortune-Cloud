#include<stdio.h>

int main() {
    int arr[] = {1,2,3,4};

    // for (int i = 1 ; i < 4; i++) {
        
    //     for (int j = 0; j < 5; j++) {
    //         printf("A ");
    //     }
    //     printf("\n");
        
    // }
    // i = row
    // j = column 

    for (int i = 1 ; i < 8; i++) {
        
        for (int j = 0; j < 5; j++) {
            if (i %2 == 0){
                printf("B ");
            } else {
                printf("A ");
            }
            
        }
        printf("\n");
        
    }
    
    
}