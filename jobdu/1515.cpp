/*************************************************************************
    > File: jobdu1515
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 11:38:01 AM CST
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

int maxn[6] = {0, 9, 99, 999, 9999, 99999};

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= maxn[n]; i++)
        printf("%d\n", i);
    return 0;
}
