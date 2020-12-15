/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * dp[i] = max { dp[i - 1], dp[i - 2] + nums[i]}
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            if (i- 1 >= 0) {
                dp[i] = std::max(dp[i], dp[i - 1]);
            }
            if (i - 2 >= 0) {
                dp[i] = std::max(dp[i], dp[i - 2] + nums[i]);
            }
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end 
