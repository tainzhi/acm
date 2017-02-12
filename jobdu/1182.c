#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int Strlen(char *str) {
    int len = 0;
    while (str[len] != '\n' && str[len] != '\0')
        ++len;
    str[len] = '\0';
    return len;
}

int main() {
    char str[MAX_SIZE];
    int i, j, count;
    int len;
    while (fgets(str, MAX_SIZE, stdin) != NULL) {
        len = Strlen(str);
        i = j = count = 0;
        if (len == 0)
            break;
        while (str[i] != '.' && i < len ) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                /* printf("-"); */
                j++;
            }
            else {
                /* printf("*"); */
                if (j != 0) {
                    count++;
                    if (count == 1)
                        printf("%d", j);
                    else 
                        printf(" %d", j);
                    j = 0;
                }
            }
            i++;
        }
        if (j != 0) {
            /* printf("__count=%d___", count); */
            if (count > 1)
                printf(" ");
            printf("%d\n", j);
        } else if (j == 0 && count > 0)
            printf("\n");
    }
    /* printf("*******\n"); */
    return 0;
}

