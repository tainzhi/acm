/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 * 转化为求最长公共字串
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j- 1] + 1;
                }else {
                    dp[i][j] = std::max(dp[i][j- 1], dp[i - 1][j]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};
// @lc code=end

