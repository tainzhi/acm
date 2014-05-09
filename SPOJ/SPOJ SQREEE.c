#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAXN = 10000010;
char mobius[MAXN];
int  prime[MAXN];

void GetMoibus()
{
    int top = 0;
    mobius[1] = 1;
    for (int i=2; i<MAXN; i++)
    {
        if (prime[i] == 0)
        {
            mobius[i] = -1;
            prime[top++] = i;
        }
        for (int j=0; j<top && i * prime[j] < MAXN; j++)
        {
            prime[i*prime[j]] = 1;
            if (i % prime[j])
                mobius[i*prime[j]] = mobius[i] * mobius[prime[j]];
        }
    }
}

int main()
{
    GetMoibus();
    int test;
    scanf("%d", &test);
    while (test--)
    {
        long long n, sum = 0;
        scanf("%lld", &n);
        for (long long  i=1; i<=n/i; i++)
        {
            sum += mobius[i] * (n/(i*i));
        }
        printf("%lld\n", sum);
    }
    return 0;
}

