#include <stdio.h>

int main() {
    int nums[10];
    while (scanf("%d", &nums[0]) != EOF) {
        for (int i = 1; i < 10; ++i)
            scanf("%d", &nums[i]);
        int max = nums[1];
        for (int i = 2; i < 10; ++i) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        printf("max=%d\n", max);
    }
    return 0;
}
