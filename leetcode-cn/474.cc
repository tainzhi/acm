/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.size() == 0) return 0;
        int dp[m + 1][ n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (string str: strs) {
            int zeros = 0, ones = 0;
            for (char c: str) {
                if (c == '1') ones++;
                else zeros++;
            }
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

