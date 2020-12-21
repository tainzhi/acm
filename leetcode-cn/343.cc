/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 * 注意: dp[n + 1], fill_n(dp, n + 1, 0)
 * dp[i - j] * j 和 (i - j) * j这两种情况
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        std::fill_n(dp, n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <=n; i++) {
            for (int j = 1; j < i; j++ ) {
                dp[i] = std::max(dp[i], std::max(dp[ i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

