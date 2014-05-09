/*************************************************************************
    > File: jodbu 1366
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sat 22 Feb 2014 10:49:14 AM CST
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

#define N 1000010

using namespace std;

int main()
{
    int inOrder[N], popOrder[N];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &inOrder[i]);
        for (int i=0; i<n;i ++)
            scanf("%d", &popOrder[i]);
        std::stack<int> mystack;
        int ii=0, ip=0;
        mystack.push(inOrder[0]);
        while (true)
        {
            if (!mystack.empty() && mystack.top() == popOrder[ip])
            {
                ip++;
                mystack.pop();
            }
            else
            {
                ii++;
                if (ii < n)
                    mystack.push(inOrder[ii]);
                else
                    break;
            }
        }
        if (ip == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

