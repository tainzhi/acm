/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
// 转换成 0 - 1背包问题
// 将数字看成两部分, P和N,其中 P 使用正号，N 使用负号，有以下推导：
//                   sum(P) - sum(N) = target
// sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
//                        2 * sum(P) = target + sum(nums)

    int findTargetSumWays1(vector<int>& nums, int S) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        sum = (sum + S) / 2;
        int dp[sum + 1];
        std::fill_n(dp, sum + 1, 0);
        dp[0] = 1;
        for (int num: nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[sum];
    }

    // DFS解法
    int findTargetSumWays(vector<int>& nums, int S) {
        return findSubWasy(nums, 0, S);
    }

    unsigned int findSubWasy(vector<int>& nums, int start, unsigned int S) {
        if (start == nums.size()) {
            return S == 0 ? 1: 0;
        }
        return findSubWasy(nums, start + 1, S + nums[start]) + findSubWasy(nums, start + 1, S - nums[start]);
    }
};
// @lc code=end

