/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dp[col];
        dp[0] = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (j == 0) {
                    // 只能上面的节点 向下走
                    dp[j] = dp[j];
                } else if (i == 0) {
                    // 只能左边点向 右走
                    dp[j] = dp[j - 1];
                } else {
                    dp[j] = std::min(dp[j], dp[j - 1]);
                }
                dp[j] += grid[i][j];
            }
        }
        return dp[col - 1];
    }
};
// @lc code=end

