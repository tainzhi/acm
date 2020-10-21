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
    typedef pair<int, int> dp;
    int rob(TreeNode* root) {
        dp ret = dfs(root);
        return ret.second;
    }

    dp dfs(TreeNode* root) {
        if (root == nullptr) return dp(0, 0);
        // t.first 不包含此节点
        // t.second 包含此节点
        dp t(0, root->val);
        dp leftSub(0, 0), rightSub(0, 0);
        if (root->left != nullptr) {
            leftSub = dfs(root->left);
        }
        if (root->right != nullptr) {
            rightSub = dfs(root->right);
        }
        // 不取父节点, 但是子树的节点要取
        t.first += leftSub.second + rightSub.second;
        // 取父节点, 但是不取子节点 
        t.second += leftSub.first + rightSub.first;
        // 优化: 如果取了父节点还没有不取父节点的值更大, 那么以不取父节点的值为准
        t.second = std::max(t.first, t.second);
        return t;
    }
};