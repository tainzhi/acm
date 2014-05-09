#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int GetFirstNumber(int number[], int n, int k)
{
    int low = 0, high = n-1, mid;
    while (low <= high)
    {
        if (low == high)
        {
            if (number[low] == k)
                return low;
            else
                return -1;
        }
        mid = (low + high)>>1;
        if (number[mid] > k)
            high = mid -1;
        else if (number[mid] < k)
            low = mid + 1;
        else
        {
            if (mid-1>=low && number[mid-1] == k)
                high = mid-1;
            else
                return mid;
        }
    }
}

int GetLastNumber(int number[], int n, int k)
{
    int low = 0, high = n-1, mid;
    while (low <= high)
    {
        if (low == high)
        {
            if (number[low] == k)
                return low;
            else
                return -1;
        }
        mid = (low + high)>>1;
        if (number[mid] > k)
            high = mid-1;
        else if (number[mid] < k)
            low = mid + 1;
        else
        {
            if (mid+1 <= high && number[mid+1] == k)
                low = mid+1;
            else
                return mid;;
        }
    }
}

int main()
{
    int n, number[1000010];
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        sort(number, number+n);
        int m;
        scanf("%d", &m);
        while (m--)
        {
            int k;
            scanf("%d", &k);
            int first = GetFirstNumber(number, n, k);
            int last = GetLastNumber(number, n, k);
            //printf("first=%d last=%d\n", first, last);
            if (first < 0 && last < 0)
                printf("0\n");
            else
                printf("%d\n", last-first+1);
        }
    }
    return 0;
}

