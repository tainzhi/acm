#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 510

int matrix[MAX_SIZE][MAX_SIZE];
int distance[MAX_SIZE];
int inset[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    int new_node;
    int min_dist = INT_MAX;
    for (int i = 1; i <= nodes; ++i) {
        distance[i] = -1;
        inset[i] = 0;
        if (matrix[start][i] != 0) {
            distance[i] = matrix[start][i];
            if (min_dist > distance[i]) {
                min_dist = distance[i];
                new_node = i;
            }
        }
    }
    /* printf("new_node=%d\n", new_node); */
    for (int i = 1; i < nodes; ++i) {
        for (int j = 1; j <= nodes; ++j)
            if (!inset[j] && matrix[new_node][j] != 0) {
                if (distance[j] == -1)
                    distance[j] = distance[new_node] + matrix[new_node][j];
                else if (distance[j] > distance[new_node] + matrix[new_node][j])
                        distance[j] = distance[new_node] + matrix[new_node][j];
                }
        min_dist = INT_MAX;
        for (int j = 1; j <= nodes; ++j) {
            if (!inset[j] && distance[j] != -1 && distance[j] < min_dist) {
                min_dist = distance[j];
                new_node = j;
            }
        }
        inset[new_node] = 1;
        /* printf("new_node=%d\n", new_node); */
    }
}

int main() {
    int n, m, s;
    int u, v, t;
    while (scanf("%d %d %d", &n, &m, &s) != EOF) {
        memset(matrix, 0, sizeof(matrix));
        while (--m >= 0) {
            scanf("%d %d %d", &u, &v, &t);
            if (matrix[u][v] == 0 || (matrix[u][v] != 0 && matrix[u][v] > t))
                matrix[u][v] = t;
        }
        Dijkstra(s, n);
        if (distance[s] <= 0)
            printf("help!\n");
        else
            printf("%d\n", distance[s]);
    }
    return 0;
}



