/*******************************************************************************
* File     : 1352.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-11 08:34:09
* Modified : 2017-04-11 08:51:06
*******************************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX_SIZE 1000010
 
int nums[MAX_SIZE];
 
int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        int i = 0, j = n - 1;
        int multi;
        while (i < j) {
            multi = nums[i] + nums[j];
            if (multi == k)
                break;
            else if (multi < k)
                ++i;
            else
                --j;
        }
        if (i < j)
            printf("%d %d\n", nums[i], nums[j]);
        else
            printf("-1 -1\n");
    }
    return 0;
}
 
