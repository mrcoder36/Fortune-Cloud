#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char str[10] = "Vishal";

    printf("%s\n", str);
    printf("4th index: ");

    for (int i = 0; i <= 4; i++) {
        printf("%c", str[i]);
    }
}