/*
Declare and initialize a one-dimensional array of integers with a size of 5.                          [DONE]
Implement a function printArray to print the elements of the array.                                   [DONE]    
Implement a function sumArray to calculate and return the sum of all elements in the array.           [DONE]
Implement a function reverseArray to reverse the elements of the array.                               [DONE]
Implement a function to find teh largest no using pointers. 
*/

#include <stdio.h>

void printArray(const int *a, int size, const char *arrayName);
int sumArray(const int *a, int size, const char *arrayName);
void revArray(const int *a, int size, const char *arrayName);
int largestnum(const int *a , int size);
void insertElement(int *a , int *size , int index , int value );

int main() {
    int s = 5;
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5, "Array");
    printf("\n");
    
    int largest = largestnum(arr , 5);
    printf("The Largest number in the array is : %d\n", largest);

    int sum = sumArray(arr, 5, "Array");
    printf("Sum of array elements: %d\n", sum);
    
    printf("Reversed array:\n");
    revArray(arr, 5, "Array");

    // Inserting an element
    int index = 2;
    int value = 10;
    insertElement(arr, &s, index, value);
    printf("After inserting %d at index %d:\n", value, index);
    printArray(arr, s, "Array");

    return 0;
}

void printArray(const int *a, int size, const char *arrayName) {
    printf("Printing the %s[%d] array:\n", arrayName, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
}

int sumArray(const int *a, int size, const char *arrayName) {
    int sum = 0;
    printf("Summing the %s[%d] array elements:\n", arrayName, size);
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

void revArray(const int *a, int size, const char *arrayName) {
    printf("Reversing the %s[%d] array:\n", arrayName, size);
    for (int i = size - 1; i >= 0; i--) {
        printf("%d\n", a[i]);
    }
}

int largestnum(const int *a , int size){
    const int *ptr = a;
    int largest = *ptr;

    for(int i = 0 ; i < size - 1 ; i++){
        ptr++;
        if(*ptr > largest){
            largest = *ptr;
        }
    }
    return largest;
}

void insertElement(int *a , int *size , int index , int value ){
    if( index >= *size || index < 0 ){
        printf("Invalid Index\n");
        return;
    }

    for(int i = *size - 1 ; i >= index ; i--){
        a[i + 1] = a[i];
    }
    a[index] = value;
    (*size)++;
}
