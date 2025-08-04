#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("The Queue is Full (Overflow)\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("Enqueued : %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty (Underflow)\n");
        return;
    }
    printf("Dequeued : %d\n", queue[front]);
    front++;


    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty.\n");
        return;
    }
    printf("Queue Contents: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n-------------------- Queue Operation ------------------\n");
        printf("1. Enqueue\t 2.Dequeue\t3.Display\t 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
