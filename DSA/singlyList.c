#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void beginsert();
void display();

int main()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\n Choose One option from the following List");
        printf("\n 1. Insert in begining \n 2. Show \n 3. Exit\n");
        printf("\n Enter your choice: ");
        scanf("\n%d", &choice);

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice...");
        }
    }
}

void beginsert()
{
    struct node *ptr;
    int element;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &element);
        ptr->data = element;
        ptr->next = head;
        head = ptr;
        printf("Item Inserted");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nPrinting values while (ptr ! = NULL).\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next; 
        }
    }
}