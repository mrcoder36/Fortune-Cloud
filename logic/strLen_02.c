#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() {
    char str[10] = "Vishal";

    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    
    printf("%s\n", str);
    printf("Length: %d", len);
}