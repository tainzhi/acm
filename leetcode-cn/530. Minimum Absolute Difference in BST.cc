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

    int min_val = INT_MAX;
    int pre_val = -1;

    void inOrder(TreeNode * root) {
        if (root == NULL)
            return;
        inOrder(root->left);
        if (pre_val != -1) {
            min_val = std::min(min_val, root->val - pre_val);
        }
        pre_val = root->val;
        inOrder(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        min_val = INT_MAX;
        pre_val = -1;
        inOrder(root);
        return min_val;
    }
};