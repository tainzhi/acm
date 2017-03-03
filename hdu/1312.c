#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 110

char matrix[MAX_SIZE][MAX_SIZE];

int move[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

int Constrain(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return 1;
    } else {
        return 0;
    }
}

void DFS(int x, int y, int n, int m, int *step) {
    matrix[y][x] = '#';
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + move[i][0];
        ny = y + move[i][1];
        if (Constrain(nx, ny, n, m) && matrix[ny][nx] == '.') {
            matrix[ny][nx] = '#';
            ++(*step);
            DFS(nx, ny, n, m, step);
        }
    }
}

int  main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        int start_x, start_y, find_start = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%s", matrix[i]);
            if (!find_start) {
                for (int j = 0;j < n; ++j) {
                    if (matrix[i][j] == '@') {
                        start_x = j;
                        start_y = i;
                        find_start = 1;
                        break;
                    }
                }
            }
        }
        int step = 1;
        DFS(start_x, start_y, n, m, &step);
        printf("%d\n", step);
    }
    return 0;
}

