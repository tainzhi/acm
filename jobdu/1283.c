/*******************************************************************************
* File     : 1283.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-06 15:29:54
* Modified : 2017-04-06 18:16:02
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10010
int Strlen(char *str) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n')
        ++len;
    str[len] = '\0';
    return len;
}

int main() {
    char str[MAX_SIZE];
    char alpha[26];
    /* while (fgets(str, MAX_SIZE, stdin)) { */
    while (scanf("%s", str) != EOF) {
        int len = Strlen(str);
        /* if (len == 0) */
        /*     break; */
        memset(alpha, 0, sizeof(alpha));
        for (int i = 0; i < len; ++i) {
            int current = str[i] - 'A';
            if (alpha[current] == 0)
                alpha[current] = 1;
            else if (alpha[current] == 1)
                alpha[current] = 2;
        }
        int index = -1;
        for (int i = 0; i < len; ++i) {
            int current = str[i] - 'A';
            if (alpha[current] == 1) {
                index = i;
                break;
            }
        }
        printf("%d\n", index);
    }
    return 0;
}

