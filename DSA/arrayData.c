#include <stdio.h>

void main()
{
    int arr[5];
    int i, index;

    printf("Enter elements: ");

    for(i = 0; i < 5; i++) { 
        scanf("%d", &arr[i]);
    }

    printf("Array reverse: ");
    for(i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter index: ");
    scanf("%d", &index);

    if (index > 0 && index < 5) {
        printf("%d", arr[index]);
    } else {
        printf("Enter correct index");
    }
    

}