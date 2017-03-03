#include <stdio.h>

#define MAX_SIZE 1010
#define MAX_INT 10009

int dp[MAX_SIZE][MAX_SIZE];

int main() {
    int n, m;
    for (int i = 0; i <= 1000; i++)
        dp[0][i] = 1;
    for (int j = 0; j <= 1000; ++j)
        dp[j][0] = 1;
    for (int j = 1; j <= 1000; ++j) {
        for (int i = 1; i <= 1000; ++i) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MAX_INT;
        }
    }
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d\n", dp[m - 1][n - 1]);
    }
    return 0;
}
