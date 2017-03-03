#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 15
#define MAX_INT 10000

int matrix[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int s_x, s_y, t_x, t_y;
int w, h;
int final_step;
int direction[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}};

void DFS(int x, int y, int power, int time) {
    /* printf("DFS x = %d y = %d power = %d time = %d\n", x, y, power, time); */
    if (power == 0 || time > final_step)
        return;
    if (matrix[x][y] == -1)
        return;
    /* printf("1DFS x = %d y = %d power = %d time = %d\n", x, y, power, time); */
    if (x == t_x && y == t_y) { // destination
        if (final_step > time) {
            final_step = time;
        }
        /* printf("2DFS x = %d y = %d power = %d time = %d\n", x, y, power, time); */
    } else if (matrix[x][y] == 3 || matrix[x][y] == 0 || matrix[x][y] == 1) {
        if (matrix[x][y] == 3) power = 8;
        if (matrix[x][y] == 0) power -= 1;
        time = time + 1;
        /* printf("->DFS x = %d y = %d power = %d time = %d\n", x, y, power, time); */
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + direction[i][0];
            ny = y + direction[i][1];
            if (x >= 0 && x < h && y >= 0 && y < w) {
                if (visit[nx][ny] < power) {
                    visit[nx][ny] = power;
                    DFS(nx, ny, power, time);
                }
            }
        }
    }
}

int main() {
    while (scanf("%d %d", &w, &h) != EOF) {
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf("%d", &matrix[i][j]);

                if (matrix[i][j] == 1) {
                    s_x = i;
                    s_y = j;
                } else if (matrix[i][j] == 2) {
                    t_x = i;
                    t_y = j;
                }
            }
        }
        final_step = MAX_INT;
        memset(visit, 0, sizeof(visit));
        visit[s_x][s_y] = 8;
        DFS(s_x, s_y, 8, 0);
        if (final_step == MAX_INT) {
            printf("Pity oz!\n");
        } else {
            printf("%d\n", final_step);
        }
    }
    return 0;
}

