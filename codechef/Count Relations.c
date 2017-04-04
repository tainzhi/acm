/*******************************************************************************
* File     : Count Relations.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-04 11:28:44
* Modified : 2017-04-04 11:28:44
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
ll MOD = 100000007;

ll power(ll a, ll b) {
    ll ans = 1, mida = a;
    while (b) {
        if (b&1)
            ans = (ans * mida) % MOD;
        mida = (mida * mida) % MOD;
        b = b >> 1;
    }
    return ans;
}

int main() {
    ll t, n;
    scanf("%lld", &t);
    while (--t >= 0) {
        scanf("%lld", &n);
        /* ll ans1 = ((power(3, n) - 2 * power(2, n) + 1) / 2 + MOD) % MOD; */
        /* ll ans2 = ((power(4, n) - 3 * power(3, n) + 3 * power(2, n) - 1) / 2 + MOD) % MOD; */
        ll inv2 = power(2, MOD - 2);
        ll ans1 = (power(3, n) + MOD - power(2, n + 1) + 1) % MOD * inv2 % MOD;
        ll ans2 = (power(4, n) + MOD - power(3, n + 1) + (3 * power(2, n) % MOD) - 1) % MOD * inv2 % MOD;
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
        
