/*
Sorting and Searching:

Declare and initialize a one-dimensional array of integers with a size of 8.[DONE]
Implement a function sortArray to sort the elements of the array in ascending order using any sorting algorithm of your choice (e.g., bubble sort, insertion sort).
Implement a function binarySearch to search for a given element in the sorted array using the binary search algorithm
*/

#include <stdio.h>

void printArray(const int *a, int size, const char *array_name) {
    printf("Printing the %s[%d] array..........\n", array_name, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
}

void swap(int *x, int *y) {
    if (x != y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

void bubblesort(int *a, int size, const char *array_name) {
    printf("Running Bubble Sort.............\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    printArray(a, size, array_name);
}

int bianrysearch(const int *a , int size ,int target ){
    
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) {
            return mid;
        }

        if (a[mid] < target) {
            low = mid + 1;
        } 
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size;

    printf("Enter the Size of Array : ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("\nEnter the Value of Array[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printArray(arr, size, "Original_Array"); 

    bubblesort(arr, size, "Sorted_Array"); 

    int target;
    printf("Enter the Target to find : ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Target %d found at index %d in the sorted array.\n", target, result);
    } else {
        printf("Target %d not found in the sorted array.\n", target);
    }
}