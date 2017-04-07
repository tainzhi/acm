/*******************************************************************************
* File     : 1351.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-07 13:52:10
* Modified : 2017-04-07 14:20:21
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000010

int nums[MAX_SIZE];
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        int count0, count1;
        int single0, single1;
        for (int bit = 0; bit < 32; ++bit) {
            count0 = count1 = 0;
            single0 = single1 = 0;
            int current_bit = 1<<bit;
            for (int i = 0; i < n; ++i) {
                if (nums[i]&current_bit) {
                    ++count1;
                    single1 ^= nums[i];
                } else {
                    ++count0;
                    single0 ^= nums[i];
                }
            }
            if (count1 & 1) {
                break;
            }
        }
        if (single0 > single1) {
            single0 ^= single1;
            single1 ^= single0;
            single0 ^= single1;
        }
        printf("%d %d\n", single0, single1);
    }
    return 0;
}
