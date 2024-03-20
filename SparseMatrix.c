// Sparce Matrix Program

#include <stdio.h>

void displayMatrix(int matrix[][7], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int countNonZeros(int matrix[][7], int row, int column, int *k) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] != 0) {
                (*k) += 1;
            }
        }
    }

    if ((*k) < 0.5 * (row * column)) {
        printf("It can be a sparse matrix.\nAs the number of non-zero elements is %d only out of %d\n", *k, (row * column));
        return 1;
    } else {
        printf("It can't be a sparse matrix.\nAs the number of non-zero elements is %d out of %d\nNot Executing code Further..............", *k, (row * column));
        return 0;
    }
}

void sparseMatrixAssignment(int matrix[][7], int row, int column, int k, int sparseMatrix[3][50]) {
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[0][index] = i; // row input - coordinate input
                sparseMatrix[1][index] = j; // column    - coordinate input
                sparseMatrix[2][index] = matrix[i][j]; // value
                index++;
            }
        }
    }

    // Fill the remaining entries in sparseMatrix with -1 to mark them as unused
    for (int i = index; i < 50; i++) {
        sparseMatrix[0][i] = -1;
        sparseMatrix[1][i] = -1;
        sparseMatrix[2][i] = -1;
    }
}

void convertSparseToOriginal(int sparseMatrix[3][50], int row, int column, int originalMatrix[][7]) {
    // Initializing original matrix with zeros
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            originalMatrix[i][j] = 0;
        }
    }

    int i = 0;
    while (sparseMatrix[0][i] != -1){
        originalMatrix[sparseMatrix[0][i]][sparseMatrix[1][i]] = sparseMatrix[2][i];
        i++;
    }
}

int main() {
    int matrix[7][7] = {
        {1, 0, 0, 0, 0, 0, 2},
        {0, 3, 0, 0, 0, 4, 0},
        {0, 0, 5, 0, 6, 0, 0},
        {0, 0, 0, 7, 0, 0, 0},
        {0, 0, 6, 0, 5, 0, 0},
        {0, 4, 0, 0, 0, 3, 0},
        {2, 0, 0, 0, 0, 0, 1}
    };

    int k = 0; // K is the number of non-zeroes in matrix.
    int result = countNonZeros(matrix, 7, 7, &k);

    printf("%d\n", result);

    if (result == 0) return 0;

    int sparseMatrix[3][50]; // Assuming a maximum of 50 non-zero elements

    sparseMatrixAssignment(matrix, 7, 7, k, sparseMatrix);

    printf("Sparse Matrix:\n");
    int i = 0;
    while (sparseMatrix[0][i] != -1) {
        printf("(%d, %d, %d)\n", sparseMatrix[0][i], sparseMatrix[1][i], sparseMatrix[2][i]);
        i++;
    }

   
    int originalMatrix[7][7];

    convertSparseToOriginal(sparseMatrix, 7, 7, originalMatrix);

    printf("\nOriginal Matrix:\n");
    displayMatrix(originalMatrix, 7, 7);

    return 0;
}
