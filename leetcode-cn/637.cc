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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        TreeNode * currentNode;
        long sum = 0;
        que.push(root);
        while (!que.empty()) {
            int ss = que.size();
            sum = 0;
            for (int i = 0; i < ss; i++) {
                currentNode = que.front();
                que.pop();
                sum += currentNode->val;
                if (currentNode->left != nullptr) {
                    que.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    que.push(currentNode->right);
                }
            }
            result.push_back(sum * 1.0 / ss);
        }
        return result;
    }
};