class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int notZeroIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[notZeroIndex++] = nums[i];
            }
        }
        while (notZeroIndex < nums.size()) {
            nums[notZeroIndex++] = 0;
        }
    }
};