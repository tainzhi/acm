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
    TreeNode *pre;
    int preCount = 0;
    int maxCount = 0;
    void dfs(TreeNode *root, vector<int> &ret)
    {
        if (root == nullptr)
            return;
        dfs(root->left, ret);
        if (pre == nullptr)
        {
            preCount = 1;
        }
        else
        {
            if (pre->val == root->val)
            {
                preCount++;
            }
            else
            {
                preCount = 1;
            }
        }
        if (preCount > maxCount)
        {
            maxCount = preCount;
            ret.clear();
            ret.emplace_back(root->val);
        }
        else if (preCount == maxCount)
        {
            ret.emplace_back(root->val);
        }
        pre = root;
        dfs(root->right, ret);
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ret;
        pre = nullptr;
        dfs(root, ret);
        return ret;
    }
};