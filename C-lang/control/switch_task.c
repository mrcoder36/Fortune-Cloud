#include <stdio.h>

int main() {

    int month = 10;


    switch (month)
    {
    case 1:
    case 2:
    case 10:  
    case 11:   
    case 12:
        printf("WINTER TIME!");
        break;

    case 3:
    case 4:
    case 5:
    case 6:
        printf("Summer time!");
        break;

    case 7:
    case 8:
    case 9:
        printf("Monsoon time!");
        break;

    default:
        break;
    }

}