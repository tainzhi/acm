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
    // pair.first不含该节点
    // pair.second包含该节点
    typedef pair<int, int> dp;

    dp dfs(TreeNode* root) {
        if (root == nullptr) return dp(0, 0);
        dp ret(0, root->val);
        if (root->left != nullptr) {
            dp l = dfs(root->left);
            ret.first += std::max(l.first, l.second);
            ret.second += l.first;
        }
        if (root->right != nullptr) {
            dp r = dfs(root->right);
            ret.first += std::max(r.first, r.second);
            ret.second += r.first;
        }
        return dp(ret.first, std::max(ret.first, ret.second));
    }
    int rob(TreeNode* root) {
        dp t = dfs(root);
        return t.second;
    }
};