/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths1(int m, int n) {
        int dp[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        int dp[n];
        std::fill_n(dp, n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // dp[j] 从上边走下来
                // dp[j - 1] 从左边走过来
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

