/*******************************************************************************
* File     : SSIGN-Assignments.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-14 21:48:49
* Modified : 2017-04-15 07:02:02
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 22

int matrix[22][22];
long long dp[2][(1<<20) + 1];

int main() {
    int c;
    while (scanf("%d", &c) != EOF) {
        while ((--c) >= 0) {
            /* printf("c=%d\n", c); */
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    scanf("%d", &matrix[i][j]);
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n; ++i) {
                /* printf("1<<%d=%d\n", i, 1<<i); */
                if (matrix[0][i] == 1) {
                    dp[0][1<<i] = 1;
                }
            }
            int p = 0;
            for (int i = 1; i < n; ++i) {
                /* printf("p=%d\n", p); */
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 1) {
                        for (int k = 0; k < 1<<n; k++) {
                            if ((k & (1<<j)) == 0) {
                                /* printf("%d&%d=%d %d|(1<<%d)=%d\n", k, 1<<j, k & (1<<j), k, 1<<j, k|(1<<j)); */
                                dp[p ^ 1][k | (1<<j)] += dp[p][k];
                            }
                        }
                    }
                }
                p = p ^ 1;
            }
            /* printf("(1<<%d)-1=%d\n", n, (1<<n)-1); */
            /* for (int i = 0; i < (1<<n); ++i) */
            /*     printf("%lld\n", dp[p][i]); */
            printf("%lld\n", dp[p][(1<<n) - 1]);
        }
    }
    return 0;
}


