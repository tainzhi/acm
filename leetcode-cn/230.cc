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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> stack;
        TreeNode * c = root;
        while (c != nullptr || !stack.empty()) {
            while (c != null) {
                stack.push(c);
                c = c->left;
            }
            c = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return c->val;
            }
            c = c->right;
        }
    }
};