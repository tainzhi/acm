/*************************************************************************
    > File: jobdu 1524
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sun 23 Feb 2014 11:21:28 AM CST
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

using namespace std;

int main()
{
    int n;
    int a[1010],b[1010];
    while (scanf("%d", &n) != EOF)
    {
        a[0] = 0;
        for (int i=1; i<=n; i++)
            scanf("%d", &a[i]);
        for (int i=1; i<=n; i++)
            scanf("%d", &b[i]);
        for (int i=1; i<=n; i++)
            printf("%d %d\n", a[i], a[b[i]]);
    }
    return 0;
}
