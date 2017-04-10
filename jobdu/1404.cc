/*******************************************************************************
* File     : 1404.cc
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-10 16:48:00
* Modified : 2017-04-10 17:25:33
*******************************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
 
#define MAX_SIZE 20
 
using namespace std;
 
int visit[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];
int s_x, s_y, t_x, t_y;
int w, h;
int final_step;
int direction[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}};
typedef struct StructNode {
    int x, y;
    int power;
    int step;
}Node;
queue<Node> myque;
 
int BFS() {
    while (!myque.empty())
        myque.pop();
    Node node, n_node;
    node.x = s_x;
    node.y = s_y;
    node.power = 8;
    node.step = 0;
    visit[node.x][node.y][node.power] = 1;
    myque.push(node);
    while (!myque.empty()) {
        node = myque.front();
        myque.pop();
        if (node.x == t_x && node.y == t_y) {
            return node.step;
        }
        for (int i = 0; i < 4; ++i) {
            n_node.x = node.x + direction[i][0];
            n_node.y = node.y + direction[i][1];
            if (n_node.x < 0 || n_node.x >= h || n_node.y < 0 || n_node.y >= w || matrix[n_node.x][n_node.y] == -1)
                continue;
            n_node.step = node.step + 1;
            n_node.power = node.power - 1;
            if (n_node.power <= 0)
                continue;
            if (matrix[n_node.x][n_node.y] == 3)
                n_node.power = 8;
            if (visit[n_node.x][n_node.y][n_node.power] == 1)
                continue;
            myque.push(n_node);
            visit[n_node.x][n_node.y][n_node.power] = 1;
        }
    }
    return -1;
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
        memset(visit, 0, sizeof(visit));
        int ans = BFS();
        if (ans == -1) {
            printf("Pity oz!\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
