
#include<stdlib.h>
#include "arrays.h"
#include "sort.h"

#define start_timer(X) clock_t X = clock()
#define stop_timer(X) printf("%s completed for %f sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int main() {
    int len = 7;
    input(&len, 1, INT32_MAX, "Input len:");
    int *arr = (int *) malloc(len * sizeof(int *));

    fill_random_array(arr, len, 1000);
    // fill_array(arr, len);
    //print_row(arr, len);
    //printf("\n");
    start_timer(bubble);
    bubble_sort(arr, len);
    stop_timer(bubble);

    reverse(arr, len);
    start_timer(bubble_worths);
    bubble_sort(arr, len);
    stop_timer(bubble_worths);
    //print_row(arr, len);

    start_timer(select);
    select_sort(arr, len);
    stop_timer(select);
}