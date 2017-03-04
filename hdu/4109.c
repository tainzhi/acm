#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct StructEdge {
    int adjacent;
    int distance;
    struct StructEdge *next;
}Edge;

typedef struct StructVertex {
    Edge *first;
}Vertex;
Vertex graph[1010];

int in_stack[1010],in_top;
int out_stack[1010], out_top;
int ve[1010], vl[1010];
int indegree[1010];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int u, v, t;
        for (int i = 0; i < n; ++i) 
            graph[i].first = NULL;
        memset(indegree, 0, sizeof(indegree));
        memset(vl, 0, sizeof(vl));
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &t);
            Edge *edge = (Edge *)malloc(sizeof(Edge));
            edge->adjacent = v;
            edge->distance = t;
            edge->next = graph[u].first;
            graph[u].first = edge;
            ++indegree[v];
        }
        in_top = out_top = 0;
        // Get vl[0...n-1]
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0) {
                in_stack[++in_top] = i;
                vl[i] = 1;
            }
        Edge *e_point;
        while (in_top > 0) {
            u = in_stack[in_top--];
            out_stack[++out_top] = u;
            for (e_point = graph[u].first; e_point; e_point = e_point->next) {
                v = e_point->adjacent;
                vl[v] = MAX(vl[v], vl[u] + e_point->distance);
                if ((--indegree[v]) == 0)
                    in_stack[++in_top] = v;
            }
        }
        int max_time = -1;
        for (int i = 0; i < n; ++i)
            if (max_time < vl[i])
                max_time = vl[i];
        printf("%d\n", max_time);
    }
    return 0;
}
