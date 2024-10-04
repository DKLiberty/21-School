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

void max_in_rows(int **matrix, int rows, int cols, int *max_array) {
    for (int i = 0; i < rows; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_array[i] = max;
    }
}

void min_in_cols(int **matrix, int rows, int cols, int *min_array) {
    for (int j = 0; j < cols; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        min_array[j] = min;
    }
}

int main() {
    int choice;
    int rows, cols;
    int **matrix;
    int *max_in_row;
    int *min_in_col;

    scanf("%d", &choice);

    scanf("%d %d", &rows, &cols);

    switch (choice) {
        case 2:
            matrix = allocate_dynamic_1(rows, cols);
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

    max_in_row = (int *)malloc(rows * sizeof(int));
    min_in_col = (int *)malloc(cols * sizeof(int));
    if (max_in_row == NULL || min_in_col == NULL) {
        printf("n/a\n");
        free_matrix(matrix, rows);
        return 0;
    }

    max_in_rows(matrix, rows, cols, max_in_row);
    min_in_cols(matrix, rows, cols, min_in_col);

    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%d ", max_in_row[i]);
    }
    printf("\n");

    for (int j = 0; j < cols; j++) {
        printf("%d ", min_in_col[j]);
    }
    printf("\n");

    free_matrix(matrix, rows);
    free(max_in_row);
    free(min_in_col);

    return 0;
}