/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int dp[s.size() + 1];
        memset(dp, 0 , sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i<=s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2') {
                    dp[i] = dp[i - 2];
                } else {
                    break;
                }
            } else {
                if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

