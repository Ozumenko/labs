

#include <stdlib.h>
#include <stdio.h>
#include <arrays.h>

void free_mass(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
}

void free_td_array(td_array *arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i].arr);
    }
}


void input(int *var, int min, int max, char *str) {

    printf("%s", str);
    while (!scanf("%d", var) || (*var > max && max != INT32_MAX) ||
           (*var < min && min != INT32_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

void print_row(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void fill_array(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        input(&arr[i], INT32_MIN, INT32_MAX, "Input elem:");
    }
}

void fill_random_array(int *arr, int len, int max) {

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (2 * max) - max;
    }
}

void fill_matrix(int **arr, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(columns * sizeof(int *));
        fill_array(arr[i], columns);
    }
}


void fill_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {

        int inp = 0;
        arr[i].character = 0;
        arr[i].arr = NULL;

        while (inp != -1) {

            input(&inp, -1, INT32_MAX, "Input elem:");
            if (inp == -1) break;

            arr[i].character++;
            arr[i].arr = (int *) realloc(arr[i].arr, arr[i].character * sizeof(int *));
            arr[i].arr[arr[i].character - 1] = inp;
        }
    }
}

void print_2d_array(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {
        print_row(arr[i].arr, arr[i].character);
        printf("\n");
    }
}


void print_matrix(int **matrix, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        print_row(matrix[i], columns);
        printf("\n");
    }
}

int find_min(const int *arr, int len) {

    int min = arr[0];

    for (int i = 0; i < len; i++) {
        if (arr[i] < min) min = arr[i];
    }

    return min;
}

void remove_min(int *arr, int *len, int min) {

    for (int i = *len - 1; i >= 0; i--) {
        if (arr[i] == min) {
            for (int j = i; j < *len; j++) {

                arr[j] = arr[j + 1];
            }
            (*len)--;

            arr = (int *) realloc(arr, *len * sizeof(int));
        }
    }

}


void remove_column(int **arr, int rows, int *columns, int index) {

    (*columns)--;

    for (int i = 0; i < rows; i++) {

        for (int j = index; j <= *columns; j++) {
            arr[i][j] = arr[i][j + 1];
        }

        arr[i] = realloc(arr[i], sizeof(double) * *columns);
    }
}


void remove_neg_columns(int **arr, int rows, int *columns) {

    for (int j = *columns - 1; j >= 0; j--) {

        int negative = 1;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] >= 0) negative = 0;
        }

        if (negative) remove_column(arr, rows, columns, j);

    }
}

int is_letter(char line) {
    if ((line >= 'a' && line <= 'z') || (line >= 'A' && line <= 'Z'))
        return 1;
    return 0;
}

int len(char *line) {
    int i = 0;
    for (; line[i] != '\0'; i++);
    return i;
}

int get_words_of_even(char *line) {
    int words = 0, start = 0;
    for (int i = len(line); i != 0; i--) {
        if (is_letter(line[i - 1]) && !is_letter(line[i])) {
            start = i;
            continue;
        }
        if (!is_letter(line[i - 1]) && is_letter(line[i])) {
            words += ((start - i) % 2 == 0);
            start = 0;
        }
    }
    if (is_letter(line[0]) && start != 0)
        words += (start % 2 == 0);
    return words;
}

void swap(char **line1, char **line2) {
    char *temp = *line1;
    *line1 = *line2;
    *line2 = temp;
}

void move(char **argv, int start, int end) {
    for (int i = end; i > start; i--) {
        swap(argv + i, argv + i - 1);
    }
}

void merge(int start, int mid, int end, char **argv) {
    int i = start, j = mid + 1;
    for (; i <= mid && j <= end;) {
        if (get_words_of_even(argv[i]) <= get_words_of_even(argv[j])) {
            i++;
        } else {
            move(argv, i, j);
            i++;
            mid++;
            j++;
        }
    }
}

void merge_sort(char **argv, int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        merge_sort(argv, start, mid);
        merge_sort(argv, mid + 1, end);
        merge(start, mid, end, argv);
    }
}

void type(int argc, char **argv) {
    for (int i = 1; i < argc; i++)
        printf("%s %d words\n", argv[i], get_words_of_even(argv[i]));
}

