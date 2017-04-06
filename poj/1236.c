#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_SIZE 105

int matrix[MAX_SIZE][MAX_SIZE];
int final[MAX_SIZE];
int visit[MAX_SIZE];
int indegree[MAX_SIZE];
int outdegree[MAX_SIZE];
int count;

void DFS(int u, int n) {
    visit[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i] && matrix[u][i] == 1) {
            DFS(i, n);
        }
    }
    final[++count] = u;
}

void FloodFill(int u, int tag, int n) {
    visit[u] = tag;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i] && matrix[i][u] == 1) {
            FloodFill(i, tag, n);
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int temp;
        memset(matrix, 0, sizeof(matrix));
        memset(visit, 0, sizeof(visit));
        memset(final, 0, sizeof(final));
        for (int i = 1; i <= n; ++i) {
            while (scanf("%d", &temp)) {
                if (temp == 0) break;
                matrix[i][temp] = 1;
            }
        }
        count = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visit[i]) {
                DFS(i, n);
            }
        }
        int component = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = n; i >= 1; --i) {
            if (!visit[final[i]]) {
                FloodFill(final[i], ++component, n);
            }
        }
        memset(indegree, 0, sizeof(indegree));
        memset(outdegree, 0, sizeof(outdegree));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i][j] == 1 && visit[i] != visit[j]) {
                    ++indegree[visit[j]];
                    ++outdegree[visit[i]];
                }
            }
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= component; ++i) {
            if (indegree[i] == 0) ++ans1;
            if (outdegree[i] == 0) ++ans2;
        }
        /* printf("component=%d\n", component); */
        if (component == 1)
            printf("1\n0\n");
        else
            printf("%d\n%d\n", ans1, MAX(ans1, ans2));
    }
    return 0;
}
