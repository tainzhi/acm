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
    int subTree(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + subTree(root->left, sum) + subTree(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return subTree(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};