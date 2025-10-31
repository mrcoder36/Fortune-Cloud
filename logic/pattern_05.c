#include <stdio.h>

int main() {
    char ch = 'A';
    int r, c;
    
    for (r = 0; r < 3; r++) {       
        
        for (c = 0; c < 4; c++) {   
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }
    
}
