/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
private:
    vector<char> sign;
    vector<int> numbers;
public:
    vector<int> diffWaysToCompute(string input) {
        int num = 0;
        for (char c: input) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else {
                sign.emplace_back(c);
                numbers.emplace_back(num);
                num = 0;
            }
        }
        numbers.emplace_back(num);
        int size = numbers.size();
        vector<int> dp[size][size];
        for (int i = 0; i < size; i++) {
            dp[i][i].emplace_back(numbers[i]);
        }
        for (int step = 1; step < size; step++) {
            for (int i = 0, j = step; i < size && j < size; i++, j++) {
                for (int k = i; k < j; k++) {
                    for (int lvalue: dp[i][k]) {
                        for (int rvalue: dp[k + 1][j]) {
                            dp[i][j].emplace_back(eval(sign[k], lvalue, rvalue));
                        }
                    }
                }
            }
        }
        return dp[0][size - 1];
    }

    int eval(char ope, int lvalue, int rvalue) {
        if (ope == '+') return lvalue + rvalue;
        if (ope == '-') return lvalue - rvalue;
        if (ope == '*') return lvalue * rvalue;
        return 0;
    }
};
// @lc code=end

