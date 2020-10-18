class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = INT_MAX;
            for (int j = 1; (i - j * j >= 0); j++) {
                dp[i] = std::min(dp[i], dp[i -j * j] + 1)
            } 
        }
        return dp[n];
    }
};