#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

long long int g_ReverseCount;

void GetReverseCount(int number[], int temp_number[], int start, int end)
{
    //printf("%d %d-----\n", start, end);
    if (start == end || start > end)
        return;
    int mid = (start + end) >> 1;
    GetReverseCount(number, temp_number, start, mid);
    GetReverseCount(number, temp_number, mid+1, end);
    int p1 = mid, p2 = end, p3 = end;
    while (p3 >= start)
    {
        if (number[p1] > number[p2])
        {
            g_ReverseCount += p2 - (mid + 1) + 1;
            temp_number[p3--] = number[p1--];
        }
        else
            temp_number[p3--] = number[p2--];
        while (p1 < start && p2 >= mid+1)
                temp_number[p3--] = number[p2--];
        while (p2 < mid+1 && p1 >= start)
            temp_number[p3--] = number[p1--];
    }
    for (int i= start; i<=end; i++)
        number[i] = temp_number[i];
}

int main()
{
    int n, number[100010], temp_number[100010];
    while (scanf("%d", &n) != EOF)
    {
        g_ReverseCount = 0;
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        GetReverseCount(number, temp_number,0, n-1);
        printf("%lld\n", g_ReverseCount);
    }
    return 0;
}

