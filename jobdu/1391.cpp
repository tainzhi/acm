/*************************************************************************
    > File: jobdu 1391
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sat 22 Feb 2014 12:14:52 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>

#define N 1010
using namespace std;

bool isIn(int im, int m, int in, int n)
{
    if ((im >= 0 && im < m) && (in >= 0 && in < n))
        return true;
    else
        return false;
}

int main()
{
    int direct[4][2] = {{0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    int visit[N][N], matrix[N][N];
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                scanf("%d", &matrix[i][j]);
        memset(visit, 0, sizeof(int) * N * N);
        int id = 0, im = 0, in = 0;
        int ic = m * n;
        while (1)
        {
            if (!visit[im][in])
            {
                visit[im][in] = 1;
                ic--;
                printf("%d ", matrix[im][in]);
            }
            if (ic== 0)
                break;
            int mnext = im + direct[id][0], nnext = in + direct[id][1];
            //printf("im=%d in=%d\n", im, in);
            if (isIn(mnext, m, nnext, n))
            {
                if (!visit[mnext][nnext])
                    im = mnext, in = nnext;
                else
                    id = (id + 1) % 4;
            }
            else
                id = (id + 1) % 4;
        }
        printf("\n");
    }
    return 0;
}
