/*******************************************************************************
* File     : 3311.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-15 17:12:44
* Modified : 2017-04-17 06:39:39
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 15

int matrix[MAX_SIZE][MAX_SIZE];
int short_path[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][1<<MAX_SIZE];

int n;
int max_int = 100000000;

int Min(int x, int y) {
    return x < y ? x : y;
}

int DFS(int from, int s) {
    if (s == 0) {
        dp[from][s] = short_path[from][0];
    } else if (dp[from][s] == max_int) {
        for (int j = 1; j <= n; ++j) {
            if (((1<<(j-1)) & s)) {
                /* printf("from=%d s=%d j=%d next_s=%d\n", from, s, j, s & (~(1<<(from-1)))); */
                dp[from][s] = Min(dp[from][s], short_path[from][j] + DFS(j, s & (~(1<<(from-1)))));
            }
        }
    }
    /* printf("%d\n", dp[from][s]); */
    return dp[from][s];
}

int main() {
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) {
                scanf("%d", &matrix[i][j]);
                short_path[i][j] = matrix[i][j];
            }

        for (int k = 0; k <= n; ++k)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= n; ++j)
                    short_path[i][j] = Min(short_path[i][j],
                            short_path[i][k] + short_path[k][j]);

        for (int i = 1; i <= n; ++i)
            for (int s = 0; s < (1<<n); ++s)
                dp[i][s] = max_int;

        int ans = max_int;
        for (int i = 1; i <= n; ++i)
            ans = Min(ans, short_path[0][i] + DFS(i, (1<<n) -1));
        printf("%d\n", ans);
    }
    return 0;
}
