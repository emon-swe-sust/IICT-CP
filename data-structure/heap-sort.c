#include <stdio.h>

int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void insert(int array[], int newNum) {
    array[size] = newNum;
    size += 1;

    int current = size - 1;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (array[current] > array[parent]) {
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
        if (array[i] == num) break;
    }

    if (i == size) return;

    swap(&array[i], &array[size - 1]);
    size--;

    heapSort(array, size);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[20] = {3, 9, 2, 1, 4, 5};
    size = 6;

    heapSort(array, size);
    printf("Max-Heap array: ");
    printArray(array, size);

    insert(array, 7);
    insert(array, 8);
    heapSort(array, size);


    printf("After insertion: ");
    printArray(array, size);

    deleteRoot(array, 4);
    heapSort(array, size);

    printf("After deleting 4: ");
    printArray(array, size);

    return 0;
}