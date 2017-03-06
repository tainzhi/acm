#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define  MAX_SIZE 100001

typedef struct StructEdge {
    int to, next;
}Edge;
Edge edge[MAX_SIZE];
int head[MAX_SIZE], edge_count;
int depth_count, depth[MAX_SIZE], low[MAX_SIZE];
int top, stack[MAX_SIZE], onstack[MAX_SIZE];
int com_count, component_set[MAX_SIZE], belong[MAX_SIZE];
int indegree[MAX_SIZE], outdegree[MAX_SIZE];

void Targan(int u) {
    depth[u] = low[u] = ++depth_count;
    stack[++top] = u;
    onstack[u] = 1;
    int v;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (!depth[v]) {
            Targan(v);
            low[u] = MIN(low[u], low[v]);
        } else if (onstack[v]) {
            low[u] = MIN(low[u], depth[v]);
        }
    }
    if (depth[u] == low[u]) {
        ++com_count;
        do {
            v = stack[top--];
            onstack[v] = 0;
            belong[v] = com_count;
            ++component_set[com_count];
        } while (v != u);
    }
}

int main() {
    int T;
    int n, m;
    while (scanf("%d", &T) != EOF) {
        for (int ij = 1; ij <= T; ++ij) {
            scanf("%d %d", &n, &m);
            memset(head, -1, sizeof(head));
            edge_count = 0;
            int u, v;
            for (int i = 0; i < m; ++i) {
                scanf("%d %d", &u, &v);
                edge[edge_count].to = v;
                edge[edge_count].next = head[u];
                head[u] = edge_count++;
            }
            memset(depth, 0, sizeof(depth));
            memset(low, 0, sizeof(low));
            memset(onstack, 0, sizeof(onstack));
            memset(component_set, 0, sizeof(component_set));
            depth_count = 0;
            com_count = 0;
            top = 0;
            for (int i = 1; i <= n; ++i) {
                if (depth[i] == 0) {
                    Targan(i);
                }
            }
            memset(indegree, 0, sizeof(indegree));
            memset(outdegree, 0, sizeof(outdegree));
            for (int i = 1; i <= n; ++i) {
                for (int j = head[i]; j != -1; j = edge[j].next) {
                    u = edge[j].to;
                    if (belong[i] != belong[u]) {
                        ++outdegree[belong[i]];
                        ++indegree[belong[u]];
                    }
                }
            }
            long long ans = n * (n - 1) - m;
            long long min_xy = 123123123123123;
            for (int i = 1; i <= com_count; ++i) {
                if (!indegree[i] || !outdegree[i]) {
                    min_xy = MIN(min_xy, component_set[i] * (n - component_set[i]));
                }
            }
            printf("Case %d: %lld\n", ij, com_count == 1 ?  -1 : ans - min_xy);
        }
    }
    return 0;
}



