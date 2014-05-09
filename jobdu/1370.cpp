/*************************************************************************
    > File: jobdu 1370  
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Wed 26 Feb 2014 09:07:35 AM CST
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
    int array[100010];
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &array[i]);
        int num = -1, count = 0;
        for (int i=0; i<n; i++)
        {
            if (num != array[i])
            {
                if (count == 0)
                    count = 1, num = array[i];
                else
                    count--;
            }
            else
                count++;
        }
        int half = 0;
        for (int i=0; i<n; i++)
            if (num == array[i])
                half++;
        if (half*2 <= n)
            printf("-1\n");
        else
            printf("%d\n", num);
    }
    return 0;
}
                
