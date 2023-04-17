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

const char *status_to_str[] = {"bad", "norm", "best"};

void print_company(COMPANY *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d. %s %d$ %s\n", i + 1, arr[i].name, arr[i].salary, status_to_str[arr[i].status]);
    }
}

int cmp_name(COMPANY *a, COMPANY *b) {
    return strcmp(a->name, b->name);
}

int cmp_salary(COMPANY *a, COMPANY *b) {
    return a->salary - b->salary;
}

int cmp_name_salary(COMPANY *a, COMPANY *b) {
    if (strcmp(a->name, b->name) == 0) return a->salary - b->salary;
    return strcmp(a->name, b->name);
}

void sort(COMPANY *arr, int len) {
    printf("1 name\n2 salary\n3 name+salary\n0 exit\n");
    int s;
    scanf("%d", &s);
    if (s == 1) qsort(arr, len, sizeof(COMPANY), (int (*)(const void *, const void *)) cmp_name);
    else if (s == 2) qsort(arr, len, sizeof(COMPANY), (int (*)(const void *, const void *)) cmp_salary);
    else if (s == 3) qsort(arr, len, sizeof(COMPANY), (int (*)(const void *, const void *)) cmp_name_salary);
    else if (s == 0) return;
}

void remove_item(COMPANY **arr, int *len) {
    char *c = malloc(0);
    gets(c);
    rewind(stdin);

    for (int i = 0; i < *len; i++) {
        if (strcmp((*arr)[i].name, c) == 0) {
            for (int j = i; j < *len; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*len)--;
            *arr = realloc(*arr, *len * sizeof(COMPANY));
            return;
        }
    }
}

void init(COMPANY **arr, int *len, int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {

        (*arr) = realloc(*arr, ++(*len) * sizeof(COMPANY));
        (*arr)[i - 1].name = calloc(0, 0);

        int ptr = 0;
        while (argv[i][ptr] != ';') {
            (*arr)[i - 1].name = realloc((*arr)[i - 1].name, (ptr + 1) * sizeof(char));
            (*arr)[i - 1].name[ptr] = argv[i][ptr];
            ptr++;
        }
        int salary_ptr = 0;
        char *str_salary = calloc(0, 0);
        ptr++;
        while (argv[i][ptr] != ';') {
            str_salary = realloc(str_salary, (salary_ptr + 1) * sizeof(char));
            str_salary[salary_ptr] = argv[i][ptr];
            ptr++;
            salary_ptr++;
        }

        (*arr)[i - 1].salary = strtol(str_salary, NULL, 10);

        int status_ptr = 0;
        char *str_status = calloc(0, 0);
        ptr++;
        while (argv[i][ptr] != '\0') {
            str_status = realloc(str_status, (status_ptr + 1) * sizeof(char));
            str_status[status_ptr] = argv[i][ptr];
            ptr++;
            status_ptr++;
        }
        if (strcmp(str_status, "loh") == 0) (*arr)[i - 1].status = bad;
        else if (strcmp(str_status, "norm") == 0) (*arr)[i - 1].status = norm;
        else if (strcmp(str_status, "best") == 0) (*arr)[i - 1].status = best;
        else (*arr)[i - 1].status = bad;
    }
}

void print_text(int *len) {
    int *arr;
    printf("Введите текст\n");
    scanf("%s", len);
    for (int i = 0; i < len; i++) {
        scanf("%s", arr);

    }
}

void count(int *arr, int *len, int i) {
    int word = 0;
    i=0;
    while (i!='\0') {
        i++;
        if (arr[i]='a'){
            word++;

        }
    }




}