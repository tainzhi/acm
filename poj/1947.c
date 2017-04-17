/*******************************************************************************
* File     : 1947.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-17 13:23:51
* Modified : 2017-04-17 13:26:54
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_SIZE 200

int father[MAX_SIZE], son[MAX_SIZE], brother[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int n, p;
int max_int = 1000000;

int Min(int a, int b) {
    return a < b ? a : b;
}

void DFS(int root) {
    dp[root][1] = 0;
    int child, tmp;
    child = son[root];
    while (child != 0) {
        DFS(child);
        for (int i = p; i >= 1; --i) {
            tmp = dp[root][i] + 1;
            for (int j = 1; j < i; ++j) {
                tmp = Min(tmp, dp[child][j] + dp[root][i-j]);
            }
            dp[root][i] = tmp;
        }
        child = brother[child];
    }
}

int main() {
    while (scanf("%d %d", &n, &p) != EOF) {
        memset(father, 0, sizeof(father));
        memset(son, 0, sizeof(son));
        int u, v;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d", &u, &v);
            father[v] = 1;
            brother[v] = son[u];
            son[u] = v;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= p; ++j)
                dp[i][j] = max_int;
        int root = -1;
        for (int i = 1; i <= n; ++i)
            if (!father[i]) {
                root = i;
                break;
            }
        DFS(root);
        int ans = dp[root][p];
        for (int i = 1; i <= n; ++i)
            ans = Min(ans, dp[i][p] + 1);
        printf("%d\n", ans);
    }
    return 0;
}


