class Solution {
public:
    long calculate(string s) {
        stack<long numStack;
        stack<char> operaStack;
        long tmpSum = -1, num1, num2;
        char ope;
        for (auto c: s) {
            if (c == ' ') continue;
            if (isOperator(c)) {
                if (tmpSum != -1) {
                    numStack.push(tmpSum);
                    tmpSum = -1;
                }
                if (operaStack.empty())  {
                    operaStack.push(c);
                } else  {
                    if (operaPri(c, operaStack.top())) {
                        operaStack.push(c);
                    } else {
                        while (!operaStack.empty() && !operaPri(c, operaStack.top())) {
                            num2 = numStack.top();
                            numStack.pop();
                            num1 = numStack.top();
                            numStack.pop();
                            ope = operaStack.top();
                            operaStack.pop();
                            numStack.push(eval(ope, num1, num2));
                        }
                        operaStack.push(c);
                    }
                }
            } else {
                if (tmpSum == -1) {
                    tmpSum = c - '0';
                } else {
                    tmpSum = tmpSum * 10 + c - '0';
                }
            }
        }
        numStack.push(tmpSum);
        while (!operaStack.empty()) {
            num2 = numStack.top();
            numStack.pop();
            num1 = numStack.top();
            numStack.pop();
            ope = operaStack.top();
            operaStack.pop();
            numStack.push(eval(ope, num1, num2));
        }
        return numStack.top();
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool operaPri(char a, char b) {
        long num1, num2;
        if (a == '+' || a == '-')  {
            num1 = 1;
        } else if (a == '*' || a == '/') {
            num1 = 2;
        }
        if (b == '+' || b == '-') {
            num2 = 1;
        } else if (b == '*' || b == '/') {
            num2 = 2;
        }
        return (num1 - num2) > 0;
    }

    long eval(char op, long num1, long num2) {
        if (op == '+') {
            return num1 +num2;
        } else if (op == '-') {
            return num1 - num2;
        } else if (op == '*') {
            return num1 * num2;
        } else if (op == '/') {
            return num1 / num2;
        }
        return 0;
    }
};