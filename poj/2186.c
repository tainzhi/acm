#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50010
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct StructEdge {
    int to, next;
}Edge;

Edge edges[MAX_SIZE];
int edge_count, head[MAX_SIZE];
int depth_count, depth[MAX_SIZE], low[MAX_SIZE];
int top, stack[MAX_SIZE], onstack[MAX_SIZE], belong[MAX_SIZE];
int indegree[MAX_SIZE], outdegree[MAX_SIZE];
int component_count, component[MAX_SIZE];

void Targan(int u) {
    depth[u] = low[u] = ++depth_count;
    stack[++top] = u;
    onstack[u] = 1;
    int v;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        v = edges[i].to;
        if (!depth[v]) {
            Targan(v);
            low[u] = MIN(low[u], low[v]);
        } else if (onstack[u]) {
            low[u] = MIN(low[u], depth[v]);
        }
    }
    if (low[u] == depth[u]) {
        ++component_count;
        do {
            v = stack[top--];
            onstack[v] = 0;
            belong[v] = component_count;
            ++component[component_count];
        } while (v != u);
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(head, -1, sizeof(head));
        edge_count = 0;
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            edges[edge_count].to = v;
            edges[edge_count].next = head[u];
            head[u] = edge_count++;
        }
        depth_count = 0;
        memset(depth, 0, sizeof(depth));
        memset(low, 0, sizeof(low));
        memset(belong, 0, sizeof(belong));
        top = 0;
        memset(onstack, 0, sizeof(onstack));
        component_count = 0;
        memset(component, 0, sizeof(component));
        for (int i =  1; i <= n; ++i) {
            if (!depth[i]) {
                Targan(i);
            }
        }
        memset(indegree, 0, sizeof(indegree));
        memset(outdegree, 0, sizeof(outdegree));
        for (int i = 1; i <= n; ++i) {
            for (int j = head[i]; j != -1; j = edges[j].next) {
                if (belong[i] != belong[edges[j].to]) {
                    ++indegree[belong[edges[j].to]];
                    ++outdegree[belong[i]];
                }
            }
        }
        int out_0_count = 0, out_0_node;
        for (int i = 1; i <= component_count; ++i)
            if (outdegree[i] == 0) {
                ++out_0_count;
                out_0_node = i;
            }
        printf("%d\n", out_0_count > 1 ? 0 : component[out_0_node]);
    }
    return 0;
}






