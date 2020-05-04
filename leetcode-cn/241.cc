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