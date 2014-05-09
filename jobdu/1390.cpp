/*************************************************************************
    > File: 1390
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 09:36:06 AM CST
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
    long long mat[72];
    int n;
    mat[0] = mat[1] = 1;
    for (int i=2; i<=70; i++)
        mat[i] = mat[i-1] + mat[i-2];
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", mat[n]);
    }
    return 0;
}
