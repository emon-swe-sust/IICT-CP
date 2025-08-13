#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front];
    front++;
    return val;
}

void bfs(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    queue = (int*) malloc(sizeof(int) * MAX);

    int vertices = 6;
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    printf("BFS starting from vertex 0:\n");
    bfs(graph, vertices, 0);

    free(queue);
    return 0;
}