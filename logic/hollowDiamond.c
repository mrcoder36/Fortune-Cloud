#include <stdio.h>

int main()
{
    int rows, i, j;

    printf("Enter the number of rows for the diamond (odd number recommended): ");
    scanf("%d", &rows);

    // Upper half of the diamond
    for (i = 1; i <= rows; i++)
    {
        // Print leading spaces
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        // Print stars and inner spaces
        for (j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            { // First and last character of the row
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Lower half of the diamond
    for (i = rows - 1; i >= 1; i--)
    {
        // Print leading spaces
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        // Print stars and inner spaces
        for (j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            { // First and last character of the row
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}