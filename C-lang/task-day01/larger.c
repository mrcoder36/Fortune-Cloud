#include <stdio.h>

int main() {
    int a = 2, b = 5, c = 3;

    if(a >= b){
        if(a >= c) {
            printf("%d", a);
        } else {
            printf("%d", c);
        }
    } else {
        if(b >= c) {
            printf("%d", b);
        } else {
            printf("%d", c);
        }
    }
}