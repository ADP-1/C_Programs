#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputMatrix(int ***matrixName, int *x, int *y);
void printMatrix(int **matrixName, int x, int y);
bool isSparse(int **matrixName, int x, int y);
int** sparseAssigment(int **matrixName, int x, int y);
void originalMatrix(int **sparseMatrix, int x, int y);

void inputMatrix(int ***matrixName, int *x, int *y) {
    printf("Enter x dimension of Matrix: ");
    scanf("%d", x);
    printf("Enter y dimension of Matrix: ");
    scanf("%d", y);

    *matrixName = (int **)malloc(*x * sizeof(int *));
    for (int i = 0; i < *x; i++) {
        (*matrixName)[i] = (int *)malloc(*y * sizeof(int));
        for (int j = 0; j < *y; j++) {
            printf("Enter value for Matrix[%d][%d]: ", i, j);
            scanf("%d", &(*matrixName)[i][j]);
        }
    }
    printf("Matrix Entered Successfully.\n");
}

void printMatrix(int **matrixName, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d\t", matrixName[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSparse(int **matrixName, int x, int y) {
    int zeros = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (matrixName[i][j] == 0)
                zeros += 1;
        }
    }

    return (zeros > x * y * 0.5);
}

int** sparseAssigment(int **matrixName, int x, int y) {
    int col = 0;
    int sparseMatrix[3][col];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (matrixName[i][j] != 0) {
                sparseMatrix[0][col] = i;
                sparseMatrix[1][col] = j;
                sparseMatrix[2][col] = matrixName[i][j];
                col++;
            }
        }
    }

    while (col > 0 && sparseMatrix[2][col - 1] == 0) {
        col--;
    }

    return sparseMatrix;
}

void originalMatrix(int **sparseMatrix, int x, int y) {
    // Implement this function to convert the sparseMatrix back to the original matrix
    // You need to allocate memory for the original matrix and fill it based on the sparseMatrix
}

int main() {
    int x = 0, y = 0;
    int **matrix, **sparseMatrix;

    int choice;

    while (1) {
        printf("1. Insert Elements in Matrix.\n");
        printf("2. Print Matrix\n");
        printf("3. Check If Matrix Can Be Sparse\n");
        printf("4. Convert to Sparse\n");
        printf("5. Convert to Original Matrix\n");
        printf("6. Exit.\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {

        case 1:
            inputMatrix(&matrix, &x, &y);
            break;

        case 2:
            printf("Which Matrix:\n1. Matrix.\n2. Sparse Matrix.\nEnter Your Choice of Matrix: ");
            scanf("%d", &choice);
            if (choice == 1)
                printMatrix(matrix, x, y);
            else
                printMatrix(sparseMatrix, x, y);
            break;

        case 3:
            if (isSparse(matrix, x, y))
                printf("Yes, it Can be a Sparse Matrix.\n");
            else
                printf("No, it Cannot be a Sparse Matrix.\n");
            break;

        case 4:
            sparseMatrix = sparseAssigment(matrix, x, y);
            break;

        case 5:
            // Call the function to convert the sparseMatrix back to the original matrix
            originalMatrix(sparseMatrix, x, y);
            break;

        case 6:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}