#include"header.h"


int main() {
    int arr[] = { 1, 2, 3, 5, 67, 87, 86, 5, 56, 7, 89, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}