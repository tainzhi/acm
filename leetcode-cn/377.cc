/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
// 完全背包, 涉及到顺序, 背包在外层
    int combinationSum4(vector<int>& nums, int target) {
        int n = target + 1;
        unsigned int dp[n];
        std::fill_n(dp, n, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num: nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

