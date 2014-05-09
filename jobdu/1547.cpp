/*************************************************************************
    > File: jodbu 1547
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Mon 24 Feb 2014 08:15:07 AM CST
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

#define INF 1000000007

using namespace std;

int main()
{
    int n;
    int f[1010];
    memset(f, 0, 1010 * sizeof(int));
    f[0] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        f[i] = 0;
        for (int j=0; j<i; j += 2)
            f[i] = (f[i] + f[j]) % INF;
    }

    while (scanf("%d", &n) != EOF)
        printf("%d\n", f[n]);
    return 0;

}
