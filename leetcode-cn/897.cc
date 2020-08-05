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
        auto ans = new TreeNode(0);
        cur = ans;
        inOrder(root);
        return ans->right;
    }

    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cur->left = nullptr;
            cur->right = root;
            cur = root;
            inOrder(root->right);
        }
    }
};