#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
const ULL module = 100000007;

ULL Pow(ULL base, ULL exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    ULL temp = Pow(base, exp/2) % module;
    if (exp % 2)
        return (((temp * temp) % module) * base) % module;
    else
        return (temp * temp) % module;
}

ULL R1(ULL n2, ULL n3)
{
    ULL answer = ((n3 - (2 * n2))%module + 1 + module) % module;
    while (answer < 0)
        answer += module;
    answer %= module;
    if (answer % 2)
        return ((answer + module)/2)%module;
    else
        return answer / 2;
}

ULL R2(ULL n2, ULL n3)
{
    ULL answer = ((n2*(n2 + 3))%module - (3*n3)%module-1 + module) % module;
    while (answer < 0)
        answer += module;
    answer %= module;
    if (answer % 2)
        return ((answer + module)/2)%module;
    else
        return answer / 2;
}

int main()
{
    int T;
    scanf("%d", &T);
    ULL n;
    while (T--)
    {
        scanf("%llu", &n);
        if (n == 1)
        {
            printf("0 0\n");
            continue;
        }
        ULL n2 = Pow(2, n), n3 = Pow(3, n);
        printf("%llu %llu\n", R1(n2, n3), R2(n2, n3));
    }
    return 0;
}

