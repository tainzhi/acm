#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 2000100
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int next[MAX_SIZE];
char str[MAX_SIZE], temp[MAX_SIZE];

int ChangeString() {
    temp[0] = '$';
    int flag = 0, i = 1, j = 0;
    while (str[j] != '\0') {
        if (!flag) {
            temp[i++] = '#';
        } else {
            temp[i++] = str[j++];
        }
        flag ^= 1;
    }
    temp[i++] = '#';
    temp[i] = '\0';
    /* printf("changed str:%s\n", temp); */
    return i;
}

void GetNext(int n) {
    int pre_s = 0, pre_i;
    for (int i = 1; i <= n; ++i) {
        if (pre_s >= i) {
            next[i] = MIN(next[2 * pre_i - i], pre_s - i);
        } else {
            next[i] = 1;
        }
        while (temp[i - next[i]] == temp[i + next[i]]) ++next[i];
        if (i + next[i] > pre_s) {
            pre_s = i + next[i];
            pre_i = i;
        }
    }
}

int main() {
    int count = 0;
    while (scanf("%s", str) != EOF) {
        if (str[0] == 'E') break;
        int len = ChangeString();
        GetNext(len);
        int max_p = -1;
        for (int i = 1; i <= len; ++i) {
            if (max_p < (next[i] - 1))
                max_p = next[i] - 1;
        }
        printf("Case %d: %d\n", ++count, max_p);
    }
}
