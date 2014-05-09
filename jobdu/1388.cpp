/*************************************************************************
    > File: jobdu 1388
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 08:19:55 AM CST
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
    long long step[72];
    int n;
    step[0] = step[1] = 1;
    for (int i=2; i<=70; i++)
        step[i] = step[i-1] + step[i-2];
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", step[n]);
    return 0;
}
