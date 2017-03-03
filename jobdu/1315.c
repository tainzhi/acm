#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 110

int matrix[MAX_SIZE][MAX_SIZE];
int distance[MAX_SIZE][MAX_SIZE];
int queue[MAX_SIZE][2];
int direction[4][2] = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}};
int Constrain(int x, int y, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n)
        return 1;
    else 
        return 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &matrix[i][j]);
        memset(distance, -1, sizeof(distance));
        int front = 0;
        int rear = 0;
        int cx, cy, nx, ny, lx, ly;
        lx = 0;
        ly = 0;
        int step = 0;
        int has = 0;
        if (matrix[0][0] == 0) {
            queue[++rear][0] = 0;
            queue[rear][1] = 0;
        }
        int current_is_last;
        while (rear > front && !has) {
            cx = queue[++front][0];
            cy = queue[front][1];
            matrix[cx][cy] = 1;
            /* printf("cx=%d cy=%d\n, front=%d rear=%d\n", cx, cy, front, rear); */
            current_is_last = 0;
            if (lx == cx && ly == cy) {
                /* printf("last_x=%d last_y=%d\n", cx, cy); */
                ++step;
                current_is_last = 1;
            }
            for (int i = 0; i < 4; ++i) {
                nx = cx + direction[i][0];
                ny = cy + direction[i][1];
                if (Constrain(nx, ny, n) && matrix[nx][ny] == 0) {
                    if (nx == n - 1 && ny == n - 1) {
                        has = 1;
                        break;
                    } else {
                        queue[++rear][0] = nx;
                        queue[rear][1] = ny;
                    }
                    if (current_is_last) {
                        lx  = nx;
                        ly = ny;
                    }
                }
            }
        }
        printf("%d\n", has ? step : -1);
    }
    return 0;
}
