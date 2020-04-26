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
    int minValue = 0, secondMinValue = 0;
    void dfs(TreeNode * root) {
        if (root == nullptr) return;
        if (root->val > minValue) {
            if (secondMinValue == minValue) {
                secondMinValue = root->val;
            } else {
                secondMinValue = std::min(secondMinValue, root->val);
            }
        }
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        minValue = -1;
        if (root != nullptr) {
            minValue = root->val;
            secondMinValue = minValue;
            dfs(root->left);
            dfs(root->right);
        }
        return secondMinValue == minValue ? -1 : secondMinValue;
    }
};