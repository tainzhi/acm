#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

int missor[MAX_SIZE];
int dp[MAX_SIZE], pre[MAX_SIZE];

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        for (int i = 0; i < k; ++i)
            scanf("%d", &missor[i]);
        int max_m = 0;
        for (int i = 0; i < k; ++i) {
            dp[i] = 1;
            pre[i] = i;
            for (int j = 0; j < i; ++j) {
                if (missor[j] >= missor[i] && (dp[i] < (dp[j] + 1))) {
                    dp[i] = dp[j] + 1;
                }
            }
            /* printf("dp[%d]=%d\n", i, dp[i]); */
            if (max_m < dp[i])
                max_m = dp[i];
        }
        printf("%d\n", max_m);
    }
    return 0;
}
