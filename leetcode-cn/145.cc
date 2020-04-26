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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * cur;
        vector<int> result;
        stack<TreeNode*> s;
        if (root == nullptr) return result;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            result.push_back(cur->val);
            if (cur->left != nullptr) s.push(cur->left);
            if (cur->right != nullptr) s.push(cur->right);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};