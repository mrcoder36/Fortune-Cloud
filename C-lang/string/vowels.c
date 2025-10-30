#include<stdio.h>
#include<string.h>


int main() {
    char str[50];
    int i = 0, count = 0;

    printf("Enter the string: ");
    gets(str);

    while (str[i] != '\0') {
        if (str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' ||str[i]=='I' || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U') {
            count++;
        }
        i++;
    }
    printf("The count of vowels is: %d, count");

}