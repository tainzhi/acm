/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isBalancedTree = true;
    int treeHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftChildHeight = treeHeight(root->left);
        int rightChildHeight = treeHeight(root->right);
        if (std::abs(leftChildHeight - rightChildHeight) > 1) {
            isBalancedTree = false;
        }
        return std::max(leftChildHeight, rightChildHeight) +1;
    }
    bool isBalanced(TreeNode* root) {
        treeHeight(root);
        return isBalancedTree;
    }
};