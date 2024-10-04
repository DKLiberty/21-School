#include <stdio.h>
#include <stdlib.h>

int **allocate_dynamic_1(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

int **allocate_dynamic_2(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    matrix[0] = (int *)malloc(rows * cols * sizeof(int));
    if (matrix[0] == NULL) {
        free(matrix);
        return NULL;
    }
    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[0] + i * cols;
    }
    return matrix;
}

int **allocate_dynamic_3(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    matrix[0] = (int *)malloc(rows * cols * sizeof(int));
    if (matrix[0] == NULL) {
        free(matrix);
        return NULL;
    }
    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[i - 1] + cols;
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    if (matrix != NULL) {
        free(matrix[0]);
        free(matrix);
    }
}

void input_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
            printf("\n");
        }
    }
}

int main() {
    int choice;
    int rows, cols;
    int **matrix;

    scanf("%d", &choice);

    scanf("%d %d", &rows, &cols);

    switch (choice) {
        case 1:
            matrix = allocate_dynamic_1(rows, cols);
            break;
        case 2:
            matrix = allocate_dynamic_2(rows, cols);
            break;
        case 3:
            matrix = allocate_dynamic_3(rows, cols);
            break;
        default:
            printf("n/a");
            return 0;
    }

    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }

    input_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);

    return 0;
}