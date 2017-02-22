#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1010

typedef struct ArcNode {
    int adjacent;
    int dist;
    int cost;
    struct ArcNode *next;
}Arc;

typedef struct StructCost {
    int dist;
    int cost;
}Cost;

typedef struct VertexNode {
    Arc * first;
}Vertex;
Vertex graph[MAX_SIZE];
int pre[MAX_SIZE], inset[MAX_SIZE];
Cost distance[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        distance[i].dist = -1;
        distance[i].cost = -1;
        pre[i] = -1;
        inset[i] = 0;
    }
    Arc *arc_point;
    int new_point;
    distance[start].dist = 0;
    distance[start].cost = 0;
    pre[start] = -1;
    inset[start] = 1;
    new_point = start;
    int min_dist;
    int temp_dist, temp_cost, next_node;
    for (int i = 2; i <= nodes; ++i) {
        for (arc_point = graph[new_point].first; arc_point != NULL; arc_point = arc_point -> next) {
            next_node = arc_point->adjacent;
            if (inset[next_node] == 0) {
                pre[next_node] = new_point;
                temp_dist = distance[new_point].dist + arc_point->dist;
                temp_cost = distance[new_point].cost + arc_point->cost;
                if (distance[next_node].dist == -1 ||
                        temp_dist < distance[next_node].dist ||
                        (temp_dist == distance[next_node].dist && temp_cost < distance[next_node].cost)) {
                    distance[next_node].dist = temp_dist;
                    distance[next_node].cost = temp_cost;
                }
            }
        }
        min_dist = INT_MAX;
        for (int j = 1; j <= nodes; ++j) {
            if (inset[j] == 0 && distance[j].dist != -1) {
                    if (min_dist > distance[j].dist) {
                        min_dist = distance[j].dist;
                        new_point = j;
                }
            }
        }
        inset[new_point] = 1;
    }
}

void AddEdge(int vertex, int adjacent, int dist, int cost) {
    Arc *point = (Arc *)malloc(sizeof(Arc));
    point->adjacent = adjacent;
    point->dist = dist;
    point->cost = cost;
    point->next = graph[vertex].first;
    graph[vertex].first = point;
}

void DeleteEdge(int nodes) {
    Arc *point, *temp;
    for (int i = 1; i <= nodes; ++i) {
        for (point = graph[i].first; point; ) {
            temp = point;
            point = point->next;
            free(temp);
        }
    }
}

int main() {
    int n, m, a, b, d, p, s, t;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; ++i)
            graph[i].first = NULL;
        while (--m >= 0) {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            AddEdge(a, b, d, p);
            AddEdge(b, a, d, p);
        }
        scanf("%d %d", &s, &t);
        Dijkstra(s, n);
        printf("%d %d\n", distance[t].dist, distance[t].cost);
        DeleteEdge(n);
    }
    return 0;
}
