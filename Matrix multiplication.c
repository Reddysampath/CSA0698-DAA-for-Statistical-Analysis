#include <stdio.h>
#include <time.h>
#define SIZE 100
void multiplyMatrices(int mat1[][SIZE], int mat2[][SIZE], int res[][SIZE], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], result[SIZE][SIZE];
    int n, i, j;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat1[i][j] = i + j;  
        }
    }
    clock_t start_time = clock(); 
    multiplyMatrices(mat1, mat2, result, n);

    clock_t end_time = clock(); 
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time taken

    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);

    return 0;
}

