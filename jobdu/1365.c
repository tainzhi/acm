#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 110

int visit[MAX_SIZE][MAX_SIZE];
int distance[MAX_SIZE][MAX_SIZE];
int queue[MAX_SIZE * MAX_SIZE][2];
int move[8][2] = {
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2}};

int Constrain(int x, int y, int n) {
    if (x >= 1 && x <= n && y >= 1 && y <= n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    int start_x, start_y, end_x, end_y;
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        int front = 0;
        int rear = 0;
        /* memset(visit, 0, sizeof(visit)); */
        memset(distance, -1, sizeof(distance));
        distance[start_x][start_y] = 0;
        queue[++rear][0] = start_x;
        queue[rear][1] = start_y;
        int has = 0;
        int cx, cy, nx, ny;
        while (rear > front && !has) {
            cx = queue[++front][0];
            cy = queue[front][1];
            /* printf("nx=%d ny = %d\n", cx, cy); */
            /* visit[cx][cy] = 1; */
            for (int i = 0; i < 8; ++i) {
                nx = cx + move[i][0];
                ny = cy + move[i][1];
                if (Constrain(nx, ny, n)) {
                    distance[nx][ny] = distance[cx][cy] + 1;
                    queue[++rear][0] = nx;
                    queue[rear][1] = ny;
                    if (nx == end_x && ny == end_y) {
                        has = 1;
                    }
                }
            }
        }
        printf("%d\n", has ? distance[end_x][end_y] : -1);
    }
    return 0;
}

