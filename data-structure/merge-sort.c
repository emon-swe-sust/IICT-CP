// time complexity: O(n log n)

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int i, j;
    
    int L[n1], R[n2];
    
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    } 
    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int k = l;
    i=0;
    j=0;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            k++;
            i++;
        }
        else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    
    while(i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        
        printf("Dividing: arr[%d..%d]\n", l, r);
        printf("D: Left: arr[%d..%d]\n", l, m);
        printf("D: Right: arr[%d..%d]\n", m + 1, r);

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        printf("Merging: arr[%d..%d]\n", l, r);
        printf("M: Left: arr[%d..%d]\n", l, m);
        printf("M: Right: arr[%d..%d]\n", m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}