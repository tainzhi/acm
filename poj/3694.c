#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 200010
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct StructEdge {
    int to, next;
}Edge;
Edge edges[MAX_SIZE];
int edge_count, head[MAX_SIZE];
int depth_count, depth[MAX_SIZE], low[MAX_SIZE], father[MAX_SIZE];
int inset[MAX_SIZE], rank[MAX_SIZE];
int bridges;

int Find(int x) {
    if (x != inset[x])
        inset[x] = Find(inset[x]);
    return inset[x];
}

int Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return 1;
    else {
        if (rank[x] > rank[y])
            inset[y] = x;
        else {
            inset[x] = y;
            if (rank[x] == rank[y])
                ++rank[y];
        }
        return 0;
    }
}

void Targan(int u, int _father) {
    depth[u] = low[u] = ++depth_count;
    int v;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        v = edges[i].to;
        /* printf("v=%d _father=%d\n", v, _father); */
        if (v == _father) continue;
        if (!depth[v]) {
            father[v] = u;
            Targan(v, u);
            low[u] = MIN(low[u], low[v]);
            if (low[v] > depth[u])
                ++bridges;
            else
                Union(u, v);
        } else {
            low[u] = MIN(low[u], depth[v]);
        }
    }
}

void LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    /* printf("inset: "); */
    /* for (int i = 1; i <= 3; ++i) */
    /*     printf("%d ", Find(i)); */
    /* printf("\nfather: "); */
    /* for (int i = 1; i <= 3; ++i) */
    /*     printf("%d ", father[i]); */
    /* printf("\n"); */
    /*  */
    while (depth[u] > depth[v]) {
        /* printf("u=%d v=%d bridges=%d\n", u, v, bridges); */
        if (!Union(u, father[u]))
            --bridges;
        u = father[u];
        /* printf("u=%d v=%d bridges=%d\n", u, v, bridges); */
    }
    while (u != v) {
        if (!Union(v, father[v]))
            --bridges;
        v = father[v];
    }
}

void AddEdge(int u, int v) {
    edges[edge_count].to = v;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

int main() {
    int n, m, ncase = 0, q, u, v;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        edge_count = 0;
        memset(head, -1, sizeof(head));
        while (--m >= 0) {
            scanf("%d %d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            rank[i] = 1;
            inset[i] = i;
        }
        depth_count = 0;
        memset(depth, 0, sizeof(depth));
        memset(low, 0, sizeof(depth));
        bridges = 0;
        for (int i = 1; i <= n; ++i) {
            if (!depth[i]) {
                Targan(i, i);
            }
        }
        /* printf("targan->%d\n", bridges); */
        scanf("%d", &q);
        printf("Case %d:\n", ++ncase);
        while (--q >= 0) {
            scanf("%d %d", &u, &v);
            LCA(u, v);
            printf("%d\n", bridges);
        }
        printf("\n");
    }
    return 0;
}
