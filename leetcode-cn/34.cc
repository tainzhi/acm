class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1, mid;
        vector<int> result = {-1, -1};
        int first = searchLeft(nums, target);
        if (first == -1) {
            return result;
        } else {
            result[0] = first;
            result[1] = searchRight(nums, first, high, target);
        }
        return result;
    }

    int searchLeft(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
            if (low > high && nums[high] != target) {
                return -1;
            }
        }
        return high;
    }

    int searchRight(vector<int>& nums, int target, int low, int high) {
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] <= target){
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};