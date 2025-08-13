#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int val = stack[top];
        top--;
        return val;
    }
}

int isEmpty() {
    return top == -1;
}

void dfs(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};

    push(start);

    while (!isEmpty()) {
        int current = pop();

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = vertices - 1; i >= 0; i--) {
                if (graph[current][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 6;

    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    printf("DFS starting from vertex 0:\n");
    dfs(graph, vertices, 0);

    return 0;
}