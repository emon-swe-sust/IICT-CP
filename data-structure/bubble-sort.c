// Time complexity: O(n^2) in the worst and average cases, O(n) in the best case.

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i,j;
    for(i = 0; i < n - 1; i++) {
        int swapped = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
            break; 
    }
}

void printArray(int arr[], int n) {
    
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}