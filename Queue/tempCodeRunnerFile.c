#include <stdio.h>
#include <stdlib.h>

void readValues(int *arr, int n) {
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void expandArray(int **arr, int n1, int n2) {
    int *newArr = (int *)realloc(*arr, (n1 + n2) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory reallocation failed\n");
        return;
    }

    *arr = newArr;
    printf("Enter %d new values:\n", n2);
    for (int i = n1; i < n1 + n2; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void printArray(int *arr, int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n1, n2;
    printf("Enter the initial size of the array: ");
    scanf("%d", &n1);

    int *arr = (int *)malloc(n1 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    readValues(arr, n1);

    printf("Enter the number of new elements to add: ");
    scanf("%d", &n2);

    expandArray(&arr, n1, n2);

    printArray(arr, n1 + n2);

    free(arr);
    return 0;
}
