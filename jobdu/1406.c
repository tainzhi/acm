#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 510

typedef struct ArcNode {
    int adjacent;
    int cost;
    struct ArcNode *next;
}Arc, *ArcP;

typedef struct VertexNode {
    ArcP first;
}Vertex;
Vertex graph[MAX_SIZE];

int distance[MAX_SIZE];
int pre[MAX_SIZE];
int inset[MAX_SIZE];
int paths[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        distance[i] = -1;
        pre[i] = 0;
        inset[i] = 0;
        paths[i] = 0;
    }
    distance[start] = 0;
    inset[start] = 1;
    paths[start] = 1;
    int new_node = start, min_distance;
    ArcP point;
    for (int i = 1; i < nodes; ++i) {
        for (point = graph[new_node].first; point; point = point->next) {
            int next = point->adjacent;
            if (!inset[next]) {
                if (distance[next] == -1) {
                    distance[next] = distance[new_node] + point->cost;
                    paths[next] = paths[new_node];
                } else if (distance[next] != -1) {
                    if (distance[next] > distance[new_node] + point->cost) {
                        distance[next] = distance[new_node] + point->cost;
                        paths[next] = paths[new_node];
                    } else if (distance[i] != -1 &&  distance[next] == distance[new_node] + point->cost) {
                        paths[next] += paths[new_node];
                    }
                }
            }
        }
        min_distance = INT_MAX;
        for (int j = 1; j <= nodes; ++j) {
            if (!inset[j] && distance[j] != -1 && distance[j] < min_distance) {
                min_distance = distance[j];
                new_node = j;
            }
        }
        inset[new_node] = 1;
    }
}



void AddEdge(int u, int v, int t) {
    int exist = 0;
    ArcP point;
    for (point = graph[u].first; point; point = point->next) {
        if (point->adjacent == v) {
            exist = 1;
            if (point->cost > t)
                point->cost = t;
        }
    }
    if (!exist) {
        point = (ArcP)malloc(sizeof(Arc));
        point->adjacent = v;
        point->cost = t;
        point->next = graph[u].first;
        graph[u].first = point;
    }
}

void DeleteEdge(int nodes) {
    ArcP point, tp;
    for (int i = 1; i <= nodes; ++i) {
        for (point = graph[i].first; point; ) {
            tp = point;
            point = point->next;
            free(tp);
        }
        graph[i].first = NULL;
    }
}

int main() {
    int n, m;
    int u, v, t;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i)
            graph[i].first = NULL;
        while (--m >= 0) {
            scanf("%d %d %d", &u, &v, &t);
            AddEdge(u, v, t);
            AddEdge(v, u, t);
        }
        Dijkstra(1, n);
        if (paths[n] == 0)
            printf("-1 -1\n");
        else
            printf("%d %d\n", distance[n], paths[n]);
        DeleteEdge(n);
        /* printf("\n-----------------\n"); */
    }
    return 0;
}
