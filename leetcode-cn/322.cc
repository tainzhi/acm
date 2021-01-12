/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
private:
    int minRet;
public:
    // 完全背包
    // dp[j] j金额的最少硬币数
    // dp[j] 的3种转移方法
    int coinChange1(vector<int>& coins, int amount) {
        int dp[amount + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int coin: coins) {
            for (int j = coin; j <= amount; j++) {
                // 转移1: 完全只有一个货币coin
                if (j - coin == 0) {
                    dp[j] = 1;
                } else if (dp[j - coin] != -1 && dp[j] == -1) {
                // 转移2: 只能从dp[j-coin] + coin转移过来
                    dp[j] = dp[j - coin] + 1;
                } else if (dp[j - coin] != -1) {
                // 转移3: dp[j] 和dp[j - coin] + 1中的最小值
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);
                }
            }
        }
        return dp[amount];
    }

    // 递归法(超时)
    int coinChange2(vector<int>& coins, int amount) {
        minRet = INT_MAX;
        findWays(coins, amount, 0);
        return minRet == INT_MAX ? -1: minRet;
    }

    // 硬币金额还剩余amount时, 选择了count枚硬币
    // minRet选择的最少硬币数
    void findWays(vector<int>& coins, int amount, int count) {
        if (amount < 0) return;
        if (amount == 0) {
            if (count < minRet) {
                minRet = count;
            }
        } else {
            for (int coin: coins) {
                findWays(coins, amount - coin, count + 1);
            }
        }
    }

    // 递归法+记忆化搜索
    // dp[i] 记录金额为 i 时的最少硬币数
    int coinChange3(vector<int>& coins, int amount) {
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        return dfs(coins, dp, amount);
    }

    int dfs(vector<int>& coins, int * dp, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (dp[amount] != 0) {
            return dp[amount];
        }
        int min = INT_MAX, res;
        for (int coin: coins) {
            res = dfs(coins, dp, amount - coin);
            if (res >= 0 && res < min) {
                min = res;
            }
        }
        dp[amount] = min == INT_MAX ? -1 : min + 1;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for (int i = 0; i <= amount; i++) {
            // 因为 amount可能为0
            // 比如 coins = [1], amount = 0
            dp[i] = amount + 1;
        }
        // memset只适合用来初始化-1或者0
        // std::fill_n(dp, sizeof(dp), INT_MAX);
        // std::fill_n(dp, amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++){
            for (int coin: coins){
                if (i >= coin) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1: dp[amount];
    }


};
// @lc code=end

