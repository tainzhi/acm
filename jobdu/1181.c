#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void Merge(int nums[], int tnums[], int low, int mid, int high) {
    int i, j, k;
    /* for (i = low; i <= high; ++i) */
    /*     tnums[i] = nums[i]; */
    memcpy(tnums + low, nums + low, sizeof(int) * (high - low + 1));
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (tnums[i] < tnums[j])
            nums[k++] = tnums[i++];
        else
            nums[k++] = tnums[j++];
    }
    while (i <= mid)
        nums[k++] = tnums[i++];
    while (j <= high)
        nums[k++] = tnums[j++];
}


void MSort(int nums[], int tnums[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MSort(nums, tnums, low, mid);
        MSort(nums, tnums, mid + 1, high);
        Merge(nums, tnums, low, mid, high);
    }
}


void Sort(int nums[], int n) {
    int *tnums = (int *)malloc(sizeof(int) * n);
    MSort(nums, tnums, 0, n - 1);
    free(tnums);
}


int main()
{
    int n, i;
    int nums[1010];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", nums + i);
        Sort(nums, n);
        /* int *tnum = (int *)malloc(sizeof(int) * n); */
        /* MergeSort(nums, tnum, 0, n - 1); */
        for (i = 0; i < 1; i++)
            printf("%d", *(nums + i));
        /* free(tnum); */
        for ( ; i < n; i++)
            printf(" %d", nums[i]);
        printf("\n");
    }
}
