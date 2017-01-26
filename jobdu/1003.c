#include <stdio.h>
#include <string.h>

int Convert(char *nums) {
    int len = strlen(nums);
    int result = 0, bit = 1;
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (nums[i] != ',' && nums[i] != '-') {
            result += bit * (nums[i] - '0');
            bit *= 10;
            //printf("result = %d bit=%d\n", result, bit);
        }
    }
    if (nums[0] == '-')
        result *= -1;
    //printf("result = %d\n", result);
    return result;
}

int main()
{
    char nums1[12], nums2[12];
    while (scanf("%s %s", nums1, nums2) != EOF)
    {
        printf("%d\n", Convert(nums1) + Convert(nums2));
    }
    return 0;
}

