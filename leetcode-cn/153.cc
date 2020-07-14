class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid]  > nums[high]) {
                low = mid +1;
            } else {
                high = mid;
            }
        }
        return nums[high];
    }
};