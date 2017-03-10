#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 510
#define MODULE 1000007

int combination[MAX_SIZE][MAX_SIZE];

int main() {
    memset(combination, 0, sizeof(combination));
    for (int i = 0; i < MAX_SIZE; ++i)
        combination[i][0] = 1;
    for (int i = 1; i < MAX_SIZE; ++i)
        for (int j = 1; j <= i; ++j)
            combination[i][j] = (combination[i - 1][j] + combination[i - 1][j - 1] + MODULE) % MODULE;
    for (int i = 1; i <= 5; ++i) {
        printf("%d :", i);
        for (int j = 0; j <= i; ++j)
            printf(" %3d ", combination[i][j]);
        printf(";");
        for (int j = i + 1; j <= 10; ++j)
            printf(" %3d ", combination[i][j]);
        printf("\n");
    }
    int ncase, n, m, k;
    scanf("%d", &ncase);
    for (int i = 1 ; i <= ncase; ++i) {
        scanf("%d %d %d", &n, &m, &k);
        int ans = 0, sign = -1, r = n, c = m;
        for (int j = 1; j < (1 << 4); ++j) {
            r = n;
            c = m;
            sign = -1;
            if ((1<<0) & j) {
                sign *= -1;
                --r;
            }
            if ((1<<1) & j) {
                sign *= -1;
                --c;
            }
            if ((1<<2) & j) {
                sign *= -1;
                --r;
            }
            if ((1<<3) & j) {
                sign *= -1;
                --c;
            }
            /* printf("sign=%d\n", sign); */
            ans = (ans + sign * combination[r * c][k] + MODULE) % MODULE;
        }
        /* printf("all=%d,before ans=%d\n" ,combination[n][m], ans); */
        ans = (combination[n * m][k] - ans + MODULE) % MODULE;
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}


