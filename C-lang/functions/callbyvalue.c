#include <stdio.h>

int show(int *a ) {
    printf("\nAfter Function calling a= %d", *a);
    *a = *a + 10;
    printf("\n After updation a= %d", *a);

}

int main() {

    int a = 10;
    printf("Before Function calling a= %d", a);
    show(&a);
    printf("\n After updation calling a= %d", a);
}