#include <stdio.h>

int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        heapify(array, size, smallest);
    }
}

void buildHeap(int array[]) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
}

void insert(int array[], int newNum) {
    array[size] = newNum;
    size++;

    int current = size - 1;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (array[current] < array[parent]) {
            swap(&array[current], &array[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

void deleteRoot(int array[], int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == num)
            break;
    }

    if (i == size) return;

    swap(&array[i], &array[size - 1]);
    size--;

    buildHeap(array);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[20] = {10, 15, 20, 17, 25};
    size = 5;

    buildHeap(array);
    printf("Min-Heap array: ");
    printArray(array, size);

    insert(array, 5);
    insert(array, 8);

    printf("After insertion: ");
    printArray(array, size);

    deleteRoot(array, 15);
    printf("After deleting 15: ");
    printArray(array, size);

    return 0;
}