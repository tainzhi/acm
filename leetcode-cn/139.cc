/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
// 完全背包, 涉及到顺序, 即物品按一定顺序放入背包中, 那么对物品的迭代放在内层
// 对背包的迭代放在外层, 只有这样才能让物品按照一定的顺序放入背包中
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size() + 1];
        std::fill_n(dp, s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (string word: wordDict) {
                int len = word.size();
                if (i >= len && word.compare(s.substr(i - len, len)) == 0) {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

