#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 1010

int matrix[MAX_SIZE][MAX_SIZE];
int final[MAX_SIZE], dist[MAX_SIZE], pre[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        final[i] = 0;
        dist[i] = -1;
        pre[i] = 0;
    }
    final[start] = 1;
    dist[start] = 0;
    int new_node = start, min_dist;
    for (int i = 2; i <= nodes; ++i) {
        for (int j = 1; j <= nodes; ++j) {
            if (!final[j]) {
                if (matrix[new_node][j] != -1 &&
                        (dist[j] == -1 || (dist[new_node] + matrix[new_node][j] < dist[j]))) {
                    dist[j] = dist[new_node] + matrix[new_node][j];
                }
            }
        }
        min_dist = INT_MAX;
        for (int j = 1; j <= nodes; ++j)
            if (final[j] == 0 && dist[j] != -1 && min_dist > dist[j]) {
                min_dist = dist[j];
                new_node = j;
            }
        final[new_node] = 1;
    }
}

int main() {
    int n, m, a, b, x, y, t;
    while (scanf("%d %d", &n, &m) != EOF) {
        scanf("%d %d", &a, &b);
        memset(matrix, -1, sizeof(matrix));
        while (--m >= 0) {
            scanf("%d %d %d", &x, &y, &t);
            if (matrix[x][y] == -1 || matrix[x][y] > t) {
                matrix[x][y] = matrix[y][x] = t;
            }
        }
        Dijkstra(a, n);
        printf("%d\n", dist[b]);

    }
    return 0;
}
