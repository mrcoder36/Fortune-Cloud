#include <stdio.h>
int stack[5]; //array
int top = -1;
// function to push an element into the stack
void push(int value) {
    if (top == 5 - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack. \n", value);
    }
}
// pop operation
void pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop.\n");
    } else {
        int value = stack[top];
        top--;
        printf("%d is popped from stack.\n", value);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack element: ");
        int i;
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
        
    }
}
int main() {
    push(10);
    push(120);
    push(360);
    display();
    pop();
    pop();
    display();
    
}