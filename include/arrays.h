
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"array.c"

#ifndef ARRAYS_H
#define ARRAYS_H

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
#endif
