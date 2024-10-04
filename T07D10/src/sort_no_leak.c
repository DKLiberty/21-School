#include <stdio.h>
#include <stdlib.h>

void readArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("n/a\n");
            exit(1);
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("n/a\n");
        return 1;
    }

    readArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);

    free(arr);

    return 0;
}