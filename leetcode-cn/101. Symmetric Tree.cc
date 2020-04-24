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
    bool dfs(TreeNode* t, TreeNode * s) {
        if (t == nullptr && s == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (t->val == s->val) {
            return dfs(t->left, s->right) && dfs(t->right, s->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }
};