/*******************************************************************************
* File     : 4105.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-13 07:15:00
* Modified : 2017-04-13 11:00:41
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 110
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int dp[2][MAX_SIZE][MAX_SIZE];
char str[MAX_SIZE];

int Compare(int low, int mid, int high) {
    int num1 = 0, num2 = 0;
    for (int i = low; i < mid; ++i)
        num1 = (num1 * 10 + str[i]);
    for (int i = mid; i <= high; ++i)
        num2 = (num2 * 10 + str[i]);
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", str);
        int length = strlen(str);
        for (int i = 0; i < length; ++i)
            str[i] -= '0';
        memset(dp, -1, sizeof(dp));
        for (int k = 1; k <= length; ++k)
            dp[0][k - 1][k] = 0;
        for (int i = 1; i < length; ++i) 
            for (int k = 1; k < i + 1; ++k)
                for (int j = 1; j <= i + 1 - k; ++j) {
                    int temp = Compare(i - k - j + 1, i - k + 1, i);
                    if (temp < 0)
                        dp[1][i][k] = MAX(dp[1][i][k], dp[0][i - k][j] + 1);
                    else if (temp > 0) {
                        dp[0][i][k] = MAX(dp[0][i][k], dp[1][i - k][j] + 1);
                    }
                }
        int ans = 0;
        for (int k = 1; k <= length; ++k) {
            ans = MAX(ans, dp[0][length - 1][k]);
            ans = MAX(ans, dp[1][length - 1][k]);
        }
        printf("%d\n", ans);
    }
    return 0;
}



