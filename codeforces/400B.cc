#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

char matrix[1010][1010];
int adj[1010][2], dif[1010];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%s", matrix[i]);
        //printf("***********\n");
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (matrix[i][j] == 'G')
                    adj[i][0] = j;
                else if (matrix[i][j] == 'S')
                    adj[i][1] = j;
            }
        }
        bool flag = true;
        int min_move = 1;
        for (int i=0; i<n; i++)
        {
            dif[i] = adj[i][1] - adj[i][0] - 1;
            if (dif[i] < 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            printf("-1\n");
        else
        {
            sort(dif, dif + n);
            for (int i=1, before = dif[0]; i<n; i++)
                if (before != dif[i])
                {
                    min_move++;
                    before = dif[i];
                }
            printf("%d\n", min_move);
        }
    }
    return 0;
}
