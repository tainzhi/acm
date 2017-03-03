#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 110

bool matrix[MAX_SIZE][MAX_SIZE];
int distance[MAX_SIZE][MAX_SIZE];
int queue[10 * MAX_SIZE * MAX_SIZE][2];
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
    int n, temp;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                matrix[i][j] = temp;
            }
        }
        memset(distance, -1, sizeof(distance));
        int front = 0;
        int rear = 0;
        if (matrix[0][0] == 1 || matrix[n-1][n-1] == 1) {
            printf("-1\n");
            continue;
        } else if (n == 1 && matrix[0][0] == 0) {
            printf("0\n");
            continue;
        }
        if (matrix[0][0] == 0) {
            queue[++rear][0] = 0;
            queue[rear][1] = 0;
            distance[0][0] = 2;
        }
        int cx, cy, nx, ny;
        while (rear > front) {
            cx = queue[++front][0];
            cy = queue[front][1];
            matrix[cx][cy] = 1;
            for (int i = 0; i < 4; ++i) {
                nx = cx + direction[i][0];
                ny = cy + direction[i][1];
                if (Constrain(nx, ny, n) && matrix[nx][ny] == 0) {
                    distance[nx][ny] = distance[cx][cy] + 1;
                    queue[++rear][0] = nx;
                    queue[rear][1] = ny;
                }
            }
        }
        if (distance[n-1][n-1] != -1) {
            printf("%d\n", distance[n-1][n-1] - 2);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
