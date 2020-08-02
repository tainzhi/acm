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
    TreeNode * cur;
    TreeNode* increasingBST(TreeNode* root) {
        cur = new TreeNode(0);
        inOrder(root);
        return cur->right;
    }

    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cur->left = nullptr;
            cur->right = root;
            inOrder(root->right);
            cur = root;
        }
    }
};