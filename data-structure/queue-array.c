#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int* queue;
int front = -1, rear = -1;

int isEmpty() {
    return front == -1 || front > rear;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }    
    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    queue = (int*) malloc(sizeof(int) * MAX);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    peek();
    dequeue();
    display();

    free(queue);
    return 0;
}