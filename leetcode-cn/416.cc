/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        int dp[sum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int num: nums) {
            for (int i = sum; i >= num; i--) {
                dp[i] |= dp[i - num];
            }
        }
        return dp[sum] == 1;
    }
};
// @lc code=end

