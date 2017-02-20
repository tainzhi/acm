#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1010
#define MAX_INT 10000000

int matrix[MAX_SIZE][MAX_SIZE];
int final[MAX_SIZE], dist[MAX_SIZE], pre[MAX_SIZE];

void Dijkstra(int start, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        final[i] = 0;
        dist[i] = matrix[start][i];
        pre[i] = start;
    }
    final[start] = 1;
    dist[start] = 0;
    int min_position, flag, min_dist;
    for (int i = 2; i <= nodes; ++i) {
        flag = false;
        min_dist = MAX_INT;
        for (int j = 1; j <= nodes; ++j)
            if (final[j] == 0 && dist[j] != -1 && min_dist > dist[j]) {
                min_dist = dist[j];
                min_position = j;
                flag = true;
            }
        if (!flag)
            break;
        final[min_position] = 1;
        for (int j = 1; j <= nodes; ++j) {
            if (!final[j]) {
                if (matrix[min_position][j] != -1 &&
                        (dist[j] == -1 || (min_dist + matrix[min_position][j] < dist[j]))) {
                    dist[j] = min_dist + matrix[min_position][j];
                }
            }
        }
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
