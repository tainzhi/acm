#include <stdio.h>
#include <string.h>

#define HOOK_NUM 22
#define NATURAL_NUM 26
#define DIFF 7600

int dp[NATURAL_NUM][2*DIFF];
int hooks[HOOK_NUM];
int natural[NATURAL_NUM];

int main() {
    int c, g;
    while (scanf("%d %d", &c, &g) != EOF) {
        for (int i = 1; i <= c; ++i)
            scanf("%d", &hooks[i]);
        for (int i = 1; i <= g; ++i)
            scanf("%d", &natural[i]);
        for (int i = 0; i <= g; ++i)
                for (int k = 0; k < DIFF * 2; ++k)
                    dp[i][k] = 0;
        for (int i = 1; i <= c; ++i)
            dp[0][7500] = 1;
        int current;
        for (int i = 1; i <= g; ++i)
            for (int j = 1; j <= c; ++j) {
                current = natural[i] * hooks[j];
                int low = 0, high = 2 * DIFF;
                if (current > 0)
                    low = current;
                else
                    high = 2  * DIFF + current;
                for (int k = low; k < high; ++k)
                    dp[i][k] += dp[i - 1][k - current];
            }
        int solution = dp[g][7500];
        printf("%d\n", solution);
    }
    return 0;
}
