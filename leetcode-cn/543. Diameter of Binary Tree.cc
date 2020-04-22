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
    int diameter = 0;
    int lengthOfTree(TreeNode * root) {
        if (root == NULL) return 0;
        int leftChildLength = lengthOfTree(root->left);
        int rightChildLength = lengthOfTree(root->right);
        diameter = std::max(diameter, leftChildLength + rightChildLength );
        return std::max(leftChildLength, rightChildLength) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        lengthOfTree(root);
        return diameter;
    }
};