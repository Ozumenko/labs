


#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int character;
    int *arr;
} td_array;


void print_bubble_matrix(int *arr);

void input(int *var, int min, int max, char *str);

void print_row(int *arr, int len);

void fill_array(int *arr, int len);

void fill_random_array(int *arr, int len, int max);

void fill_matrix(int **arr, int rows, int columns);

void fill_2d_array(td_array *arr, int rows);

void print_2d_array(td_array *arr, int rows);

void print_matrix(int **matrix, int rows, int columns);

int find_min(const int *arr, int len);

void remove_min(int *arr, int *len, int min);

void remove_column(int **arr, int rows, int *columns, int index);

void remove_neg_columns(int **arr, int rows, int *columns);

void remove_odd_columns(td_array *arr, int rows);

void free_td_array(td_array *arr, int rows);

void free_mass(int **arr, int rows);

void first_task(char **line, char **line2);

void reverse(int *arr, int len);

void second_task(char **line1, char **line2);

void del(char *line, int i, int step);

void swap(char **line1, char **line2);

void move(char **argv, int start, int end);

void merge(int start, int mid, int end, char **argv);

void merge_sort(char **argv, int start, int end);

void type(int argc, char **argv);

char **copy(int argc, char **argv);

void printout(int **arr, int n, int m);

int findmax(int **arr, int n, int m);

void swap_1(int **arr, int n, int m1, int m2);

void ShellSort(int **arr, int n, int m);

#endif
