/*******************************************************************************
* File     : 2773.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-03-25 12:08:40
* Modified : 2017-03-25 12:08:40
* Description: 容斥原理+二分法
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRIME_SIZE 100001

int prime[MAX_PRIME_SIZE];
int prime_number;
int comb[MAX_PRIME_SIZE];
bool comb_tag[MAX_PRIME_SIZE]; // true: odd
int comb_number;

void GetPrime(int m) {
    int sqrt_m = sqrt(m + 0.5);
    prime_number = 0;
    for (int i = 2; i <= sqrt_m; ++i) {
        if (m % i == 0) {
            prime[prime_number++] = i;
            while (m % i == 0)
                m = m / i;
        }
    }
    if (m != 1)
        prime[prime_number++] = m;
}

void GetComb() {
    comb_number = 0;
    for (int i = 1; i < (1<<prime_number); ++i) {
        int sum = 1, odd_count = 0;
        for (int j = 0; j < prime_number; ++j) {
            if (i & (1<<j)) {
                sum *= prime[j];
                ++odd_count;
            }
        }
        comb[comb_number] = sum;
        comb_tag[comb_number++] = ((odd_count & 1) == 1) ? true : false;
    }
}

long long Calc(long long m) {
    long long leave = m;
    for (int i = 0; i < comb_number; ++i) {
        if (comb_tag[i]) {
            leave -= m / comb[i];
        } else {
            leave += m / comb[i];
        }
    }
    return leave;
}


int main() {
    int m, k;
    while (scanf("%d %d", &m, &k) != EOF) {
        GetPrime(m);
        GetComb();
        long long unsigned int low = 1, high = 1 << 30, mid;
        high = high * high;
        while (low < high) {
            mid = (low + high) >> 1;
            long long  t_k = Calc(mid);
            if (t_k > k)
                high = mid - 1;
            else if (t_k < k)
                low = mid + 1;
            else
                high = mid;
        }
        printf("%lld\n", high);
    }
    return 0;
}



