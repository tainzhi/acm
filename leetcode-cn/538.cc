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
    // 栈实现
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* current = root;
        int sum = 0;
        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->right;
            }
            current = stack.top();
            stack.pop();
            sum += current->val;
            current->val = sum;
            current = current->left;
        }
        return root;
    }

    void dfs(TreeNode * root, int &sum) {
        if (root == nullptr) return;
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
    }

    // 递归实现
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};