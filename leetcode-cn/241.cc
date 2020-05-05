class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); i++){
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> leftResult = diffWaysToCompute(input.substr(0, i));
                vector<int> rightResult = diffWaysToCompute(input.substr(i+1));
                for (auto leftNum: leftResult) {
                    for (auto rightNum: rightResult) {
                        result.push_back(eval(input[i], leftNum, rightNum));
                    }
                }
            }
        }
        // 全是数字
        int tmpsum = 0;
        if (result.empty()) {
            for (auto c: input) {
                tmpsum = tmpsum * 10 + c - '0';
            }
            result.push_back(tmpsum);
        }
        return result;
    }

    int eval(char op, int num1, int num2){
        if (op == '+') return num1 + num2;
        else if (op == '-') return num1 - num2;
        // num1 * num2
        else
        {
            return num1 * num2;
        }
        
    }
};

class Solution {
private:
    vector<int> nums;
    vector<char> syns;
public:
    vector<int> diffWaysToCompute(string input) {
        int num = 0;
        for (auto c: input) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else {
                if (num != 0) {
                    nums.push_back(num);
                    num = 0;
                }
                syns.push_back(c);
            }
        }
        nums.push_back(num);
        int len = nums.size();
        vector<int> dp[len][len];
        for (int i = 0; i < len; i++) dp[i][i].push_back(nums[i]);
        for (int step = 1; step <= len - 1; step++) {
            for (int i = 0, j=step; i < len && j < len; i++, j++) {
                for (int k = i; k < j; k++) {
                    for (auto num1: dp[i][k]) {
                        for (auto num2: dp[k+1][j]) {
                            if (syns[k] == '+') dp[i][j].push_back(num1 + num2);
                            else if (syns[k] == '-') dp[i][j].push_back(num1 - num2);
                            else if (syns[k] == '*') dp[i][j].push_back(num1 * num2);

                        }
                    }
                }
            }
        }
        return dp[0][len - 1];
    }
};