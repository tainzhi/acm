/*******************************************************************************
* File     : 3311.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-15 17:12:44
* Modified : 2017-04-15 17:46:55
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 15
#define MAX_INT 1e11

int matrix[MAX_SIZE][MAX_SIZE];
int short_path[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][1<<MAX_SIZE];

int Min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int n;
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
            for (int j = 0; j < (1<<n); ++j)
                dp[i][j] = (int)MAX_INT;
        for (int i = 0; i <= n; ++i)
            dp[i][0] = short_path[i][0];
        int next_s;
        for (int i = 1; i <= n; ++i) {
            for (int s = 1;  s < (1<<n); ++s) {
                if (s & (1<<(i-1))) {
                        next_s = (s & (~(1<<(i-1))));
                        for (int j = 1; j <= n; ++j) {
                            if (next_s & (1<<(i-1))) {
                                dp[i][s] = Min(dp[i][s],
                                        short_path[i][j] + dp[j][next_s]);
                            }
                        }
                }
            }
        }
        int ans = (int)MAX_INT;
        for (int i = 1; i <= n; ++i)
            ans = Min(ans, short_path[0][i] + dp[i][(1<<n) -1]);
        printf("%d\n", ans);
    }
    return 0;
}
