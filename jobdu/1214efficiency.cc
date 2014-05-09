#include <cstdio>
#include <cstdlib>

int main()
{
    int UglyNumber[1500];
    UglyNumber[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0, current_index = 0;
    int t2_current, t3_current, t5_current;
    while (current_index < 1500 && t2 < 1500 && t3 < 1500 && t5 < 1500)
    {
        t2_current = UglyNumber[t2] * 2, t3_current = UglyNumber[t3] * 3, t5_current = UglyNumber[t5] * 5;
        //printf("%d %d %d, current=%d\n", t2_current, t3_current, t5_current, UglyNumber[current_index]);
        if (t2_current <= UglyNumber[current_index])
            t2++;
        if (t3_current <= UglyNumber[current_index])
            t3++;
        if (t5_current <= UglyNumber[current_index])
            t5++;
        if (t2_current <= t3_current && t2_current <= t5_current && t2_current > UglyNumber[current_index])
            UglyNumber[++current_index] = t2_current;
        else if (t3_current <= t2_current && t3_current <= t5_current && t3_current > UglyNumber[current_index])
            UglyNumber[++current_index] = t3_current;
        else if (t5_current <= t2_current && t5_current <= t3_current && t5_current > UglyNumber[current_index])
            UglyNumber[++current_index] = t5_current;
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 1)
            printf("-1\n");
        else
            printf("%d\n", UglyNumber[n-1]);
    }
    return 0;
}
