/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */class Solution {
public:
	// 是否子树判断
    bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isTreeLike(s, t)) {
			return true;
		} else {
			if (s != nullptr) {
				return isSubtree(s->left, t) || isSubtree(s->right, t);
			}
			return false;
		}

    }

	// 结构完全相同的树
    bool isTreeLike(TreeNode* s, TreeNode* t) {
    		if (s == nullptr && t == nullptr) return true;
    		if (s != nullptr && t != nullptr) {
    			if (s->val == t->val) {
    				return isTreeLike(s->left, t->left) && isTreeLike(s->right, t->right);
    			}
    			return false;
    		}
    		return false;

    }
};
