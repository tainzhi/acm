#include <stdio.h>
#include <string.h>

#define MAX_VERTEX_SIZ 110
#define MAX_INT 1123123123

int matrix[MAX_VERTEX_SIZ][MAX_VERTEX_SIZ];
int distance[MAX_VERTEX_SIZ];
int inset[MAX_VERTEX_SIZ];
int pre_vertex[MAX_VERTEX_SIZ];

int Prim(int vertex_number) {
    for (int i = 1; i <= vertex_number; ++i) {
        distance[i] = -1;
        inset[i] = 0;
        pre_vertex[i] = 0;
    }
    int sum_distance = 0;
    inset[1] = 1;
    int next_vertex = 1;
    int min_distance;
    int has_un_in_vertex;
    for (int i = 1; i < vertex_number; ++i) {
        for (int j = 1; j <= vertex_number; ++j)
            if (!inset[j] && matrix[next_vertex][j] != -1 &&
                    (distance[j] == -1 || distance[j] > matrix[next_vertex][j]))
                distance[j] = matrix[next_vertex][j];
        has_un_in_vertex = 0;
        min_distance = MAX_INT;
        for (int j = 1; j <= vertex_number; ++j) {
            if (!inset[j] && distance[j] != -1 && distance[j] < min_distance) {
                min_distance = distance[j];
                next_vertex = j;
                has_un_in_vertex = 1;
            }
        }
        if (!has_un_in_vertex)
            return -1;
        sum_distance += min_distance;
        /* printf("sum_distance=%d\n", sum_distance); */
        inset[next_vertex] = 1;
    }
    return sum_distance;
}

int main() {
    int n, m;
    int u, v, t;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0)
            break;
        memset(matrix, -1, sizeof(matrix));
        for (int i = 1; i <= m; ++i)
            for (int j = i; j <= m; ++j)
                matrix[i][j] = matrix[j][i] = -1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &u, &v, &t);
            if (matrix[u][v] == -1 || matrix[u][v] > t) 
                matrix[u][v] = matrix[v][u] = t;
        }
        int answer = Prim(m);
        if (answer == -1)
            printf("?\n");
        else
            printf("%d\n", answer);
    }
    return 0;
}


