#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_matrix_(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    srand(time(NULL));
    int size;
    printf("input size");
    scanf("%d",&size);
    char mode;
    int arr[size][size];
    printf("Fill matrix random numbers? [y/n]");
    while (!scanf(" %c", &mode) || (mode != 'y' && mode != 'n') || getchar() != '\n') {
        printf("Wrong answer, input again:");
        rewind(stdin);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mode == 'y') {
                arr[i][j] = rand() % 20 - 10;
            }
            else {
                    printf("Input array:\n");
                while (!scanf("%d", &arr[i][j]) ) {
                    printf("Wrong charact, input again:");
                    rewind(stdin);
                }
                }
            }
        }
    print_matrix_(size, size, arr);
    int center = size / 2;
    int max = arr[0][0];
    int k = 0;
    for (int j = 0; j <= center; j++) {
        for (int i = k; i < size - k; i++) {
            if (arr[i][j] > max && arr[i][j] % 2) {
                max = arr[i][j];
            }
        }
        k++;
    }
    printf("Result: %d", max);
    return 0;
}