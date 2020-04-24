/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int min_depth = INT_MAX;

    void dfs(TreeNode *root, int depth)
    {
        if (root == nullptr) {
            if (depth == 0) { min_depth = 0;}
            return;
        };
        if (root->left == nullptr && root->right == nullptr) {
            min_depth = std::min(depth + 1, min_depth);
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int minDepth(TreeNode *root)
    {
        min_depth = INT_MAX;
        dfs(root, 0);
        return min_depth;
    }
};
