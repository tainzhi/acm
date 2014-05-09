#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, card[20];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i=0; i<n; i++)
            scanf("%d", &card[i]);
        sort(card, card+n);
        int zero_count = 0;
        for (int i=0; i<n; i++)
        {
            if (card[i] != 0)
                break;
            zero_count++;
        }
        int no_zero_start = zero_count;
        bool flag = true;
        while ((no_zero_start+1) < n)
        {
            int gap = card[no_zero_start+1] - card[no_zero_start];
            if (gap == 0)
            {
                flag = false;
                break;
            }
            if (gap > 1)
                zero_count -= (gap-1);
            if (zero_count < 0)
            {
                flag = false;
                break;
            }
            no_zero_start++;
        }
        if (flag)
            printf("So Lucky!\n");
        else
            printf("Oh My God!\n");
    }
    return 0;
}
