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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
           return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return sum == root->val;
        }
        int remain = sum - root->val;
        return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
    }
};