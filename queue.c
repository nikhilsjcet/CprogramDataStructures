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


/*Algorithm

Algorithm for Queue Operations (Using Array)

Initialization:

    Set front = -1, rear = -1

    Define MAX as the maximum size of the queue (here, 5)

    Declare an array queue[MAX]

Enqueue Algorithm (Insert element at the rear)

    Check if the queue is full:

        If rear == MAX - 1, then print "Queue is full (Overflow)" and return.

    If queue is empty (front == -1):

        Set front = 0.

    Insert the new element:

        Increment rear by 1.

        Set queue[rear] = value.

    Print confirmation message with the enqueued value.

Dequeue Algorithm (Remove element from the front)

    Check if the queue is empty:

        If front == -1 or front > rear, then print "Queue is empty (Underflow)" and return.

    Remove element at front:

        Print the dequeued element queue[front].

    Increment front by 1.

    If front > rear after incrementing:

        Reset front = -1 and rear = -1 (queue becomes empty).

Display Algorithm (Show all elements from front to rear)

    Check if the queue is empty:

        If front == -1 or front > rear, print "Queue is empty" and return.

    Print all elements:

        Loop from i = front to rear and print queue[i].*/
