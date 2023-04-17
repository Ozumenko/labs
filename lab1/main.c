#include <stdlib.h>
#include"arrays.h"

int main(int argc, char *argv[]) {

    COMPANY *arr = NULL;
    int len = 0;

    init(&arr, &len, argc, argv);

    while (1) {
        printf("1 print\n2 remove\n3 sort\n0 exit\n");
        int s;
        scanf("%d", &s);

        if (s == 1) print_company(arr, len);
        else if (s == 2) remove_item(&arr, &len);
        else if (s == 3) sort(arr, len);
        else if (s == 0) return 0;

    }
}