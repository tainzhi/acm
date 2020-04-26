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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int result = 0;
        que.push(root);
        TreeNode* p;
        while (!que.empty()) {
            int size = que.size();
            p = que.front();
            result = p->val;
            while (--size >= 0) {
                p = que.front();
                if (p->left != nullptr) {que.push(p->left);}
                if (p->right != nullptr) {que.push(p->right);}
                que.pop();
            }
        }
        return result;
    }
};