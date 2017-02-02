#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100010

int nums[MAX_SIZE];

int Compare(const void *a, const void *b) {
    return *(int*)a - *(int *)b;
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), Compare);
        int j;
        /* for (int i = 0; i < n; i++) */
        /*     printf("--%d\n", nums[i]); */
        for (j=0; j < 1 && m >= 1; j++)
            printf("%d", nums[j]);
        for (j=1; j < m; j++)
            printf(" %d", nums[j]);
        printf("\n");
    }
    return 0;
}

        


