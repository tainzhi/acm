#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 110
#define MAX_TIME 1010
#define MAX_INT 10000000

int dp[MAX_SIZE][MAX_TIME];
int o_t[MAX_SIZE], o_v[MAX_SIZE];

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T, M;
    while (scanf("%d %d", &T, &M) != EOF) {
        for (int i = 1; i <= M; ++i) {
            scanf("%d %d", &o_t[i], &o_v[i]);
        }
        int max_val = -1;
        for (int j = 0; j < MAX_TIME; ++j)
            dp[0][j] = 0;
        dp[0][0] = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = T; j >= o_t[i]; --j) {
                dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - o_t[i]] + o_v[i]);
                max_val = Max(dp[i][j], max_val);
            }
            for (int j = o_t[i] - 1; j >= 0; --j)
                dp[i][j] = dp[i - 1][j];
        }
        printf("%d\n", max_val);
    }
    return 0;
}
