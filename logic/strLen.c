#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char str[10] = "Vishal";

    int i;
    // int len = 0;
    for(i=0; i != '\0'; i++)
    {
        printf("%c", str[i]);
    }

}