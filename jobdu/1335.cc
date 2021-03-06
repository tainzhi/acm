#include <cstdio>
#include <cstring>
#include <stdbool.h>
#include <iostream>
#include <algorithm>
#include <queue>

#define  C_MAX_SIZE  110;

using namespace std;


typedef struct StructStep {
    char x, y;
    short int step;
}Step;

int direction[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1,0}};

bool matrix[110][110];
bool visit[110][110];

queue<Step> myque;

int Constrain(Step s, int n) {
    int x = s.x, y = s.y;
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return 1;
    } else {
        return 0;
    }
}

int BFS(int n) {
    while (!myque.empty()) myque.pop();
    // printf("BFS\n");
    Step c_step, n_step;
    c_step.x = 0;
    c_step.y = 0;
    c_step.step = 0;
    visit[0][0] = 1;
    myque.push(c_step);
    while (!myque.empty()) {
        c_step = myque.front();
        myque.pop();
        if (c_step.x == (n - 1) && c_step.y == (n - 1))
            return c_step.step;
        for (int i = 0; i < 4; ++i) {
            n_step.x = c_step.x + direction[i][0];
            n_step.y = c_step.y + direction[i][1];
            n_step.step = c_step.step + 1;
            if (Constrain(n_step, n) && matrix[(int)n_step.x][(int)n_step.y] == 0
                    &&visit[(int)n_step.x][(int)n_step.y] == 0) {
                // printf("matrix[%d][%d]=%d\n", n_step.x, n_step.y, matrix[(int)n_step.x][(int)n_step.y]);
                visit[(int)n_step.x][(int)n_step.y] = 1;
                myque.push(n_step);
            }
        }
    }
    return -1;
}


int main() {
    int n, temp;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                if (temp == 0) {
                    matrix[i][j] = 0;
                } else {
                    matrix[i][j] = 1;
                }
            }
        }
        memset(visit, 0, sizeof(visit));
        // printf("n=%d\n", n);
        int result;
        if (matrix[0][0] == 1 || matrix[0][0] == 1) {
            result = -1;
         } else if (n == 1 && matrix[0][0] == 0) {
             result = 0;
         } else {
             result = BFS(n);
         }
        printf("%d\n", result);
    }
    return 0;
}
