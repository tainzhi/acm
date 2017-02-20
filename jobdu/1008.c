#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1010
#define INT_MAX 2^31

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
    for (arc_point = graph[start].first; arc_point != NULL; arc_point = arc_point->next) {
        distance[arc_point->adjacent].dist = arc_point->dist;
        distance[arc_point->adjacent].cost = arc_point->cost;
    }
    distance[start].dist = 0;
    distance[start].cost = 0;
    pre[start] = -1;
    inset[start] = 1;
    int min_dist, min_cost, min_position;
    int temp_dist, temp_cost, next_node;
    for (int i = 2; i <= nodes; ++i) {
        min_dist = min_cost = INT_MAX;
        for (int j = 1; j <= nodes; ++j) {
            if (distance[j].dist != -1 && 
                    inset[j] == 0 
                    && min_dist > distance[j].dist) {
                min_dist = distance[j].dist;
                min_cost = distance[j].cost;
                min_position = j;
            } else if (min_dist == distance[j].dist && min_cost > distance[j].cost) {
                min_cost = distance[j].cost;
                min_position = j;
            }
        }
        inset[min_position] = 1;
        for (arc_point = graph[min_position].first; arc_point != NULL; arc_point = arc_point -> next) {
            next_node = arc_point->adjacent;
            if (inset[next_node])
                continue;
            pre[next_node] = min_position;
            temp_dist = distance[min_position].dist + arc_point->dist;
            temp_cost = distance[min_position].cost + arc_point->cost;
            if (distance[next_node].dist == -1 || temp_dist < distance[next_node].dist) {
                distance[next_node].dist = temp_dist;
                distance[next_node].cost = temp_cost;
            } else if (temp_dist == distance[next_node].dist && temp_cost < distance[next_node].cost) {
                distance[next_node].cost = temp_cost;
            }
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
        Arc * arc_point;
        while (--m >= 0) {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            arc_point = (Arc *)malloc(sizeof(Arc));
            arc_point->dist = d;
            arc_point->cost = p;
            arc_point->adjacent = b;
            arc_point->next = graph[a].first;
            graph[a].first = arc_point;

            arc_point = (Arc*)malloc(sizeof(Arc));
            arc_point->dist = d;
            arc_point->cost = p;
            arc_point->adjacent = a;
            arc_point->next = graph[b].first;
            graph[b].first = arc_point;
        }
        scanf("%d %d", &s, &t);
        Dijkstra(s, n);
        printf("%d %d\n", distance[t].dist, distance[t].cost);

    }
    return 0;
}
