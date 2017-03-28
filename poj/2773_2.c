/*******************************************************************************
* File     : 2773_2.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-03-27 19:08:28
* Modified : 2017-03-27 19:08:28
* Description: 欧拉函数
* Result: Wrong Answer
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000010

bool prime[1000010];
int prime_sum;

void GetPrime(int m) {
    prime_sum = m;
    int n = m;
    for (int i = 1; i <= m; ++i)
        prime[i] = true;
    int sqrt_m = sqrt(m + 0.5);
    for (int i = 2; i <= sqrt_m; ++i) {
        if (m % i == 0) {
            prime_sum = prime_sum / i * (i - 1);
            for (int j = i; j <= m; j += i)
                prime[j] = false;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1) {
        prime_sum = prime_sum / n * (n - 1);
        for (int j = n; j <= m; j += n)
            prime[j] = false;
    }
}

int main() {
    int m, k;
    while (scanf("%d %d", &m, &k) != EOF) {
        GetPrime(m);
        int times = k / prime_sum, leave;
        if (k % m == 0)
            --times;
        leave = k - times * prime_sum;
        int index = 0, last_prime;
        for (int i = 1; i <= m; ++i) {
            if (prime[i]) {
                ++index;
            }
            if (index == leave) {
                last_prime = i;
                break;
            }
        }
        printf("%lld\n", (long long)(times * m + last_prime));
    }
    return 0;
}



