#include "arrays.h"
int main(int argc, char **argv) {
    if (argc == 1) {
        printf("no arg");
   return 0;
    }
    char** str = copy (argc, argv);
    merge_sort(argv, 1, argc-1);
    printf("Your lines sorted by amount of words of even number of letters:\n");
    type(argc, argv);
}