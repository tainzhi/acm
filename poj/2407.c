/*******************************************************************************
* File     : 2407.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-03-23 19:44:34
* Modified : 2017-03-23 19:44:34
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, eula;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        if (n == 1)
            eula = 0;
        int sqrt_n = sqrt(n + 0.5);
        eula = n;
        for (int i = 2; i < sqrt_n; ++i) {
            if (n % i == 0) {
                eula = eula / i * (i - 1);
                while (n % i == 0)
                    n = n / i;
            }
        }
        if (n > 1)
            eula = eula / n * (n - 1);
        printf("%d\n", eula);
    }
    return 0;
}
