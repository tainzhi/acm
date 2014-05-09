/*************************************************************************
    > File: jobdu 1520
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Fri 21 Feb 2014 11:53:57 AM CST
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

#define N 1010

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void preOrder(node * root)
{
    if (!root)
        return;
    printf("%d* ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

node * buildTree(int n, int *na)
{
    /*
    printf("-------------test----------------\n");
    for (int i=0; i<n; i++)
    {
        printf("%d-- ", *(na + 3 *i + 2));
        for (int j=0; j<*(na + 3*i +2); j++)
            printf(" %d", *(na + 3*i + j));
        printf("\n");
    }
    printf("--------------test---------------\n");
    */
    node *root = (node *)malloc(sizeof(node));
    root->data=0;
    root->left = root->right = NULL;
    std::queue<node *> myqueue;
    myqueue.push(root);
    while (!myqueue.empty())
    {
        node * rt = myqueue.front();
        myqueue.pop();
        //printf("\n----------%d------%d %d %d\n", rt->data, *(na + 3 * rt->data + 2),*(na + 3 * rt->data + 0), *(na + 3 *rt->data + 1));
        if (*(na + 3 * rt->data + 2) == 1)
        //if (na[rt->data][2] == 1)
        {
            //printf("\n-----------%d-----------\n", *(na+3 * rt->data + 2));
            rt->left = (node *)malloc(sizeof(node));
            //rt->left->data = na[rt->data][0] - 1;
            rt->left->data = *(na + 3 * rt->data + 0);
            rt->left->left = rt->left->right = NULL;
            myqueue.push(rt->left);
        }
        else if (*(na + 3 * rt->data + 2) == 2)
        //else if (na[rt->data][2] == 2)
        {
            //printf("******%d %d----------\n",*(na + 3*rt->data+0), *(na+3*rt->data+1));
            rt->left = (node *)malloc(sizeof(node));
            //rt->left->data = na[rt->data][0]-1;
            rt->left->data = *(na + 3 * rt->data + 0);
            rt->left->left = rt->left->right = NULL;
            myqueue.push(rt->left);
            
            rt->right = (node *)malloc(sizeof(node));
            //rt->right->data = na[rt->data][1]-1;
            rt->right->data = *(na + 3 * rt->data + 1);
            rt->right->left = rt->right->right = NULL;
            myqueue.push(rt->right);
        }
    }
    /*
    printf("----------pre------------\n");
    preOrder(root);
    printf("\n----------pre------------\n");
    */
    return root;
}

bool same(node * treeA, int *ta, node * treeB, int *tb)
{
    if (treeB == NULL)
        return true;
    else if(treeB)
    {
        if (treeA == NULL)
            return false;
        else
        {
            if ((ta[treeA->data] == tb[treeB->data]) && same(treeA->left, ta, treeB->left, tb) && same(treeA->right, ta, treeB->right, tb))
                return true;
            else
                return false;
        }
    }
}



bool judge(node * treeA, int *ta, node * treeB, int *tb)
{
    std::queue<node *> myqueue;
    myqueue.push(treeA);
    bool flag = false;
    while (!myqueue.empty())
    {
        node * rt = myqueue.front();
        myqueue.pop();
        if (flag)
            break;
        else
        {
            if (same(rt, ta, treeB, tb))
            {
                flag = true;
                break;
            }
            else
            {
                if (rt->left)
                    myqueue.push(rt->left);
                if (rt->right)
                    myqueue.push(rt->right);
            }
        }
    }
    return flag;
}


int main()
{
    int ta[N], tb[N];
    int na[N][3], nb[N][3];
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i=0; i<m; i++)
            scanf("%d", &ta[i]);

        for (int i=0; i<m; i++)
        {
            scanf("%d", &na[i][2]);
            for (int j=0; j < na[i][2]; j++)
                scanf("%d", &na[i][j]), na[i][j] -= 1;
        }

        for (int i=0; i<n; i++)
            scanf("%d", &tb[i]);
        for (int i=0; i<n; i++)
        {
            scanf("%d", &nb[i][2]);
            for (int j=0; j<nb[i][2]; j++)
                scanf("%d", &nb[i][j]), nb[i][j] -= 1;
        }
        /*
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<3; j++)
                printf("*%d* ", na[i][j]);
            printf("\n");
        }
        */

        node * treeA, * treeB;
        treeA = buildTree(m, &na[0][0]);
        //printf("\n********************");
        treeB = buildTree(n, &nb[0][0]);
        /*
        printf("\n*******************\n");
        preOrder(treeA);
        printf("treeA->data=%d\n", treeA->data);
        printf("\n*******************\n");
        */
        if (judge(treeA, ta, treeB, tb))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
        





