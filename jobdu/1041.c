#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10010

int nums[MAX_SIZE];

int compare(const void *a, const void *b) {
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    if (n1 < n2)
        return -1;
    else if (n1 == n2)
        return 0;
    else
        return 1;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), compare);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == 0 || nums[j - 1] != nums[i])
                nums[j++] = nums[i];
        }
        printf("%d", nums[0]);
        for (int i = 1; i < j; i++)
            printf(" %d", nums[i]);
        printf("\n");
    }
    return 0;
}
                
