/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int left, int right)
    {
        if (left > right)
            return {nullptr};
        vector<TreeNode *> currentTrees;
        vector<TreeNode *> leftChildTrees;
        vector<TreeNode *> rightChildTrees;
        for (int i = left; i <= right; ++i)
        {
            leftChildTrees = generateTrees(left, i - 1);
            rightChildTrees = generateTrees(i + 1, right);
            for (auto &leftTree : leftChildTrees)
            {
                for (auto &rightTree : rightChildTrees)
                {
                    auto currentNode = new TreeNode();
                    currentNode->val = i;
                    currentNode->left = leftTree;
                    currentNode->right = rightTree;
                    currentTrees.emplace_back(currentNode);
                }
            }
        }
        return currentTrees;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n < 1)
            return {};
        return generateTrees(1, ne;
    }
};