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
        for (int n: nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        bool dp[sum + 1];
        std::fill_n(dp, sum + 1, false);
        dp[0] = true;
        for (int n: nums) {
            for (int j = sum; j >=n; j--) {
                dp[j] = dp[j] || dp[ j - n];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

