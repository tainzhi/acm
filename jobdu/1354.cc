#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

int main()
{
    int s;
    while (scanf("%d", &s) != EOF)
    {
        if (s < 0)
            break;
        int small=1, end=2, current = 3;
        bool flag = false;
        while (end < s)
        {
            if (current > s)
            {
                current -= small;
                small++;
            }
            else if (current < s)
            {
                end++;
                current+= end;
            }
            else
            {
                if (small < end)
                {
                    flag = true;
                    for (int i=small; i<=end; i++)
                        printf("%d%c", i,i==end?'\n':' ');
                }
                current-=small;
                small++;
            }
        }
        if (flag == false)
            printf("Pity!\n");
        printf("#\n");
    }
    return 0;
}
