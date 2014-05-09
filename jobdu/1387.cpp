/*************************************************************************
    > File: jobdu 1387
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Wed 19 Feb 2014 11:45:25 PM CST
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

long long fi[72];

void initial()
{
    fi[0] = 0;
    fi[1] = 1;
    for (int i= 2; i<=70; i++)
    {
        fi[i] = fi[i -1] + fi[i - 2];
        //printf("i=%d %u-------\n", i, fi[i]);
    }
}

int main()
{
    int n;
    initial();
    //printf("sizeof(int) = %d\n", sizeof(long long));
    while(scanf("%d", &n) != EOF)
    {
        printf("%lld\n", fi[n]);
    }
    return 0;
}

