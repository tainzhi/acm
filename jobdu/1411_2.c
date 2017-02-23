#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 510
#define MAX_INT 1231231231

int matrix[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE];
int min_distance;

void DFS(int s, int target, int nodes, int current_distance) {
    visit[s] = 1;
    int temp_sum;
    for (int j = 1; j <= nodes; ++j)
        if (matrix[s][j] != 0) {
            temp_sum = current_distance + matrix[s][j];
            if (temp_sum > min_distance)
                break;
            if (j == target && min_distance > temp_sum) {
                min_distance = temp_sum;
            } else 
                DFS(j, temp_sum, target, nodes);
        }
   visit[s] = 0;
}

int main() {
    int n, m, s;
    int u, v, t;
    while (scanf("%d %d %d", &n, &m, &s) != EOF) {
        for (int i = 1; i <= n; ++i) {
            visit[i] = 0;
            for (int j = i; j <= n; ++j)
                matrix[i][j] = matrix[j][i] = 0;
        }
        while (--m >= 0) {
            scanf("%d %d %d", &u, &v, &t);
            if (matrix[u][v] == 0 || (matrix[u][v] != 0 && matrix[u][v] > t))
                matrix[u][v] = t;
        }
        min_distance = MAX_INT;
        DFS(s, s, n, 0);
        if (min_distance == MAX_INT)
            printf("help!\n");
        else
            printf("%d\n", min_distance);
    }
    return 0;
}



