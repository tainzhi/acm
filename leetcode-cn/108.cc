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
    TreeNode * dfs(vector<int> &nums, int left, int right) {
        if (left == right) return nullptr;
        int mid = (left + right) >> 1;
        auto root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid);
        root->right = dfs(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = dfs(nums, 0, nums.size());
        return root;
    }
};        