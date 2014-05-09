/*************************************************************************
    > File: jobdu 1368
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sun 23 Feb 2014 10:13:51 AM CST
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
    int depth;
    int sum;
    struct node *left;
    struct node *right;
};

void preOrder(node *root)
{
    if (!root)
        return;
    printf("*%d dep=%d %d*", root->data,root->depth, root->sum);
    preOrder(root->left);
    preOrder(root->right);
}

void output(node *root, int k, int *path)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (root->sum == k)
        {
            path[root->depth] = root->data;
            printf("A path is found:");
            for (int i=1; i<=root->depth; i++)
                printf(" %d", path[i]);
            printf("\n");
            return;
        }
        else
            return;
    }
    if (root->left && root->right)
    {
        if (root->left->data < root->right->data)
        {
            path[root->depth] = root->data;
            output(root->left, k, path);
            output(root->right, k, path);
        }
        else
        {
            path[root->depth] = root->data;
            output(root->right, k, path);
            output(root->left, k, path);
        }
    }
    else
    {
        if (root->left)
        {
            path[root->depth] = root->data;
            output(root->left, k, path);
        }
        if (root->right)
        {
            path[root->depth] = root->data;
        output(root->right, k, path);
        }
    }
}

int main()
{
    int n, k;
    int dot[10010], path[10010];
    int child[10010][2];
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i=1; i<=n; i++)
            scanf("%d%d%d", &dot[i], &child[i][0], &child[i][1]);
        //rebuild tree
        node * root = (node *)malloc(sizeof(node));
        root->data=1;
        root->depth=1;
        root->sum=dot[1];
        root->left = root->right = NULL;
        std::queue<node *> myqueue;
        myqueue.push(root);
        while (!myqueue.empty())
        {
            node *rt = myqueue.front();
            myqueue.pop();
            if (child[rt->data][0] != -1)
            {
                rt->left = (node *)malloc(sizeof(node));
                rt->left->data = child[rt->data][0];
                rt->left->depth = rt->depth+1;
                rt->left->sum = rt->sum + dot[rt->left->data];
                rt->left->left = rt->left->right = NULL;
                myqueue.push(rt->left);
            }
            if (child[rt->data][1] != -1)
            {
                rt->right = (node *)malloc(sizeof(node));
                rt->right->data = child[rt->data][1];
                rt->right->depth = rt->depth + 1;
                rt->right->sum = rt->sum + dot[rt->right->data];
                rt->right->left = rt->right->right = NULL;
                myqueue.push(rt->right);
            }
        }
        printf("result:\n");
        //preOrder(root);
        output(root, k, path);
    }
    return 0;
}

