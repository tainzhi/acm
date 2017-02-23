#include <stdio.h>
#define MAX_SIZE 1010

int rank[MAX_SIZE], set[MAX_SIZE], tag[MAX_SIZE];

int FindSet(int x) {
    if (x != set[x])
        set[x] = FindSet(set[x]);
    return set[x];
}

int Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
        return 1;
    else {
        if (rank[x] > rank[y])
            set[y] = x;
        else {
            set[x] = y;
            if (rank[x] == rank[y])
                ++rank[y];
        }
    }
    return 0;
}

int main() {
    int n, m, u, v;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        scanf("%d", &m);
        for (int i = 1; i <= n; ++i) {
            set[i] = i;
            rank[i] = 1;
            tag[i] = 0;
        }
        while (--m >= 0) {
            scanf("%d %d", &u, &v);
            if (u <= n && v <= n)
                Union(u, v);
        }
        for (int i = 1; i <= n; i++) {
            tag[FindSet(i)] = 1;
        }
        int path = 0;
        for (int i = 1; i <= n; i++)
            if (tag[i])
                path++;
        printf("%d\n", path - 1);
    }
    return 0;
}


