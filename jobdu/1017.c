#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 110

typedef struct ArcNode {
    int in;
    int out;
    int distance;
}Arc;
Arc graph[MAX_SIZE * MAX_SIZE / 2];

int set[MAX_SIZE];
int rank[MAX_SIZE];

int FindSet(int x) {
    if (x != set[x])
        set[x] = FindSet(set[x]);
    return set[x];
}

bool Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
        return true;
    else {
        if (rank[x] > rank[y])
            set[y] = x;
        else {
            set[x] = y;
            if (rank[x] == rank[y])
                ++rank[y];
        }
        return false;
    }
}

int Compare(const void *a, const void *b) {
    Arc * s1 = (Arc *)a;
    Arc * s2 = (Arc *)b;
    return s1->distance - s2->distance;
}

int main() {
    int n, u, v, t;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        for (int k = 0; k < n * (n - 1) / 2; ++k) {
            scanf("%d %d %d", &u, &v, &t);
            graph[k].in = u;
            graph[k].out= v;
            graph[k].distance = t;
        }
        for (int i = 1; i <= n; ++i) {
            set[i] = i;
            rank[i] = 1;
        }
        qsort(graph, n * (n - 1) / 2, sizeof(Arc), Compare);
        int sum = 0, count = 0;
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            if (!Union(graph[i].in, graph[i].out)) {
                ++count;
                sum += graph[i].distance;
                /* printf("%d->%d %d\n", graph[i].in, graph[i].out, graph[i].distance); */
            }
            if (count >= (n - 1))
                break;
        }
        printf("%d\n", sum);
        /* printf("\n\n\n\n"); */
    }
    return 0;
}






