#include<stdio.h>
#include<string.h>

struct emp {
    int age;
    char name[20];
}e1;



int main() {
    e1.age = 24;
    strcpy(e1.name, "Vishal Kushwaha");

    printf("Age = %d\n", e1.age);
    printf("Name = %s", e1.name);

    
}