/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode * root = dfs(head, nullptr);
        return root;
    }

    TreeNode * dfs(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        ListNode * slow_p = head, *fast_p = head;
        while (fast_p != tail &&  fast_p->next != tail) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
        }
        auto root = new TreeNode(slow_p->val);
        root->left = dfs(head, slow_p);
        root->right = dfs(slow_p->next, tail);
        return root;
    }
};