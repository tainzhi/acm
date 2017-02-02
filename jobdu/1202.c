#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10010

int nums[MAX_SIZE];

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), compare);
        for (int i = 0; i < n; i++)
            printf("%d ", nums[i]);
        printf("\n");
    }
    return 0;
}
                
