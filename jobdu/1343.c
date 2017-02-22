#include <stdio.h>

#define MAX_SIZE 310

int matrix[MAX_SIZE][MAX_SIZE];

int Calculate(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            sum += matrix[i][j];
    return sum;
}

int main() {
    int n, k;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &matrix[i][j]);
        scanf("%d", &k);
        int a, b, w;
        while (--k >= 0) {
            scanf("%d %d %d", &a, &b, &w);
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    if (matrix[i][j] > matrix[i][a] + w + matrix[b][j]) {
                        matrix[i][j] = matrix[i][a] + w + matrix[b][j];
                        matrix[j][i] = matrix[i][j];
                    }
                }
            printf("%d\n", Calculate(n));
        }
    }
    return 0;
}

