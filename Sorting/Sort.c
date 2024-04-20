#include <stdio.h>

void printArray(int *arr, int n);

void swap(int *x, int *y) {
    if (x != y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

void InsertionSort(int *arr, int n) {
    printf("Running Insertion Sort:\n");
    printArray(arr, n);
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

void bubblesort(int *arr, int size) {
    printf("Running Bubble Sort:\n");
    printArray(arr, size);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        printArray(arr, size);
    }
}

void selectionsort(int *arr, int n) {
    printf("Running Selection Sort:\n");
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[i], &arr[min]);
        }
        printArray(arr, n);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int choice;

    printf("Choose From Menu:\n");
    printf("1. Sort using Insertion Sort\n");
    printf("2. Sort using Bubble Sort\n");
    printf("3. Sort using Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Array Before Insertion Sort:\n");
            printArray(arr, n);
            InsertionSort(arr, n);
            printf("Array After Insertion Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            printf("Array Before Bubble Sort:\n");
            printArray(arr, n);
            bubblesort(arr, n);
            printf("Array After Bubble Sort:\n");
            printArray(arr, n);
            break;
        case 3:
            printf("Array Before Selection Sort:\n");
            printArray(arr, n);
            selectionsort(arr, n);
            printf("Array After Selection Sort:\n");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
    }

    return 0;
}
