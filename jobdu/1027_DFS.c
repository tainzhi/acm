#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1010
#define MAX_INT 2^30

int matrix[MAX_SIZE][MAX_SIZE];

// DFS实现连通图的判断
void Dfs(int u, int vivist[], int n);
bool Judge(int visit[], int degree[], int n);

int main() {
    int n, m;
    int visit[MAX_SIZE];
    int degree[MAX_SIZE];
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        memset(matrix, -1, sizeof(matrix));
        memset(visit, 0, sizeof(visit));
        memset(degree, 0, sizeof(degree));
        scanf("%d", &m);
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            matrix[u][v] = 1;
            ++degree[u];
            ++degree[v];
        }
        Dfs(1, visit, n);
        printf("%d\n", Judge(visit, degree, n) ? 1 : 0);
    }
    return 0;
}

void Dfs(int u, int visit[], int n) {
    visit[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i] && matrix[u][i] == 1)
            Dfs(i, visit, n);
    }
}

bool Judge(int visit[], int degree[], int n) {
    for (int i = 1; i <= n; ++i) {
        /* printf("%d visit=%d degree=%d\n", i, visit[i], degree[i]); */
        if (visit[i] != 1 || degree[i] % 2 != 0)
            return false;
    }
    return true;
}




