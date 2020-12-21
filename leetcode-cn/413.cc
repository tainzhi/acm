/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分(注意题目中是相邻数字, 而不是间隔的)
 * dp[i] 表示以A[i]结尾的等差数列
 * 如果A[i] - A[i - 1] == A[i - 1] - A[i - 2]则表示以dp[i - 1]再增加一个等差数列
 * 所以, dp[i] = dp[ i - 1] + 1
 * 注意: dp初始化为0
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int dp[A.size()];
        std::fill_n(dp, A.size(), 0);
        if (A.size() < 3) return 0;
        // dp[0] = 0, dp[1] = 0;
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i- 1] - A[i-2]) {
                dp[i] = dp[i - 1] + 1;
            } 
            sum += dp[i];
        }
        return sum;
    }
};

