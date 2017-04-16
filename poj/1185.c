/*******************************************************************************
* File     : 1185.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-15 16:26:46
* Modified : 2017-04-16 17:17:40
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 110

int dp[2][MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE];
int s_index;
int state[MAX_SIZE], detail[MAX_SIZE];
char matrix[MAX_SIZE][MAX_SIZE];

bool isCan(int i) {
    if (i & i<<1) return false;
    if (i & i<<2) return false;
    return true;
}

int GetDetail(int i) {
    int cnt = 0;
    while (i > 0) {
        if (1&i) ++cnt;
        i >>= 1;
    }
    return cnt;
}

void Preprocess(int col) {
    s_index = 0;
    for (int i = 0; i < (1<<col); ++i) {
        if (isCan(i)) {
            /* printf("i=%d\n", i); */
            state[s_index] = i;
            detail[s_index++] = GetDetail(i);
        }
    }
    /* printf("Preprocess s_index=%d\n", s_index); */
}

int Max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i) {
            scanf("%s", matrix[i]);
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 'H') {
                    map[i] = map[i] | (1<<j);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        Preprocess(m);
        for (int i = 0; i < s_index; ++i)
            for (int j = 0; j < s_index; ++j) {
                if (map[0] & state[i]) continue;
                dp[0][i][j] = detail[i];
            }
        int pp = 0;
        /* printf("111\n"); */
        for (int r = 1;  r < n; ++r) {
            for (int i = 0; i < s_index; ++i) {
                if (map[r] & state[i]) continue;
                for (int j = 0; j < s_index; ++j) {
                    if (state[i] & state[j]) continue;
                    for (int k = 0; k < s_index; ++k) {
                        if (state[i] & state[k]) continue;
                        dp[pp^1][i][j] = Max(dp[pp^1][i][j], dp[pp][j][k] + detail[i]);
                    }
                }
            }
            pp = pp ^ 1;
        }
        int ans = 0;
        for (int i = 0; i < s_index; ++i) 
            for (int j = 0; j < s_index; ++j) {
                ans = Max(ans, dp[pp][i][j]);
            }
        printf("%d\n", ans);
    }
    return 0;
}
