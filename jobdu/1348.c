/*******************************************************************************
* File     : 1348.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-06 19:00:25
* Modified : 2017-04-06 21:01:47
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100010

int nums[MAX_SIZE], tnums[MAX_SIZE];
long long count;


void Merge(int low, int mid, int high) {
    int i, j, k;
    int larger;
    memcpy(tnums + low, nums + low, sizeof(int) * (high - low + 1));
    larger = mid - low + 1;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (tnums[i] <= tnums[j]) {
            nums[k++] = tnums[i++];
            --larger;
        } else {
            nums[k++] = tnums[j++];
            /* count += (mid - i + 1); */
            count += larger;
        }
    }
    while (i <= mid)
        nums[k++] = tnums[i++];
    while (j <= high)
        nums[k++] = tnums[j++];
}

void MergeSort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) >> 1;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        count = 0;
        MergeSort(0, n - 1);
        /* for (int i = 0; i < n; ++i) */
        /*     printf("%d ", nums[i]); */
        /* printf("\n"); */
        printf("%lld\n", count);
    }
    return 0;
}
