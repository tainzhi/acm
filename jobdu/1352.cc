#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define N 1000100

using namespace std;

int main()
{
    int n, k, number[N];
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        if (n == 1)
            printf("-1 -1\n");
        else
        {
            int begin = 0, end = n-1;
            bool flag = false;
            while (begin < end)
            {
                if (number[begin] + number[end] < k)
                    begin++;
                else if (number[begin] + number[end] > k)
                    end--;
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                printf("%d %d\n", number[begin], number[end]);
            else
                printf("-1 -1\n");
        }
    }
    return 0;
}
