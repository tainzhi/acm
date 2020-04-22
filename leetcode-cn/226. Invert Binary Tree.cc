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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode * leftChild = root->left, *rightChild = root->right;
        invertTree(root->left);
        invertTree(root->right);
        root->left = rightChild;
        root->right = leftChild;
        return root;
    }
};