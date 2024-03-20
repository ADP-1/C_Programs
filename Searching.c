#include <stdio.h>

int linearSearch(const int *arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int *arr, int size, int element) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == element) {
            return mid;
        }
        if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 23, 12, 32, 9, 42, 24, 39, 51, 45, 65};
    int size = sizeof(arr) / sizeof(arr[0]), element ,opt;

    printf("Enter the element to find: ");
    scanf("%d", &element);

    int searchindex = binarySearch(arr, size, element);

    if (searchindex != -1) {
        printf("The element %d was found at index %d.\n", element, searchindex);
    } else {
        printf("The element %d is not present.\n", element);
    }

    return 0;
}
