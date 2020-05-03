class Solution
{
public:
    long calculate(string s)
    {
        stack<long> numStack;
        stack<char> operatorStack;
        long tmpSum = -1, num1, num2;
        char operatorChar;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
            {
                if (tmpSum == -1)
                {
                    tmpSum = c - '0';
                }
                else
                {
                    tmpSum = tmpSum * 10 + c - '0';
                }
            }
            else
            {
                if (tmpSum != -1)
                {
                    numStack.push(tmpSum);
                    tmpSum = -1;
                }
                if (c == '(')
                {
                    operatorStack.push(c);
                }
                else if (c == ' ')
                {
                    continue;
                }
                else if (c == ')')
                {
                    while (!operatorStack.empty() && operatorStack.top() != '(')
                    {
                        num2 = numStack.top();
                        numStack.pop();
                        num1 = numStack.top();
                        numStack.pop();
                        numStack.push(eval(operatorStack.top(), num1, num2));
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
                else
                {
                    if (operatorStack.empty() || operatorPriority(c, operatorStack.top()))
                    {
                        operatorStack.push(c);
                    }
                    else
                    {
                        while (!operatorStack.empty() && !operatorPriority(c, operatorStack.top()))
                        {
                            num2 = numStack.top();
                            numStack.pop();
                            num1 = numStack.top();
                            numStack.pop();
                            numStack.push(eval(operatorStack.top(), num1, num2));
                            operatorStack.pop();
                        }
                        operatorStack.push(c);
                    }
                }
            }
        }
        if (tmpSum != -1)
        {
            numStack.push(tmpSum);
        }
        while (!operatorStack.empty())
        {
            num2 = numStack.top();
            numStack.pop();
            num1 = numStack.top();
            numStack.pop();
            numStack.push(eval(operatorStack.top(), num1, num2));
            operatorStack.pop();
        }
        return numStack.top();
    }

    bool operatorPriority(char a, char b)
    {
        long num1, num2;
        if (b == '(') {
            num2 = 0;
        }
        if (a == '+' || a == '-')
        {
            num1 = 1;
        }
        else if (a == '*' || a == '/')
        {
            num1 = 2;
        }
        if (b == '+' || b == '-')
        {
            num2 = 1;
        }
        else if (b == '*' || b == '/')
        {
            num2 = 2;
        }
        return (num1 - num2) > 0;
    }

    long eval(char op, long num1, long num2)
    {
        if (op == '+')
        {
            return num1 + num2;
        }
        else if (op == '-')
        {
            return num1 - num2;
        }
        else if (op == '*')
        {
            return num1 * num2;
        }
        else if (op == '/')
        {
            return num1 / num2;
        }
        return 0;
    }
};