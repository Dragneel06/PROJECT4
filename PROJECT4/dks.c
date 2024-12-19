#include <stdio.h>
#include <limits.h>
#include <locale.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void rearrangeMatrix(int matrix[3][3]) {
    int minVal = INT_MAX;
    int minRow = 0, minCol = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        int temp = matrix[2][j];
        matrix[2][j] = matrix[minRow][j];
        matrix[minRow][j] = temp;
    }

    for (int i = 0; i < 3; i++) {
        int temp = matrix[i][2];
        matrix[i][2] = matrix[i][minCol];
        matrix[i][minCol] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr[] = { 5, 3, 8, 1, 2, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nОтсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int result[3][3];

    multiplyMatrices(mat1, mat2, result);

    printf("\nМатрица после умножения:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", result[i][j]);
        }
        printf("\n");
    }

    rearrangeMatrix(result);

    printf("\nМатрица после перестановки:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
