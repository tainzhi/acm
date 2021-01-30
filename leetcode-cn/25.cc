/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * hair = new ListNode(0, head), *tail, * pre = hair;
        while (head != nullptr) {
            tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode *np = tail->next;
            tie(head, tail) = reverse(head, tail);
            pre->next = head;
            tail->next = np;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next, * p = head;
        while (pre != tail) {
            ListNode *np = p->next;
            p->next = pre;
            pre = p;
            p = np;
        }
        return {tail, head};
    }
};
// @lc code=end

