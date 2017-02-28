#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT 1123451234
#define MAX_SIZE 2010

int dp[MAX_SIZE][MAX_SIZE];
int object[MAX_SIZE];

int Min(int a, int b) {
    return a < b ? a : b;
}

int Compare(const void *a, const void *b) {
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    if (n1 < n2)
        return -1;
    else if (n1 > n2)
        return 1;
    else
        return 0;
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &object[i]);
        qsort(object + 1, n, sizeof(int), Compare);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = MAX_INT;
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; 2 * j <= i; ++j) {
                dp[i][j] = Min(dp[i - 1][j], dp[i - 2][j-1] + pow(object[i] - object[i - 1], 2));
            }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
