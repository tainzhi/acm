#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

long long int dp[MAX_SIZE];

int main() {
    int n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 100; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}

