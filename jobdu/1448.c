// WA, I don't know why.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 501

int stack[MAX_SIZE];
int top;
int matrix[MAX_SIZE][MAX_SIZE];
int degree[MAX_SIZE];

int main() {
    int n, m, u, v;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; ++i) {
            degree[i] = 0;
            for (int j = i; j < n; ++j)
                matrix[i][j] = matrix[j][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            matrix[u][v] = 1;
            ++degree[v];
        }
        top = 0;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0)
                stack[++top] = i;
        }
        int count = 0;
        while (top > 0) {
            u = stack[top--];
            count++;
            for (int i = 0; i < n; ++i)
                if (matrix[u][i]) {
                    --degree[i];
                    if (degree[i] == 0)
                        stack[++top] = i;
                }
        }
        if (count == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


