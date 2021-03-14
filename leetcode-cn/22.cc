/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    vector<string> generateParenthesis1(int n) {
        vector<vector<string>> dp(n + 1, vector<string>());
        dp[0] = {""};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto left = dp[j];
                auto right = dp[i - 1 - j];
                for (string ll: left) {
                    for (string rr: right) {
                        dp[i].push_back('(' + ll + ')' + rr);
                    }
                }
            }
        }
        return dp[n];
    }

    ////////////////////////////////
    // 方法二: 暴力法

    bool isValid(string &s) {
        int balance = 0;
        for (char c: s) {
            if (c == '(') 
                balance++;
            else 
                balance--;
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generateAll(vector<string> &ans, string &current, int n) {
        if (current.size() == 2 * n) {
            if (isValid(current)) ans.push_back(current);
        } else {
            current += '(';
            generateAll(ans, current, n);
            current.pop_back();

            current += ')';
            generateAll(ans, current, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis2(int n) {
        vector<string> ans;
        string current;
        generateAll(ans, current, n);
        return ans;
    }

    ////////////////////////////////
    // 优化的方法

    void generate(vector<string> &ans, string &current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            ans.push_back(current);
        } else {
            if (open < n) {
                current += '(';
                generate(ans, current, open + 1, close, n);
                current.pop_back();
            }
            if (close < open) {
                current += ')';
                generate(ans, current, open, close + 1, n);
                current.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        generate(ans, current, 0, 0, n);
        return ans;
    }

};
// @lc code=end

