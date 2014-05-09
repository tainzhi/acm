/*************************************************************************
    > File: jodbu1523
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 10:07:25 AM CST
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

void caluate(int n, int &bit, int &one, int &zero)
{
    bit = 0, one = 0, zero = 0;
    bool flag = true;
    while (n)
    {
        bit++;
        if (n % 2)
        {
            flag = false;
            one++;
        }
        else
        {
            if (flag)
                zero++;
        }
        n /= 2;
    }
}

int main()
{
    int test, n, bit, one, zero;
    while (scanf("%d", &test) != EOF)
    {
        while (test--)
        {
            scanf("%d", &n);
            caluate(n, bit, one, zero);
            //printf("%d*%d*%d\n", n, bit, one);
            if(n > 0)
                printf("%d\n", one);
            else if (n == 0)
                printf("0\n");
            else
                printf("%d\n", 32 - one - zero + 1);
        }
    }
    return 0;
}
