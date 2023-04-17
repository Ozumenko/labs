
#ifndef SORT_H
#define SORT_H
typedef struct {
    int len;
    char *string;

    int cnt;
} str;

void select_sort(int *arr, int len);

void swap_2(int *xp, int *yp);

void bubble_sort(int *arr, int n);

void ShellSort(int **arr, int n, int m);

void swap_1(int **arr, int n, int m1, int m2);

int findmax(int **arr, int n, int m);

void printout(int **arr, int n, int m);

int str_len(const char *str);

int count_odd_words(const char *str, int len);

void swap_for_sort(str *a, str *b);

int partition(str *array, int low, int high);

void quick_Sort(str *array, int low, int high);



#endif
