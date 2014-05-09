/*************************************************************************
    > File: jobdu 1389
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 09:16:09 AM CST
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
    long long step[55];
    int n;
    step[0] = step[1] = 1;
    for (int i=2; i< 51; i++)
    {
        step[i] = 0;
        for (int j=0; j<i; j++)
        {
            //printf("step[%d] += step[j]\n", i, j);
            step[i] += step[j];
        }
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", step[n]);
    }
    return 0;
}

