/*************************************************************************
    > File: jobdu1384
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 18 Feb 2014 09:53:21 AM CST
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
 
int main()
{
    int m, n, t, matrix;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        scanf("%d", &t);
        bool in = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &matrix);
                // = %d matrix = %d*****\n", t, matrix);
                if (matrix == t)
                    in = true;
            }
        if (in)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
