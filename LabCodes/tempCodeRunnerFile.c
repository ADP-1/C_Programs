#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int numbers[MAX_SIZE];
    int num, count = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt");
        return 1;
    }

    while (fscanf(inputFile, "%d", &num) == 1) {
        if (count >= MAX_SIZE) {
            printf("Exceeded maximum size of array. Cannot process all numbers.\n");
            break;
        }
        numbers[count++] = num;
    }

    fclose(inputFile);

    insertionSort(numbers, count);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d ", numbers[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);

    printf("Numbers have been sorted and written to output.txt\n");

    return 0;
}
