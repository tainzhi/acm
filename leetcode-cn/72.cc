/*
 * dp[i][j] word1[i]和word2[j]的最小编辑距离
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0 && n == 0) return 0;
        if (m == 0) return n;
        if (n == 0) return m;
        int dp[m +1][n + 1];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int a = dp[i - 1][j] +1;
                int b = dp[i][j - 1] + 1;
                dp[i][j] = std::min(a, b);
                int c = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    c += 1; 
                }
                dp[i][j] = std::min(dp[i][j], c);
            }
        }
        return dp[m][n];
    }
};