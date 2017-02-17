#include <stdio.h>
#include <math.h>

int main() {
    int n, nodes[1010];
    char empty[] = "EMPTY";
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nodes[i]);
        int depth;
        scanf("%d", &depth);
        int begin = pow(2, depth - 1) - 1;
        int end = pow(2, depth) - 2;
        if (begin > n - 1)
            printf("%s\n", empty);
        else {
            printf("%d", nodes[begin++]);
            if (end > n - 1)
                end = n - 1;
            for (;begin <= end; ++begin)
                printf(" %d", nodes[begin]);
            printf("\n");
        }
    }
    return 0;
}
