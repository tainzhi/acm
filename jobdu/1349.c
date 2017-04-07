/*******************************************************************************
* File     : 1349.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-06 21:25:21
* Modified : 2017-04-06 22:40:38
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000010

int nums[MAX_SIZE];

int main() {
    int n, m, t;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        scanf("%d", &m);
        while (--m >= 0) {
            scanf("%d", &t);
            int low = 0, mid, high = n - 1;
            while (low < high) {
                mid = (low + high) >> 1;
                if (nums[mid] > t)
                    high = mid - 1;
                else if (nums[mid] < t)
                    low = mid + 1;
                else
                    high = mid;
            }
            int ans = 0;
            if (nums[high] == t) {
                int k = high;
                while (k < n && nums[k] == t) {
                    ++k;
                    ++ans;
                }
                k = high;
                while (k >= 0 && nums[k] == t) {
                    --k;
                    ++ans;
                }
                --ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

