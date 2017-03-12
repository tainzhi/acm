#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000010

int prime[MAX_SIZE];

int main() {
    int n;
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < MAX_SIZE; ++i) {
        if (!prime[i])  {
            for (int j = i; j < MAX_SIZE; j += i) {
                if (!prime[j])
                    prime[j] = j;
                prime[j] = prime[j] / i * (i - 1);
            }
        }
    }
    long long ans;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        ans = 0;
        for (int i = 2; i <= n; ++i)
            ans += prime[i];
        printf("%lld\n", ans);
    }
    return 0;
}
