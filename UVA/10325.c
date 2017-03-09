#include <stdio.h>

typedef long long LL;

LL GCD(LL b, LL a)
{
    LL temp;
    while (b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

LL LCM(LL a, LL b)
{
    return a * b / GCD(a, b);
}

int main()
{
    LL n, m;
    LL divisor[20];
    while (scanf("%lld %lld", &n, &m) != EOF) {
        for (LL i = 0; i < m; ++i)
            scanf("%lld", &divisor[i]);
        LL sum = 0;
        LL sign = 1, great = 1;
        for (LL i = 1; i < (1 << m); ++i) {
            great = 1;
            sign = -1;
            for (LL j = 0; j < m; ++j)
                if ((1<<j) & i) {
                    great = LCM(great, divisor[j]);
                    sign *= -1;
                }
            sum += sign * (n / great);
            sign *= -1;
        }
        printf("%lld\n", n - sum);
    }
    return 0;
}
