#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int main() {
    char str[MAX_SIZE];
    int i, j, count;
    while (fgets(str, MAX_SIZE, stdin) != NULL) {
        i = j = count = 0;
        /* puts(str); */
        while (str[i] != '.' && i < (int)strlen(str)) {
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
    return 0;
}


