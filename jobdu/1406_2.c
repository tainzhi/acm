#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 510

int matrix[MAX_SIZE][MAX_SIZE];
int distance[MAX_SIZE];
int paths[MAX_SIZE];
int inset[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        distance[i] = -1;
        paths[i] = 0;
        inset[i] = 0;
    }
    int min_dist;
    int new_node = start;
    distance[start] = 0;
    inset[start] = 1;
    paths[start] = 1;
    for (int i = 1; i < nodes; ++i) {
        for (int j = 1; j <= nodes; ++j)
            if (!inset[j] && matrix[new_node][j] != 0) {
                if (distance[j] == -1) {
                    distance[j] = distance[new_node] + matrix[new_node][j];
                    paths[j] = paths[new_node];
                } else {
                    if (distance[j] > distance[new_node] + matrix[new_node][j]) {
                        distance[j] = distance[new_node] + matrix[new_node][j];
                        paths[j] = paths[new_node];
                    } else if (distance[j] == distance[new_node] + matrix[new_node][j]) {
                        paths[j] += paths[new_node];
                    }
                }
            }
        min_dist = INT_MAX;
        for (int j = 1; j <= nodes; ++j) {
            if (!inset[j] && distance[j] != -1 && distance[j] < min_dist) {
                min_dist = distance[j];
                new_node = j;
            }
        }
        inset[new_node] = 1;
    }
}

int main() {
    int n, m;
    int u, v, t;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(matrix, 0, sizeof(matrix));
        while (--m >= 0) {
            scanf("%d %d %d", &u, &v, &t);
            if (matrix[u][v] == 0 || (matrix[u][v] != 0 && matrix[u][v] > t))
                matrix[u][v] = matrix[v][u] = t;
        }
        Dijkstra(1, n);
        if (distance[n] == -1) 
            printf("-1 -1\n");
        else
            printf("%d %d\n", distance[n], paths[n]);
    }
    return 0;
}



