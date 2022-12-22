#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int len;
    char *string;

    int cnt;
} str;

int str_len(const char *str);

int count_odd_words(const char *str, int len);

void swap_3(str *a, str *b);

int partition(str *array, int low, int high);

void quickSort(str *array, int low, int high);

int main(int argc, char *argv[]);