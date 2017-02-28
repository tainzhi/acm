#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARC_SIZE 10010
#define MAX_VERTEX_SIZ 1010

typedef struct ArcNode {
    int u, v;
    int length;
}Arc;

Arc arc_lists[MAX_ARC_SIZE];
int inset[MAX_VERTEX_SIZ], rank[MAX_VERTEX_SIZ];

int Compare(const void *a , const void *b) {
    Arc *arc1, *arc2;
    arc1 = (Arc *)a;
    arc2 = (Arc *)b;
    if (arc1->length < arc2->length)
        return -1;
    else if (arc1->length > arc2->length)
        return 1;
    else
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

int main() {
    int n, m;
    int u, v, t;
    int cost = 0, count;
    while (scanf("%d %d", &n, &m) != EOF) {
        //initialize union set
        for (int i = 1; i <= n; ++i) {
            inset[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &t);
            arc_lists[i].u = u;
            arc_lists[i].v = v;
            arc_lists[i].length = t;
        }
        qsort(arc_lists, m, sizeof(Arc), Compare);
        cost = 0;
        count = 0;
        for (int i = 0; i < m; ++i) {
            if (!Union(arc_lists[i].u, arc_lists[i].v)) {
                ++count;
                cost += arc_lists[i].length;
            }
            if (count == n - 1) {
                break;
            }
        }
        if (count == n - 1) {
            printf("%d\n", cost);
        } else {
            printf("no\n");
        }
    }
}


