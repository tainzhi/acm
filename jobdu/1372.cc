#include <cstdio>
#include <cstring>

int main()
{
    int n, number[100010];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        int max_sum = -1010,max_begin, max_end;
        int current_sum =0, current_begin = 0;
        for (int i=0; i<n; i++)
        {
            if (current_sum <= 0)
            {
                current_sum = number[i];
                current_begin = i;
            }
            else
            {
                current_sum += number[i];
            }
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
                max_begin = current_begin;
                max_end = i;
            }
        }
        printf("%d %d %d\n", max_sum, max_begin, max_end);
    }
    return 0;
}
