class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (auto s: tokens) {
            if (isOperator(s)) {
                int num2 = stack.top();
                stack.pop();
                int num1 = stack.top();
                stack.pop();
                stack.push(calculate(s, num1, num2));
            } else {
                stack.push(stringToInt(s));
            }
        }
        return stack.top();
    }

    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int calculate(string ope, int num1, int num2) {
        if (ope == "+") {
            return num1 + num2;
        } else if (ope == "-") {
            return num1 - num2;
        } else if (ope == "/") {
            return num1 / num2;
        } else if (ope == "*") {
            return num1 * num2;
        } else{
            return 0;
        }
    }

    int stringToInt(string number) {
        int sum = 0;
        int sign = 1;
        for (auto c: number) {
            if (c == '-')  {
                sign = -1;
            } else {
            sum = sum * 10 + c - '0';
            }
        }
        return sum * sign;
    }
};