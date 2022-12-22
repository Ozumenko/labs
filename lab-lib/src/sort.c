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
