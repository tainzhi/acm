#include <stdio.h>
#include <string.h>

#define MAX_SIZE 110

char matrix[MAX_SIZE][MAX_SIZE];

int direction[8][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {-1,1},
    {-1, -1},
    {1, -1},
    {1, 1}};

void DFS(int x, int y, int m, int n) {
    matrix[x][y] = '*';
    int nx, ny;
    for (int i = 0; i < 8; ++i) {
        nx = x + direction[i][0];
        ny = y + direction[i][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == '@') {
            DFS(nx, ny, m, n);
        }
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < m; ++i) {
            scanf("%s", matrix[i]);
        }
        /* printf("m=%d n=%d\n", m, n); */
        /* for (int i = 0; i < m; ++i) { */
        /*     printf("i=%d ", i); */
        /*     for (int j = 0; j < n; ++j) { */
        /*         printf("%c", matrix[i][j]); */
        /*     } */
        /*     printf("\n"); */
        /* } */
        int count = 0;
        for (int i = 0 ; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '@') {
                    ++count;
                    DFS(i, j, m, n);
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
