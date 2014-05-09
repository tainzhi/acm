/*************************************************************************
    > File: jobdu 1523
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sun 23 Feb 2014 08:21:10 AM CST
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

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

/*
void preOrder(node *root, int * pre, int &count)
{
    if (!root)
        return;
    pre[++count] = root->data;
    preOrder(root->right, pre, count);
    preOrder(root->left, pre, count);
}
*/

int main()
{
    int dot[1010], tdo[1010][2];
    int scope[1010];
    char str[1010][2];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            printf("NULL\n");
        else
        {
            for (int i=1; i<=n; i++)
                scanf("%d", &dot[i]);
            for (int i=1; i<=n; i++)
            {
                scanf("%s", str[i]);
                if (str[i][0] == 'd')
                    scanf("%d%d", &tdo[i][0], &tdo[i][1]);
                else if (str[i][0] == 'l' || str[i][0] == 'r')
                    scanf("%d", &tdo[i][0]);
            }
            int count = 0;
            node *root = (node *)malloc(sizeof(node));
            root->data = 1;
            root->left = root->right = NULL;
            std::queue<node *> myqueue;
            myqueue.push(root);
            while (!myqueue.empty())
            {
                node *rt = myqueue.front();
                myqueue.pop();
                scope[++count] = dot[rt->data];
                if (str[rt->data][0] == 'd')
                {
                    rt->left = (node *)malloc(sizeof(node));
                    rt->left->data = tdo[rt->data][0];
                    rt->left->left = rt->left->right = NULL;
                    myqueue.push(rt->left);

                    rt->right = (node *)malloc(sizeof(node));
                    rt->right->data = tdo[rt->data][1];
                    rt->right->left = rt->right->right = NULL;
                    myqueue.push(rt->right);
                }
                else if (str[rt->data][0] == 'l')
                {
                    rt->left = (node *)malloc(sizeof(node));
                    rt->left->data = tdo[rt->data][0];
                    rt->left->left = rt->left->right = NULL;
                    myqueue.push(rt->left);
                }
                else if (str[rt->data][0] == 'r')
                {
                    rt->right = (node *)malloc(sizeof(node));
                    rt->right->data = tdo[rt->data][0];
                    rt->right->left = rt->right->right = NULL;
                    myqueue.push(rt->right);
                }
            }
            for (int i=1; i<=n; i++)
                printf("%d%c", scope[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}

