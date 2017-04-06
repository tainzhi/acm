/*******************************************************************************
* File     : 1214.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-05 23:24:52
* Modified : 2017-04-06 15:29:48
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ugly[1510];

int main() {
    int index = 0, t2 = 0, t3 = 0, t5 = 0;
    int t2_current, t3_current, t5_current;
    ugly[0] = 1;
    while (index < 1500 && t2 < 1500 && t3 < 1500 && t5 < 1500) {
        t2_current = ugly[t2] * 2;
        t3_current = ugly[t3] * 3;
        t5_current = ugly[t5] * 5;
        if (t2_current <= ugly[index])
            ++t2;
        if (t3_current <= ugly[index])
            ++t3;
        if (t5_current <= ugly[index])
            ++t5;
        if (t2_current <= t3_current && t2_current <= t5_current && t2_current > ugly[index])
            ugly[++index] = t2_current;
        if (t3_current <= t2_current && t3_current <= t5_current && t3_current > ugly[index])
            ugly[++index] = t3_current;
        if (t5_current <= t2_current && t5_current <= t3_current && t5_current > ugly[index])
            ugly[++index] = t5_current;
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", ugly[n - 1]);
    }
    return 0;
}

