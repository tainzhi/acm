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
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inOrder(root, list);
        int i = 0, j = list.size() - 1, sum;
        while (i < j) {
            sum = list[i] + list[j];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }

    void inOrder(TreeNode* root, vector<int> & list) {
        if (root == nullptr) return;
        inOrder(root->left, list);
        list.push_back(root->val);
        inOrder(root->right, list);
    }
};