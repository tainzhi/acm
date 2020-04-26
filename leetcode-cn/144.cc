非递归先序遍历



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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root == nullptr) return result;
        s.push(root);
        TreeNode *cur;
        while (!s.empty()) {
            cur = s.top();
            result.push_back(cur->val);
            s.pop();
            if (cur->right != nullptr) s.push(cur->right);
            if (cur->left != nullptr) s.push(cur->left);
        }
        return result;
    }
};