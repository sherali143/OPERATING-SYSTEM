
#include <stdio.h>
#include <pthread.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int matrix[MAX_ROWS][MAX_COLS];
int columnSums[MAX_COLS];


void* calculateColumnSum(void* arg) {
    int* args = (int*)arg;
    int colIndex = args[0];
    int numRows = args[1];

    int sum = 0;
    for (int i = 0; i < numRows; i++) {
        sum += matrix[i][colIndex];
    }

    columnSums[colIndex] = sum;
    pthread_exit(NULL);
}

int main() {
    int numRows, numCols;

    printf("Enter the number of rows and columns", MAX_ROWS);
    scanf(numRows,numCols);

    printf("Enter matrix elements");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf(i, j);
            scanf(matrix[i][j]);
        }
    }

    pthread_t threads[MAX_COLS];

    for (int i = 0; i < numCols; i++) {
        int args[2] = {i, numRows};
        pthread_create(&threads[i], NULL, calculateColumnSum, (void*)args);
    }

    for (int i = 0; i < numCols; i++) {
        pthread_join(threads[i], NULL);
        printf("Sum of Column ", i, columnSums[i]);
    }

    return 0;
}