void remove_odd_columns(td_array *arr, int rows) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < arr[i].character; j++) {

            if (arr[i].arr[j] % 2 && (j + 1) % 2) continue;
            for (int k = j; k < arr[i].character; k++) {
                arr[i].arr[k] = arr[i].arr[k + 1];
            }
            arr[i].character--;
            arr[i].arr = (int *) realloc(arr[i].arr, arr[i].character * sizeof(int *));
        }
    }
}

int comp(int len, char *s0, char *s) {
    for (int i = 0; i < len; i++) {
        if (s0[i] != s[i])
            return 0;
    }
    return 1;
}

char *reallOK(char *ptr, int size, int sizenew) {
    char *ptr1 = (char *) malloc(sizenew);
    for (int i = 0; (i < size && i < sizenew); i++)
        *(ptr1 + i) = *(ptr + i);
    *(ptr1 + sizenew) = '\0';
    return ptr1;
}

int letter(char *line, int i) {
    if ((*(line + i) >= 'a' && *(line + i) <= 'z') || (*(line + i) >= 'A' && *(line + i) <= 'Z'))
        return 1;
    return 0;
}

void del(char *line, int i, int step) {
    for (int j = i; *(line + j + step - 1) != '\0'; j++) {
        *(line + j) = *(line + j + step);
    }
}

void firsttask(char **line, char **line2) {
    int k, len = 1;
    printf("input k: ");
    while (scanf("%d", &k) != 1 || getchar() != '\n') {
        printf("error\n");
        rewind(stdin);
    }
    printf("input string \n");
    *line = (char *) calloc(len, sizeof(char));
    for (int i = 0;; i++) {
        *(*line + i) = getchar();
        if (*(*line + i) == '\n') {
            len = i;
            *(*line + i) = '\0';
            break;
        } else {
            len = i + 1;
            *line = reallOK(*line, len, (len + 1) * sizeof(char));
        }
    }
    int end = 0, start = 0;
    for (int i = len; i >= 0; i--) {
        if (!letter(*line, i) && letter(*line, i - 1))
            end = i - 1;
        if (letter(*line, i) && !letter(*line, i - 1)) {
            start = i;
            if (end - start + 1 < k) {
                del(*line, start, end - start + 1);
                len = len - end + start - 1;
            }
            end = 0, start = 0;
        }
    }
    *line = reallOK(*line, len, len * (sizeof(char)));
    for (int i = 0; line[0][i] != '\0'; i++)
        printf("%c", line[0][i]);
}

void secondtask(char **line1, char **line2) {
    int len1 = 1, len2 = 1;
    printf("input string \n");
    *line1 = (char *) calloc(len1, sizeof(char));
    for (int i = 0;; i++) {
        *(*line1 + i) = getchar();
        if (*(*line1 + i) == '\n') {
            len1 = i;
            *(*line1 + i) = '\0';
            break;
        } else {
            len1 = i + 1;
            *line1 = reallOK(*line1, len1, (len1 + 1) * sizeof(char));
        }
    }
    printf("input the string to delete: ");
    *line2 = (char *) calloc(len2, sizeof(char));
    for (int i = 0;; i++) {
        *(*line2 + i) = getchar();
        if (*(*line2 + i) == '\n') {
            len2 = i;
            *(*line2 + i) = '\0';
            break;
        } else {
            len2 = i + 1;
            *line2 = reallOK(*line2, len2, (len2 + 1) * sizeof(char));
        }
    }
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (comp(len2, *line2, *line1 + i)) {
            del(*line1, i, len2);
            len1 -= len2;
            break;
        }
    }
    *line1 = reallOK(*line1, len1 + 1, len1 + 1);
    for (int i = 0; i < len1; i++)
        printf("%c", line1[0][i]);
}

char **copy(int argc, char **argv) {
    char **
            str = malloc(argc * sizeof(char *));
    for (int i = 0; i < argc; i++) {
        str[i] = calloc(len(argv[i]), sizeof(char));
        for (int j = 0; j <= len(argv[i]); j++) {
            str[i][j] = argv[i][j];

        }

    }
    return str;

}

