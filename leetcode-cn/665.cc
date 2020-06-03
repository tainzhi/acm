class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int maxBefore = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if ((i - 2 >= 0) && nums[i  - 2] > nums[i]) {
                    // nums[i] 太小
                    nums[i] = nums[i - 1];
                } else {
                    // nums[i - 1] 太大
                    nums[i - 1] = nums[i];
                }
                maxBefore++;
            }
        }
        return maxBefore <= 1;
    }
};