/*************************************************************************
    > File: jobdu 1503
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Mon 24 Feb 2014 10:14:33 PM CST
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
    int value;
    struct node *left;
    struct node *right;
};

node * buildTree(int &tc, int n, int *dot)
{
    if (tc >= n)
        return NULL;
    if (dot[tc] == 0)
    {
        tc++;
        return NULL;
    }
    node * root = (node *)malloc(sizeof(node));
    root->value = dot[tc];
    //printf("tc=%d n=%d\n", tc, n);
    tc++;
    root->left = buildTree(tc, n, dot);
    root->right = buildTree(tc, n, dot);
}

void convertNode(node *root, node ** last)
{
    if (!root)
        return;
    //printf("root->value=%d\n",root->value);
    if (root->left)
        convertNode(root->left, last);
    root->left= (*last);
    if (*(last) != NULL)
        (*last)->right = root;
    (*last) = root;
    if (root->right)
        convertNode(root->right, last);
}

node * binaryTreeConvert(node *root)
{
    node * last = NULL;
    convertNode(root, &last);
    node *head = last;
    //printf("head->value=%d\n", head->value);
    while (head && head->left)
        head = head->left;
    return head;
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int test;
    scanf("%d", &test);
    {
        while (test--)
        {
            int dot[1010];
            int count=0, rc;
            char c;
            while (1)
            {
                scanf("%d%c", &rc, &c);
                dot[count++] = rc;
                if (c == '\n')
                    break;
            }
            int tc = 0;
            /*
            for (int i=0; i<count; i++)
                printf("%d- ", dot[i]);
                */
            node * root = buildTree(tc, count, dot);
            /*
            printf("************\n");
            preOrder(root);
            printf("\n**************\n");
            */
            node * head = binaryTreeConvert(root);
            /*
            if (head == NULL)
                printf("NULL\n");
            printf("**********value=%d\n",head->value);
            */
            while (head->right)
            {
                printf("%d ", head->value);
                head = head->right;
            }
            printf("%d\n", head->value);
        }
    }
    return 0;
}

