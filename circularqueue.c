#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


int isFull() {
    return ( (rear + 1) % MAX == front );
}

int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty (Underflow)\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
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

/* Algorithm for Circular Queue Operations
Initialization:

    Define MAX as the maximum queue size.

    Initialize front = -1 and rear = -1.

    Create an array queue[MAX].

Check if Queue is Full (isFull):

    If (rear + 1) % MAX == front, then the queue is full.

    Return true if full; otherwise, false.

Check if Queue is Empty (isEmpty):

    If front == -1, the queue is empty.

    Return true if empty; otherwise, false.

Enqueue Operation (Add element):

    Check if queue is full:

        If isFull() returns true, print "Queue is full (Overflow)" and return.

    If queue is empty:

        Set front = 0.

    Increment rear circularly:

        rear = (rear + 1) % MAX.

    Insert element:

        queue[rear] = value.

    Print confirmation:

        "Enqueued: value".

Dequeue Operation (Remove element):

    Check if queue is empty:

        If isEmpty() returns true, print "Queue is empty (Underflow)" and return.

    Print dequeued element:

        "Dequeued: queue[front]".

    If queue has only one element (front == rear):

        Reset front = rear = -1 (queue becomes empty).

    Otherwise, increment front circularly:

        front = (front + 1) % MAX.

Display Operation (Show elements):

    Check if queue is empty:

        If isEmpty() returns true, print "Queue is empty." and return.

    Print all elements from front to rear circularly:

        Start at i = front.

        Loop:

            Print queue[i].

            If i == rear, break.

            i = (i + 1) % MAX.

Main Program:

    Display menu options:

            Enqueue

            Dequeue

            Display

            Exit

    Input user choice.

    Depending on choice:

        If 1, input value and call enqueue(value).

        If 2, call dequeue().

        If 3, call display().

        If 4, exit program.

        Else, print "Invalid choice. Try again."

    Repeat until user exits.
*/
