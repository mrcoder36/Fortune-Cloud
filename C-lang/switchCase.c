#include <stdio.h>

int main() {
    int time = 12;

    switch (time)
    {
        case 9:
            printf("Good Morning");
        break;

        case 12:
            printf("Good Afternoon");
        break;

        case 4:
            printf("Good Evening");
        break;

        case 10:
            printf("Good Night");
        break;

        default:
            printf("Unkown");
        break;
    
    }

}