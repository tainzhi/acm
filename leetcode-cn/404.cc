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
    int sum = 0;
    void dfs(TreeNode * root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr)
                sum += root->left->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root);
        return sum;
    }
};