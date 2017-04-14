/*******************************************************************************
* File     : 3696.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-14 13:50:33
* Modified : 2017-04-14 20:31:13
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10010

int head_index;
int head[MAX_SIZE], edge[MAX_SIZE * 5], next[MAX_SIZE * 5];
double change[MAX_SIZE * 5];
int degree[MAX_SIZE], visit[MAX_SIZE];
double weight[MAX_SIZE], price[MAX_SIZE];

double Max(double x, double y) {
    /* return x - y > 1e-8? x : y; */
    return x > y ? x : y;
}

void AddEdge(int u, int v, double c) {
    edge[head_index] = v;
    change[head_index] = c;
    next[head_index] = head[u];
    head[u] = head_index++;
}

void DFS(int u) {
    int v;
    for (int i = head[u]; i != -1; i = next[i]) {
        v = edge[i];
        if (!visit[v])
            DFS(v);
        /* printf("%d->%d, %.2lf, %.2lf%.2lf\n", u, v, price[u], price[v], change[i] * price[v]); */
        price[u] = Max(price[u], change[i] * price[v]);
    }
    visit[u] = 1;
}

int main() {
    int n, m, k;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &price[i], &weight[i]);
        }
        scanf("%d", &m);
        head_index = 0;
        memset(head, -1,sizeof(head));
        memset(visit, 0, sizeof(visit));
        memset(degree, 0, sizeof(degree));
        int u, u_p;
        double c;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &k, &u);
            u_p = u;
            for (int j = 0; j < k - 1; ++j) {
                scanf("%lf %d", &c, &u);
                AddEdge(u_p, u, c);
                u_p = u;
                ++degree[u];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 0)
                DFS(i);
        }
        double sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += weight[i] * price[i];
        printf("%.2lf\n", sum);

    }
    return 0;
}
