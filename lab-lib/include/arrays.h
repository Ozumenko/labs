#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    bad, norm, best
} status;

typedef struct {
    char *name;
    int salary;
    status status;

} COMPANY;



void print_company(COMPANY *arr, int len);

void sort(COMPANY *arr, int len);

void remove_item(COMPANY **arr, int *len);

void init(COMPANY **arr, int *len, int argc, char *argv[]);








#include <stdio.h>
#include <stdlib.h>
#include <time.h>

