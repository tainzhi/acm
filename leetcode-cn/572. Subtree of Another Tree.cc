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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        while (s != nullptr ) {
            if (dfs(s, t)) return true;
            else {
                return isSubtree(s->left , t) || isSubtree(s->right, t);
            }
        }
        return false;
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->val != t->val) return false;
        return dfs(s->left, t->left) && dfs(s->right, t->right);
    }
};