#include <stdio.h>
#include <string.h>

#define HOOK_NUM 22
#define NATURAL_NUM 26
#define DIFF 7600

int dp[NATURAL_NUM][HOOK_NUM][DIFF];
int hooks[HOOK_NUM];
int natural[NATURAL_NUM];

int main() {
    int c, g;
    while (scanf("%d %d", &c, &g) != EOF) {
        for (int i = 1; i <= c; ++i)
            scanf("%d", &hooks[i]);
        for (int i = 1; i <= g; ++i)
            scanf("%d", &natural[i]);
        for (int i = 0; i < g; ++i)
            for (int j = 0; j < c; ++j)
                for (int k = 0; k < DIFF * 2; ++k)
                    dp[i][j][k] = 0;
        for (int i = 1; i <= c; ++i)
            dp[0][i][7500] = 1;
        int current;
        for (int i = 1; i <= g; ++i)
            for (int j = 1; j <= c; ++j) {
                current = natural[i] * hooks[j];
                for (int k = 0; k < DIFF * 2; ++k) {
                    for (int j = 1; j <= c; ++j)
                        dp[i][j][k] = dp[i-1][j][k-current];
                }
            }
        int solution = 0;
        for (int i = 1; i <= c; ++i)
            solution += dp[g][i][7500];
        printf("%d\n", solution);
    }
    return 0;
}



