#include "arrays.h"

int main() {

    int len;
    input(&len, 1, INT32_MAX, "Input len:");

    int *arr = (int *) malloc(len * sizeof(int));

    fill_array(arr, len);
    int min = find_min(arr, len);
    remove_min(arr, &len, min);
    print_row(arr, len);
    return 0;
}