#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 110

bool matrix[MAX_SIZE][MAX_SIZE];
int direction[4][2] = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}};
typedef struct StructStep {
    char x, y;
    short int step;
}Step;
Step myque[MAX_SIZE * MAX_SIZE];

int Constrain(Step s ,int n) {
    int x = s.x, y = s.y;
    if (x >= 0 && x < n && y >= 0 && y < n)
        return 1;
    else 
        return 0;
}

int BFS(int n) {
    Step c_step, n_step;
    c_step.x = 0;
    c_step.y = 0;
    c_step.step = 0;
    int front = 0;
    int rear = 0;
    int MOD = MAX_SIZE * MAX_SIZE - 1;
    myque[++rear] = c_step;
    while (front < rear) {
        c_step = myque[((++front) + MOD)% MOD];
        matrix[(int)c_step.x][(int)c_step.y] = 1;
        for (int i = 0; i < 4; ++i) {
            n_step.x = c_step.x + direction[i][0];
            n_step.y = c_step.y + direction[i][1];
            n_step.step = c_step.step + 1;
            if (Constrain(n_step, n) && matrix[(int)n_step.x][(int)n_step.y] == 0) {
                myque[((++rear) + MOD) % MOD] = n_step;
                if (n_step.x == (n - 1) && n_step.y == (n - 1)) {
                    return n_step.step;
                }
            }
        }
    }
    return -1;
}



int main() {
    int n, temp;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                matrix[i][j] = temp;
            }
        int answer;
        if (matrix[0][0] == 1 || matrix[n-1][n-1] == 1) {
            answer = -1;
        } else if (n == 1 && matrix[0][0] == 0) {
            answer = 0;
        } else {
            answer = BFS(n);
        }
        printf("%d\n", answer);
    }
    return 0;
}
