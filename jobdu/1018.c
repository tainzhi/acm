#include <stdio.h>
#include <string.h>

char pails[110];

int main() {
    int n, score, target;
    while (scanf("%d", &n) != EOF) {
        /* printf("n=%d\n", n); */
        if (n == 0)
            break;
        for (int i = 0; i <= n; ++i)
            pails[i] = 0;
        for (int i = 0 ; i < n; ++i) {
            scanf("%d", &score);
            pails[score]++;
        }
        scanf("%d", &target);
        printf("%d\n", pails[target]);
    }
    return 0;
}
