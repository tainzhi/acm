/*******************************************************************************
* File     : 3904.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-03-29 12:35:17
* Modified : 2017-03-29 12:35:17
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10010

typedef long long int LL;

int numbers[MAX_SIZE];
int pail[MAX_SIZE];
int tag[MAX_SIZE];
int prime[MAX_SIZE], prime_size;

void GetPrime(int m) {
    int sqrt_m = sqrt(m + 0.5);
    int prime_size = 0;
    for (int i = 2; i <= sqrt_m; ++i) {
        if (m % i == 0) {
            ++pail[i];
            tag[i] = 1;
            prime[prime_size++] = i;
            while (m % i == 0)
                m /= i;
        }
    }
    if (m != 1) {
        ++pail[m];
        tag[m] = 1;
        prime[prime_size++] = m;
    }
    for (int i = 1; i < (1 << prime_size); ++i) {
        int sum = 1;
        int count = 0;
        for (int j = 0; j < prime_size; ++j) {
            if ((1<<j) & i) {
                sum *= prime[j];
                ++count;
            }
        }
        if (count > 1) {
            ++pail[sum];
            if (count & 1)
                tag[sum] = 1;
            else
                tag[sum] = 0;
        }
    }
}

LL Combination(int m) {
    return (LL)(m) * (m - 1) * (m - 2) * (m - 3) / (1 * 2 * 3 * 4);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(pail, 0, sizeof(pail));
        memset(prime, 0, sizeof(prime));
        memset(tag, -1, sizeof(tag));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &numbers[i]);
            GetPrime(numbers[i]);
        }
        prime_size = 0;
        LL ans = Combination(n);
        for (int i = 2; i < MAX_SIZE; ++i) {
            if (pail[i] >= 4) {
                if (tag[i] == 1)
                    ans -= Combination(pail[i]);
                else
                    ans += Combination(pail[i]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
