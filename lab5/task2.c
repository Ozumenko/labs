#include "arrays.h"

int main() {

    int rows;

    input(&rows, 1, INT32_MAX, "Input rows:");

    td_array *arr = (td_array *) (int **) malloc(rows * sizeof(td_array *));
    fill_2d_array(arr, rows);

    printf("In matrix:\n");
    print_2d_array(arr, rows);

    remove_odd_columns(arr, rows);

    printf("Result matrix:\n");
    print_2d_array(arr, rows);

    return 0;
}