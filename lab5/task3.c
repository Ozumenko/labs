#include "arrays.h"

int main() {

    int rows, cols;

    input(&rows, 1, INT32_MAX, "Input rows:");
    input(&cols, 1, INT32_MAX, "Input columns:");

    int **arr = (int **) malloc(rows * sizeof(int *));
    fill_matrix(arr, rows, cols);
    print_matrix(arr, rows, cols);
    printf("\n");
    remove_neg_columns(arr, rows, &cols);
    print_matrix(arr, rows, cols);
    free_mass(arr,rows);
    return 0;
}