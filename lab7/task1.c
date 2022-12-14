
#include "arrays.h"
int main() {
    int choice;
    void (*fun) (char**, char**);
    printf("Choose task 1 or 2\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') {
        printf("try again\n");
        rewind(stdin);
    }
    char* line1, *line2;
    if (choice == 1) {
        printf("Delete words less than k letters\n");
        fun = firsttask;
    }
    else {
        printf("The strings S and S0 are given. Remove the first substring matching S0 from the string S.\nIf there are no matching substrings, then output the string S unchanged\n");
        fun = secondtask;
    }
    fun(&line1, &line2);
}