#include <stdio.h>

void main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index;

    printf("Enter index: ");
    scanf("%d", &index);

    printf("On index %d is: %d\n", index, arr[index]);
}