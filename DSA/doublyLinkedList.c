#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_begining();
void display();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n Choose One option from the following List");
        printf("\n 1. Insert in beginning \n 2. Show \n 3. Exit\n");
        printf("\n Enter your choice: ");
        scanf("\n%d", &choice);

        switch (choice)
        {
        case 1:
            insertion_begining();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Please enter valid Choice...");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\n Printing values: ");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

void insertion_begining()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        printf("\n Enter element Value: ");
        scanf("%d", &item);
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\n Node Inserted");
    }
}