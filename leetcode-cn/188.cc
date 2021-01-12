/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        k = std::min(k, n / 2);
        // buy[i][j] 第i天, 第 j 次交易, 持有股票的收益
        // sell[i][j] 第i天, 第 j ci交易, 不持有股票的收益
        // 一次交易包含 buy && send
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));
        // 没有股票, 任何时候交易都是无效的
        for (int i = 0; i <= k; i++) {
            buy[0][i] =sell[0][i] = INT_MIN / 2;
        }
        // 第0次的交易, 不持有股票 为0
        sell[0][0] = 0;
        // 第0次的交易, 持有股票的收益为 -prices[0
        buy[0][0] = - prices[0];
        for (int i = 1; i < n; i++) {
            buy[i][0] = std::max(buy[ i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = std::max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *(std::max_element)(sell[n - 1].begin(), sell[n - 1].end());
    }
};
// @lc code=end

