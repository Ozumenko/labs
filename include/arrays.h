
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#ifndef ARRAYS_H
#define ARRAYS_H


typedef struct {
    int character;
    int *arr;
} td_array;


typedef enum {
    false, true
} bool;

void input(int *var, int min, int max, char *str) {

    printf("%s", str);
    while (!scanf("%d", var) || (*var > max && max != INT32_MAX) ||
           (*var < min && min != INT32_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

void print_row(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void fill_array(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        input(&arr[i], INT32_MIN, INT32_MAX, "Input elem:");
    }
}

void fill_random_array(int *arr, int len, int max) {

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (2 * max) - max;
    }
}

void fill_matrix(int **arr, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(columns * sizeof(int));
        fill_array(arr[i], columns);
    }
}


void fill_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {

        int inp = 0;
        arr[i].character = 0;
        arr[i].arr = calloc(0, 0);

        while (inp != -1) {

            input(&inp, -1, INT32_MAX, "Input elem:");
            if (inp == -1) break;

            arr[i].character++;
            arr[i].arr = (int *) realloc(arr[i].arr, arr[i].character * sizeof(int *));
            arr[i].arr[arr[i].character - 1] = inp;
        }
    }
}

void print_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {
        print_row(arr[i].arr, arr[i].character);
        printf("\n");
    }
}


void print_matrix(int **matrix, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        print_row(matrix[i], columns);
        printf("\n");
    }
}

int find_min(const int *arr, int len) {

    int min = arr[0];

    for (int i = 0; i < len; i++) {
        if (arr[i] < min) min = arr[i];
    }

    return min;
}

void remove_min(int *arr, int *len, int min) {

    for (int i = *len - 1; i >= 0; i--) {

        if (arr[i] == min) {
            for (int j = i; j < *len; j++) {
                arr[j] = arr[j + 1];
            }
            (*len)--;
            arr = realloc(arr, *len * sizeof(int *));
        }
    }
}


void remove_column(int **arr, int rows, int *columns, int index) {

    (*columns)--;

    for (int i = 0; i < rows; i++) {

        for (int j = index; j <= *columns; j++) {
            arr[i][j] = arr[i][j + 1];
        }

        arr[i] = realloc(arr[i], sizeof(double) * *columns);
    }
}


void remove_neg_columns(int **arr, int rows, int *columns) {

    for (int j = *columns - 1; j >= 0; j--) {

        bool negative = true;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] >= 0) negative = false;
        }

        if (negative) remove_column(arr, rows, columns, j);

    }
}

void remove_odd_columns(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < arr[i].character; j++) {

            if (arr[i].arr[j] % 2 && (j + 1) % 2) continue;

            // printf("it=%d\n", arr[i].arr[j]);
            for (int k = j; k < arr[i].character; k++) {
                // printf("k=%d\n", k);
                arr[i].arr[k] = arr[i].arr[k + 1];
            }
            // print_row(arr[i].arr, arr[i].character);
            // printf("\n");
            arr[i].character--;
            arr[i].arr = (int *) realloc(arr[i].arr, arr[i].character * sizeof(int *));
        }
    }
}

#endif
