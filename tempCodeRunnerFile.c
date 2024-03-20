/*
Declare and initialize a one-dimensional array of integers with a size of 5.                          [DONE]
Implement a function printArray to print the elements of the array.                                   [DONE]    
Implement a function sumArray to calculate and return the sum of all elements in the array.           [DONE]
Implement a function reverseArray to reverse the elements of the array.                               [DONE]
*/

#include <stdio.h>

void printArray(const int *a, int size, const char *arrayName);
int sumArray(const int *a, int size, const char *arrayName);
void revArray(const int *a, int size, const char *arrayName);

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5, "Array");
    printf("\n");

    int arraySum = sumArray(arr, 5, "Array");
    printf("Sum of the elements: %d\n", arraySum);
    printf("\n");

    revArray(arr, 5, "Reversed Array");

    return 0;
}

void printArray(const int *a, int size, const char *arrayName) {
    printf("Printing the %s[%d] array..........\n", arrayName, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
}

int sumArray(const int *a, int size, const char *arrayName) {
    int sum = 0;
    printf("Printing the %s[%d] array element's sum ..........\n", arrayName, size);
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

void revArray(const int *a, int size, const char *arrayName) {
    int reversedArray[size];
    for (int i = 0; i < size; i++) {
        reversedArray[size - 1 - i] = a[i];
    }
    printArray(reversedArray, size, arrayName);
}
