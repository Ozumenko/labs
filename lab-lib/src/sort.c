#include <stdio.h>
#include <stdlib.h>
void swap_2(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;


}
void select_sort(int *arr, int len) {

    int min_i;

    for (int i = 0; i < len - 1; i++) {

        if (arr[i] >= 0 || !(arr[i] % 2)) continue;

        min_i = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min_i])
                min_i = j;

        if (min_i != i)
            swap_2(&arr[min_i], &arr[i]);
    }
}

void bubble_sort(int *arr, int len) {

    int k;

    for (int i = 0; i < len - 1; i++) {

        for (int j = 0; j < len - i - 1; j++) {

            if (arr[j] >= 0 || !(arr[j] % 2)) continue;
            for (k = j + 1; k < len; k++) if (arr[k] <= 0 && arr[k] % 2) break;

            if (arr[j] > arr[k]) swap_2(&arr[j], &arr[k]);
        }
    }
}

int findmax(int **arr, int n, int m) {
    int max = *(*arr + m);
    for (int i = 0; i < n; i++) {
        if (max < *(*(arr + i) + m))
            max = *(*(arr + i) + m);
    }
    return max;
}

void swap_1(int **arr, int n, int m1, int m2) {
    for (int i = 0; i < n; i++) {
        int tmp = arr[i][m1];
        arr[i][m1] = arr[i][m2];
        arr[i][m2] = tmp;
    }
}

void printout(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void ShellSort(int **arr, int n, int m) {
    int i, j, step;
    int tmp;
    for (step = m - m / 2; m > 0; step = step - step / 2) {
        for (i = step; i < m; i++) {
            tmp = findmax(arr, n, i);
            for (j = i; j >= step; j -= step) {
                if (tmp > findmax(arr, n, j - step)) {
                    swap_1(arr, n, j, j - step);

                    printout(arr, n, m);//ïðîâðêà äåéñòâèé
                    printf("\n");
                } else
                    break;
            }
        }
        if (step == 1)
            break;
    }
}
typedef struct {
    int len;
    char *string;

    int cnt;
} str;

int str_len(const char *str) {
    int len = 0;
    while (*(str + len) != '\0') len++;
    return len;
}

int count_odd_words(const char *str, int len) {
    int res = 0;
    int cnt = 0;
    //printf("str - %s \n", str);
    for (int i = 0; i <= len; i++) {
        cnt++;
        // printf("%d", str[i] == '\0');
        if (str[i] == ' ' || str[i] == '\0') {
            // printf("cnt %d\n", cnt);
            if (cnt % 2) res++;
            cnt = 0;
        }
    }
    return res;
}

void swap_3(str *a, str *b) {
    str t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(str *array, int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high].cnt;

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j].cnt <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap_3(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap_3(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(str * array, int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
int main(int argc, char *argv[]) {

    if (!(argc - 1)) {
        printf("Provide strings in args!");
        return 0;
    }

    str *word_list = calloc (argc - 1, sizeof(str));

    for (int i = 1; i < argc; i++) {
        word_list[i].len = str_len(argv[i]);
        word_list[i].string = calloc(word_list[i].len, sizeof(char));
        word_list[i].string = argv[i];
        word_list[i].cnt = count_odd_words(argv[i], word_list[i].len);

        // printf("%s %d\n", word_list[i].string, word_list[i].cnt);

    }
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", word_list[i].string, word_list[i].cnt);
    }

    printf("\nStrings after sorting:\n");
    quickSort(word_list, 0, argc - 2);

    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", word_list[i].string, word_list[i].cnt);
    }
    return 0;
}