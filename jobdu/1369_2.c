#include <stdio.h>
#include <stdlib.h>

void Swap(char *a, char *b);
int Strlen(char *str);
void Reverse(char *str, int begin, int end);
int Compare(const void *a, const void *b);
int FindCeil(char *str, int first, int n);
int FindFirst(char *str, int n);
void Permuate(char *str, int n);

int main() {
    char str[20];
    while (scanf("%s", str) != EOF) {
        int len = Strlen(str);
        str[len] = '\0';
        qsort(str, len, sizeof(char), Compare);
        puts(str);
        Permuate(str, len);
    }
    return 0;
}

void Swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int Strlen(char *str) {
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') ++i;
    return i;
}

void Reverse(char *str, int begin, int end) {
    int i = begin, j = end - 1;
    while (i < j) {
        Swap(&str[i], &str[j]);
        ++i;
        --j;
    }
}

int Compare(const void *a, const void *b) {
    return *((char *)a) - *((char *)b);
}

int FindFirst(char *str, int len) {
    int i;
    for (i = len -2; i >= 0 && str[i] >= str[i + 1]; --i);
    /* printf("FindFirst first = %d\n", i); */
    return i;
}

int FindCeil(char *str, int first, int n) {
    int ceil = n - 1;
    while (ceil >= (first + 1) && str[ceil] <= str[first])
        --ceil;
    /* printf("FindCeil ceil=%d\n", ceil); */
    return ceil;
}

void Permuate(char *str, int n) {
    int is_finish = 1, first, ceil;
    while (is_finish) {
        if ((first = FindFirst(str, n)) != -1) {
            ceil = FindCeil(str, first, n);
            Swap(&str[first], &str[ceil]);
            Reverse(str, first + 1, n);
            puts(str);
        } else {
            is_finish = 0;
        }
    }
}
