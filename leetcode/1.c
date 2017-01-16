#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000


int* twoSum(int* nums, int numsSize, int target);

int main()
{
    int nums[MAX_SIZE], numsSize, target;
    int *result;
    scanf("%d", &numsSize);
    for (int i = 0; i < numsSize; i++)
        scanf("%d", nums + i);
    scanf("%d", &target);
    result = twoSum(nums, numsSize, target);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++)
        for (int j = i + 1;  j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
}

