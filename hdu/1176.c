#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TIME_SIZE 100010
#define X_RAILS 11
#define MAX_INT 10000000

int dp[TIME_SIZE][X_RAILS];
int cake[TIME_SIZE][X_RAILS];

int Max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n, x, T;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        memset(cake, 0, sizeof(cake));
        for (int i = 0; i < TIME_SIZE; ++i)
            for (int j = 0; j < X_RAILS; ++j)
                dp[i][j] = MAX_INT * (-1);
        int max_time = -1;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &T);
            ++cake[T][x];
            if (max_time < T)
                max_time = T;
        }
        dp[0][5] = 0;
        for (int i = 1; i <= max_time; ++i) {
            dp[i][0] = Max(dp[i - 1][0] ,dp[i-1][1]) + cake[i][0];
            for (int j = 1; j < 10; ++j) {
                dp[i][j] = Max(Max(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + cake[i][j];
            }
            dp[i][10] = Max(dp[i - 1][9], dp[i - 1][10]) + cake[i][10];
            /* printf("dp[%d][4]=%d\n", i, dp[i][4]); */
            /* printf("dp[%d][5]=%d\n", i, dp[i][5]); */
            /* printf("dp[%d][6]=%d\n", i, dp[i][6]); */
        }
        int max_cake = -1;
        for (int i = 0; i< 11; ++i) {
            /* printf("dp x=%d cake=%d\n", i, dp[T][i]); */
            if (max_cake < dp[T][i])
                max_cake = dp[T][i];
        }
        printf("%d\n", max_cake);
    }
    return 0;
}
                


