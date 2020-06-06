class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            // 对偶数index进行索引
            if (mid % 2 == 1) --mid;
            // 前面的都是偶数个数字
            if (nums[mid] == nums[mid +1]) {
                low = mid + 2;
            } else {
            // 后面的都是偶数个
                high = mid;
            }
        }
        return nums[low];
    }
};