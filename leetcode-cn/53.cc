class Solution {
public:
    // 动态规划
    // dp[i] = max( dp[i - 1] + num[i],  num[i])
    int maxSubArray1(vector<int>& nums) {
        int dp[nums.size()];
        std::fill_n(dp, nums.size(), 0);
        if (nums.empty()) return 0;
        dp[0] = nums[0];
        int maxRet = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            maxRet = std::max(dp[i], maxRet);
        }
        return maxRet;
    }

    // 贪心法
    // 如果 sum >0 ,说明当前num[i] 对结果有增益, 则 sum = sum + num[i],
    // 反之, sum <= 0, 说明当前num[i]对结果有损耗, 则 sum = num[i]
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxRet = INT_MIN;
        for (int i : nums) {
            if (sum > 0) {
                sum = sum + i;
            } else {
                sum = i;
            }
            maxRet = std::max(maxRet, sum);
        }
        return maxRet;
    }
};