/*************************************************************************
    > File: jobdu 1386
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Wed 19 Feb 2014 10:00:09 PM CST
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
    while (scanf("%d", &n) != EOF)
    {
        int small = 10000001;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp < small)
                small = temp;
        }
        printf("%d\n", small);
    }
    return 0;
}
