#include <stdio.h>

#define MAX 15

char tree[MAX];

void insertRoot(char key) {
    tree[0] = key;
}

void insertLeft(int parent, char key) {
    int index = 2 * parent + 1;
    tree[index] = key;
}

void insertRight(int parent, char key) {
    int index = 2 * parent + 2;
    tree[index] = key;
}

void inorder(int index) {
    if (index >= MAX || tree[index] == '\0') return;
    inorder(2 * index + 1);
    printf("%c ", tree[index]);
    inorder(2 * index + 2);
}

void preorder(int index) {
    if (index >= MAX || tree[index] == '\0') return;
    printf("%c ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void postorder(int index) {
    if (index >= MAX || tree[index] == '\0') return;
    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%c ", tree[index]);
}

int main() {
    for (int i = 0; i < MAX; i++){
         tree[i] = '\0';
    }
    insertRoot('A');
    insertLeft(0, 'B');
    insertRight(0, 'C');
    insertLeft(1, 'D');
    insertRight(1, 'E');
    insertLeft(2, 'F');
    insertRight(2, 'G');

    printf("Inorder: ");
    inorder(0);
    printf("\nPreorder: ");
    preorder(0);
    printf("\nPostorder: ");
    postorder(0);

    return 0;
}