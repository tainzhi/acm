#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1001

int set[MAX_SIZE], rank[MAX_SIZE];

bool Judge(int n, int degree[]);

int Find(int x) {
    if (x != set[x]) {
        set[x] = Find(set[x]);
    }
    return set[x];
}

bool Union(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py)
        return true;
    else {
        if (rank[x] > rank[y]) {
            set[y] = set[x];
        } else if (rank[x] < rank[y]) {
            set[x] = set[y];
        } else {
            ++rank[x];
            set[y] = set[x];
        }
                
    }
    return false;
}

int main() {
    int m, n, u, v;
    int degree[MAX_SIZE];
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        scanf("%d", &m);
        memset(degree, 0, sizeof(int) * (n + 1));
        memset(rank, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; ++i)
            set[i] = i;
        while (--m >= 0) {
            scanf("%d %d", &u, &v);
            Union(u, v);
            ++degree[u];
            ++degree[v];
        }
        printf("%d\n", Judge(n, degree) ? 1 : 0);
    }
    return 0;
}

bool Judge(int n, int degree[]) {
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0 || set[i] != set[1])
            return false;
    }
    return true;
}




