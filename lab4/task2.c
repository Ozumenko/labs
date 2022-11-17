#include <stdio.h>
#include <stdlib.h>
#include<time.h>


void print_matrix(int rows, int cols, float arr[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((int) arr[i][j] != arr[i][j]) {
                printf("%.1f\t", arr[i][j]);
            } else {
                printf("%.0f\t", arr[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {

    srand(time(NULL));

    int rows =4, cols=5 ;
   printf("input size");
   scanf("%d %d",&rows,&cols);
    char mode;

    float arr[rows][cols];

    printf("Fill matrix random numbers? [y/n]");
    while (!scanf(" %c", &mode) || (mode != 'y' && mode != 'n') || getchar() != '\n') {
        printf("Wrong answer, input again:");
        rewind(stdin);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mode == 'y') {
                arr[i][j] = rand() % 2;
            } else {
                printf("Input array:\n");
                while (!scanf("%f", &arr[i][j]) ) {
                    printf("Wrong charact, input again:");
                    rewind(stdin);
                }
            }
        }
    }

    printf("Input array:\n");
    print_matrix(rows, cols, arr);

    int zero_i, flag;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                flag = 1;
                zero_i = i;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) break;
    }
    printf("\n");
    if (flag) {
        for (int i = 0; i < cols; i++) {
            arr[i][zero_i] /= 2;
        }
        print_matrix(rows, cols, arr);

    } else{
        printf("no any 0 in matrix");
    }

    return 0;
}

