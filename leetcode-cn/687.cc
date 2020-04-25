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
    int maxLength = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int currentSum = 1;
        int leftSum = dfs(root->left), rightSum = dfs(root->right);
        bool leftEqual = false, rightEqual = false;
        if (root->left != nullptr && root->val == root->left->val) {
            leftEqual = true;
            currentSum += leftSum;
        }
        if (root->right != nullptr && root->val == root->right->val) {
            rightEqual = true;
            currentSum += rightSum;
        }
        maxLength = std::max(maxLength, currentSum);
        if (leftEqual && rightEqual) {
            return std::max(leftSum, rightSum) +1;
        }
        return currentSum;
    }

    int longestUnivaluePath(TreeNode* root) {
        maxLength = INT_MIN;
        dfs(root);
        return maxLength == INT_MIN ? 0 : maxLength - 1;
    }
};