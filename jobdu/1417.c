#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARC_SIZE 10010
#define MAX_VERTEX_SIZE 110
#define MAX_BASE_NAME_SIZE 110

typedef struct ArcNode {
    char base1[MAX_BASE_NAME_SIZE];
    char base2[MAX_BASE_NAME_SIZE];
    int base1Id;
    int base2Id;
    int distance;
}Arc;

int rank[MAX_VERTEX_SIZE], inset[MAX_VERTEX_SIZE];
char bases[MAX_ARC_SIZE][MAX_BASE_NAME_SIZE];
Arc arc_lists[MAX_ARC_SIZE];

int CompareString(const void *a, const void *b) {
    char * s1 = (char *)a;
    char * s2 = (char *)b;
    return strcmp(s1, s2);
}

int CompareArc(const void *a, const void *b) {
    Arc *arc1 = (Arc *)a;
    Arc *arc2 = (Arc *)b;
    if (arc1->distance < arc2->distance)
        return -1;
    else if (arc1->distance > arc2->distance)
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
    if ((x = FindSet(x)) == (y = FindSet(y)))
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

int Insert(char *target , char (*str)[MAX_BASE_NAME_SIZE], int n) {
    int exist = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(target, str[i]) == 0) {
            exist = i;
            break;
        }
    }
    if (exist == 0) {
        strcpy(str[n], target);
        n++;
        return n;
    } else {
        return exist;
    }
}

int main() {
    int n, m;
    int count, min_rail;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            inset[i] = i;
            rank[i] = 1;
        }
        int _index = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%s %s %d", arc_lists[i].base1, arc_lists[i].base2, &arc_lists[i].distance);

        }
        qsort(arc_lists, m, sizeof(Arc), CompareArc);
        qsort(bases, 2 * m, MAX_BASE_NAME_SIZE * sizeof(char), CompareString);
        DeleteDuplicate(bases, 2 * m);
        count = 0;
        min_rail = -1;
        for (int i = 0; i < m; ++i) {
            if (!Union(FindIndex(arc_lists[i].base1, bases, n),
                        FindIndex(arc_lists[i].base2, bases, n))) {
                ++count;
            }
            if (count == n - 1) {
                min_rail = arc_lists[i].distance;
                break;
            }
        }
        if (count == n - 1)
            printf("%d\n", min_rail);
        else
            printf("My God\n");
    }
    return 0;
}

