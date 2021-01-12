/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    // 买入股票, 收益为负
    // 卖出股票, 收益入袋
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int dp[prices.size()][3];
        memset(*dp, 0, sizeof(*dp));
        dp[0][0] = -prices[0];
        // dp[i][0] 持有股票的最大收益
        // dp[i][1] 不持有股票, 处于冷冻期的收益
        // dp[i][2] 不持有股票, 不处于冷冻期的收益
        for (int i = 1; i < prices.size(); i++) {
            // 持有股票, 或者从非冷冻期购买股票
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 持有股票后卖出
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 上一个阶段刚卖出去股票, 从冷静期过来dp[i-1][1]
            // 上一个阶段没有卖出股票, 从dp[i- 1][2]转移过来
            dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
        }
        // 不可能持有股票, 因为持有股票的收益是负的, 那为啥还要买股票了
        return std::max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
// @lc code=end