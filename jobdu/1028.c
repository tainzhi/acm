#include <stdio.h>
#include <string.h>

#define MAX_INT 1123123123
#define MAX_VERTEX_SIZ 110

int matrix[MAX_VERTEX_SIZ][MAX_VERTEX_SIZ];
int state[MAX_VERTEX_SIZ][MAX_VERTEX_SIZ];
int final[MAX_VERTEX_SIZ];
int distance[MAX_VERTEX_SIZ];

int inset[MAX_VERTEX_SIZ];
int rank[MAX_VERTEX_SIZ];

int FindSet(int x);
int Union(int x, int y);
void AddFinal(int x, int vertex_number);
int Kruskal(int vertex_number);

int main() {
    int n;
    int u, v, t, s;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        // initialize union set
        for (int i = 1; i <= n; ++i) {
            inset[i] = i;
            rank[i] = 1;
        }
        // initialize graph
        for (int i = 1; i <= n; ++i) {
            final[i] = 0;
            distance[i] = -1;
            for (int j = i; j <= n; ++j) {
                matrix[i][j] = matrix[j][i] = -1;
                state[i][j] = state[j][i] = -1;
            }
        }
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            scanf("%d %d %d %d", &u, &v, &t, &s);
            if (s == 1)
                Union(u, v);
            matrix[u][v] = matrix[v][u] = t;
            state[u][v] = state[v][u] = s;
        }
        printf("%d\n", Kruskal(n));
    }
    return 0;
}

int FindSet(int x) {
    if (x != inset[x])
        inset[x] = FindSet(inset[x]);
    return inset[x];
}

int Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
        return 1;
    else {
        if (rank[x] > rank[y])
            inset[y] = x;
        else {
            inset[x] = y;
            if (rank[x] == rank[y])
                ++rank[y];
        }
        return 0;
    }
}

void AddFinal(int x, int vertex_number) {
    for (int i = 1; i <= vertex_number; ++i) {
        if (FindSet(i) == FindSet(x))
            final[i] = 1;
    }
}

void UpdateDistance(int source, int vertex_number) {
    for (int i = 1; i <= vertex_number; ++i)
        if (!final[i] && state[source][i] == 0 &&
                (distance[i] == -1 || distance[i] > matrix[source][i]))
            distance[i] = matrix[source][i];
}

int Kruskal(int vertex_number) {
    int least_cost = 0;
    int min_distance;
    int smooth;
    int next_set;
    AddFinal(1, vertex_number);
    while (1) {
        smooth = 1;
        for (int i = 1; i <= vertex_number; ++i) {
            if (final[i]) {
                UpdateDistance(i, vertex_number);
            } else {
                smooth = 0;
            }
        }
        if (smooth)
            break;
        min_distance = MAX_INT;
        for (int i = 1; i <= vertex_number; ++i) {
            if (!final[i] && distance[i] != -1 && distance[i] < min_distance) {
                min_distance = distance[i];
                next_set = i;
            }
        }
        AddFinal(next_set, vertex_number);
        least_cost += min_distance;
    }
    return least_cost;
}




