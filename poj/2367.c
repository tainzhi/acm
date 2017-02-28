#include <stdio.h>
#include <string.h>

#define MAX_SIZE 110

int stack[MAX_SIZE];
int top;
int degree[MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];
int output[MAX_SIZE];


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(degree, 0, sizeof(degree));
        memset(matrix, 0, sizeof(matrix));
        int descent;
        for (int i = 1; i <= n; ++i){
            while (1) {
                scanf("%d", &descent);
                if (descent == 0)
                    break;
                matrix[i][descent] = 1;
                ++degree[descent];
            }
        }
        top = 0;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 0)
                stack[++top] = i;
        }
        int u, count = 0;
        while (top > 0) {
            u = stack[top--];
            output[count++] = u;
            for (int i = 1; i <= n; ++i)
                if (matrix[u][i] == 1) {
                    if (--degree[i] == 0)
                        stack[++top] = i;
                }
        }
        printf("%d", output[0]);
        for (int i = 1; i < count; i++)
            printf(" %d", output[i]);
        printf("\n");
    }
    return 0;
}


