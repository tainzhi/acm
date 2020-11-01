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
    bool dfs(TreeNode *t, TreeNode *s)
    {
        if (t == nullptr && s == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
        if (t->val == s->val)
        {
            return dfs(t->left, s->right) && dfs(t->right, s->left);
        }
        return false;
    }
    // DFS
    // 两个指针, 分别从左子树, 右子树遍历
    // 如果是对称树, 那么左子树的左子树 == 右子树的右子树, 同时 左子树的右子树 == 右子树的左子树
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return dfs(root->left, root->right);
    }

    // BFS
    // 如果是对称树, 那么对称的两个 root同时入queue, 再同时出queue后, 其中一个左子树和另一个的右子树应该是对称的, 入栈
    // 那么这样, 对称的两个节点入 queue 后在相邻的位置
    // 注意: 初始root两次入 queue; 
    // 如果中间出现 nullptr == nullptr, 不需要return, continue直到 queue为空, 因为不对成在中间的步骤已经返回了false
    // 如果queue能 empty, 则返回 true
    bool isSymmetric2(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> que;
        que.push(root);
        que.push(root);
        while (!que.empty())
        {
            TreeNode *lp = que.front();
            que.pop();
            TreeNode *rp = que.front();
            que.pop();
            if (lp == nullptr && rp == nullptr)
            {
                continue;
            }
            else if (lp != nullptr && rp != nullptr)
            {
                if (lp->val == rp->val)
                {
                    que.push(lp->left);
                    que.push(rp->right);
                    que.push(lp->right);
                    que.push(rp->left);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return
    }
};
