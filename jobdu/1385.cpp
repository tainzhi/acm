/*************************************************************************
    > File: joddu1385
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 18 Feb 2014 01:40:00 PM CST
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

#define N 1005

using namespace std;

struct node {
    int data;
    struct node * leftChild;
    struct node * rightChild;
};
int preOrder[N], inOrder[N], postOrder[N];
bool flag = true;

node* reBuild(int preStart, int preEnd, int inStart, int inEnd)
{
    //printf("%d %d %d %d***\n",preStart, preEnd, inStart, inEnd);
    node * root = (node *)malloc(sizeof(node));
    int mid = -1;
    //printf("%d %d-----\n", preOrder[preStart], inOrder[inStart]);
    for (int i = inStart; i <= inEnd; i++)
        if (preOrder[preStart] == inOrder[i])
        {
            //printf("%d %d-----\n", preOrder[preStart], inOrder[i]);
            mid = i;
            break;
        }
    //printf("mid = %d\n", mid);
    if (mid == -1)
        flag = false;
    else
    {
        root->data = preOrder[preStart];
        //not have childs
        if (preStart == preEnd && inStart == inEnd && preOrder[preStart] == inOrder[inStart])
            root->leftChild = root -> rightChild = NULL;
        else
        {
            //only have right child
            if (mid == inStart)
            {
                root->leftChild = NULL;
                root->rightChild = reBuild(preStart+mid-inStart+1, preEnd, mid+1, inEnd);
            }
            //only have left child
            else if (mid == inEnd)
            {
                root->leftChild = reBuild(preStart+1, preStart+mid-inStart, inStart, mid-1);;
                root->rightChild = NULL;
            }
            else
            {
                root->leftChild = reBuild(preStart+1, preStart+mid-inStart, inStart, mid - 1);
                root->rightChild = reBuild(preStart+mid-inStart+1, preEnd, mid+1, inEnd);
            }
        }
        return root;
    }
}

void postOrderOutput(node * root)
{
    if (root->leftChild)
        postOrderOutput(root->leftChild);
    if (root->rightChild)
        postOrderOutput(root->rightChild);
    printf("%d ", root->data);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &preOrder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &inOrder[i]);
        flag = true;
        node * root = reBuild(0, n -1, 0, n - 1);
        if (flag)
        {
            postOrderOutput(root);
            printf("\n");
        }
        else
            printf("No\n");
    }
    return 0;
}

