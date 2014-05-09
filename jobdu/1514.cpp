/*************************************************************************
    > File: jobdu 1514
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 11:01:49 AM CST
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
#define INF 1.0e16
using namespace std;

int main()
{
    int n, exp;
    double base;
    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            scanf("%lf%d", &base, &exp);
            //printf("%lf %d\n", base, exp);
            double outcome = pow(base, (double)exp);
            if (base == 0.0 && exp < 0)
                printf("INF\n");
            else
                printf("%.2ef\n", outcome);
        }
    }
    return 0;
}
