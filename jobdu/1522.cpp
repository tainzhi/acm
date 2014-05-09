/*************************************************************************
    > File: jodbu 1522
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sat 22 Feb 2014 10:24:54 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        char str[2];
        int num;
        std::stack<int> numStack, minStack;
        while (n--)
        {
            scanf("%s", str);
            if (str[0] == 's')
            {
                scanf("%d", &num);
                numStack.push(num);
                if (minStack.empty() || minStack.top() >= num)
                    minStack.push(num);
            }
            else if (str[0] == 'o')
            {
                int st = numStack.top();
                numStack.pop();
                if (st <= minStack.top())
                    minStack.pop();
            }
            if (numStack.empty())
                printf("NULL\n");
            else
                printf("%d\n", minStack.top());
        }
    }
    return 0;
}
