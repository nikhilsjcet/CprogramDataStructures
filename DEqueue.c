#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ( (front == 0 && rear == MAX - 1) || (front == rear + 1) );
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full (Overflow)\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front = front - 1;
    }
    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full (Overflow)\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }
    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty (Underflow)\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front = front + 1;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty (Underflow)\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear = rear - 1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, value;

    while (1) {
        printf("\n---- Double Ended Queue Operations ----\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(value);
        }
        else if (choice == 2) {
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(value);
        }
        else if (choice == 3) {
            deleteFront();
        }
        else if (choice == 4) {
            deleteRear();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
