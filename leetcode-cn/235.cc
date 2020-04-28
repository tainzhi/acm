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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int pVal = root->val, lVal = p->val, rVal = q->val;
        while (true)
        {
            if ((lVal < pVal) && (rVal < pVal))
            {
                root = root->left;
                pVal = root->val;
            }
            else if ((lVal > pVal) && (rVal > pVal))
            {
                root = root->right;
                pVal = root->val;
            }
            else
            {
                return root;
            }
        }
    }
};