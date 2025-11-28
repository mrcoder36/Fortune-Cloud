#include <stdio.h>

int queue[5];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == 5 -1) {
        printf("Queue is full (Overflow)\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }

}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty");
    } else {
        printf("Queue: ");
        int i;
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    
}

int main() {
    enqueue(10);
    enqueue(45);
    enqueue(70);
    display();
    dequeue();
    display();
    return 0;
}