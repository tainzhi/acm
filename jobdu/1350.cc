#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

struct binary_tree_node{
    int value;
    struct binary_tree_node * left;
    struct binary_tree_node * right;
};

binary_tree_node * BuildBinaryTree(int * child_information)
{
    binary_tree_node * root = (binary_tree_node *)malloc(sizeof(binary_tree_node));
    root->value = 1;
    root->left = root->right = NULL;
    std::queue<binary_tree_node *> myqueue;
    myqueue.push(root);
    while (myqueue.empty() == false)
    {
        binary_tree_node * current_node = myqueue.front();
        myqueue.pop();
        int current_value = current_node->value;
        //printf("value=%d\n", current_value);
        if (*(child_information + 2 * current_value + 0) != -1)
        {
            current_node->left = (binary_tree_node*)malloc(sizeof(binary_tree_node));
            current_node->left->value = *(child_information + 2 * current_value + 0);
            current_node->left->left = current_node->left->right = NULL;
            myqueue.push(current_node->left);
        }
        if (*(child_information + 2 * current_value + 1) != -1)
        {
            current_node->right = (binary_tree_node*)malloc(sizeof(binary_tree_node));
            current_node->right->value = *(child_information + 2 * current_value + 1);
            current_node->right->left = current_node->right->right = NULL;
            myqueue.push(current_node->right);
        }
    }
    return root;
}

int GetBinaryTreeDepth(binary_tree_node * root)
{
    if (root == NULL)
        return 0;
    int left_depth = GetBinaryTreeDepth(root->left);
    int right_depth = GetBinaryTreeDepth(root->right);
    return ((left_depth > right_depth) ? left_depth : right_depth) + 1;
}

int main()
{
    int n, child_information[20][2];
    while (scanf("%d", &n) != EOF)
    {
        for (int i=1; i<=n; i++)
            scanf("%d%d", &child_information[i][0], &child_information[i][1]);
        binary_tree_node * tree_root = BuildBinaryTree(&child_information[0][0]);
        printf("%d\n", GetBinaryTreeDepth(tree_root));
    }
    return 0;
}

