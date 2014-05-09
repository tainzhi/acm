/*
 * 输入n个递增的序列
 * 求存在多少个连续的子序列（长度至少为2），使的其和为指定数字
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

#define N 1000100

using namespace std;

int main()
{
    int number[N], n;
    int k;
    //long long int sum[N], k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        /*
        if (n == 1)
        {
            printf("-1 -1\n");
            continue;
        }
        */
        /*
        sum[0] = (long long int)number[0];
        for (int i=1; i<n; i++)
            sum[i] = sum[i-1] + number[i];
            */
        //printf("**********\n");
        int small=0, big=1;
        int current_sum = number[small] + number[big];
        while (big < n && small < big)
        {
            if (current_sum < k)
                current_sum += number[++big];
            else if (current_sum > k)
                current_sum -= number[small++];
            else
            {
                if (big - small + 1 >= 2)
                {
                    for (int i=small; i<= big; i++)
                        printf("%d%c", number[i], i == big ? '\n' : ' ');
                }
                current_sum -= number[small++];
            }
        }
        printf("--------------\n");
    }
    return 0;
}
