#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));

    int a[100][100];
    int size=5 ;
    char mode;
    printf("Fill matrix random numbers? [y/n]");
    while (!scanf(" %c", &mode) || (mode != 'y' && mode != 'n') || getchar() != '\n') {
        printf("Wrong answer, input again:");
        rewind(stdin);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mode == 'y') {
                a[i][j] = rand() %10;

            } else {
                printf("Input array:\n");
                while (!scanf("%d", &a[i][j])) {
                    printf("Wrong charact, input again:");
                    rewind(stdin);
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < size; i++) {

        int umn = 1, flag = 1;

        for (int j = 0; j < size; j++) {

            umn *= a[i][j];

            if (a[i][j] < 0) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("row %d - %d\n", i, umn);
        }
    }
    printf("\n");

    int max = 0;

    for (int i = 0; i < size; i++) {

        int r = 0, c = i, sum1 = 0, sum2 = 0;

        while (c < size && r < size) {
            if (c != r) {
                sum1 += a[r][c];
                sum2 += a[c][r];
            }

            r++;
            c++;
        }

        if (sum1 < sum2 && max < sum2) {
            max = sum2;
        }
        if (sum2 < sum1 && max < sum1) {
            max = sum1;
        }


    }
    printf("max sum %d\n", max);


    return 0;
}

