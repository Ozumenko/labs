#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;


}


void bubble_sort(int *arr, int len) {

    int k;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] >= 0 || !(arr[j] % 2))continue;
            for (k = j + 1; k < len; k++) {
                if (arr[k] <= 0 && arr[k] % 2)break;
                if (arr[j] > arr[k])
                    swap(&arr[j], &arr[k]);
            }
        }

    }
}