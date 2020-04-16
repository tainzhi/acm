#include <vector>
#include <iostream>

using namespace std;

// 插入排序
void sortColors(vector<int>& nums) {
    int j;
    for (int i = 1; i < nums.size(); i++) {
        j = i;
        while (((j -1) >= 0) && nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            --j;
        }
    }
}

void _sortColors(vector<int>& nums) {
    int p0 = 0, p2 = nums.size() - 1, cur = 0;
    while (cur <= p2) {
        if (nums[cur] == 0) {
            std::swap(nums[p0], nums[cur]);
            p0++;
            cur++;
        } else if (nums[cur] == 2) {
            std::swap(nums[p2], nums[cur]);
            p2--;
        } else {
            cur++;
        }
    }
}

int main() {
    int aa[] = {2, 0, 1, 2, 0, 1};
    vector<int> nums = vector(aa, aa + sizeof(aa)/sizeof(aa[0]));
    _sortColors(nums);
    return 0;
}