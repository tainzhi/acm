#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1010
#define MAX_INT 10e10

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
        /* printf("min_dist=%d\n", min_dist); */
        /* for (int j = 1; j <= nodes; ++j) { */
        /*     printf("%d final=%d dist=%d\n", j, final[j], dist[j]); */
        /* } */
        for (int j = 1; j <= nodes; ++j)
            if (final[j] == 0 && dist[j] != -1 && min_dist > dist[j]) {
                min_dist = dist[j];
                min_position = j;
                flag = true;
            }
        /* printf("min_position=%d\n", min_position); */
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
    int n, cows, u, v, d;
    while (scanf("%d %d", &n, &cows) != EOF) {
        for (int i = 1; i <= n; ++i)
            for (int j =1; j <= n; ++j)
                matrix[i][j] = matrix[j][i] = -1;
        while (--cows >= 0) {
            scanf("%d %d %d", &u, &v, &d);
            matrix[u][v] = matrix[v][u] = d;
        }
        Dijkstra(n, n);
        printf("%d\n", dist[1]);
    }
    return 0;
}


