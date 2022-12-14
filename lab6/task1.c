
#include<stdlib.h>
#include "arrays.h"
#include "sort.h"

int main() {
    int len = 7;
    input(&len, 1, INT32_MAX, "Input len:");
    int *arr = (int *) malloc(len * sizeof(int *));
    fill_array(arr, len);
    print_row(arr, len);
    printf("\n");
    bubble_sort(arr, len);
    print_row(arr, len);
}